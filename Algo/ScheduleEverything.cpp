#include<boost/thread.hpp>
#include<stdio.h>
#include<iostream>

class Task;
class TaskScheduler;
class WorkerThread;

//// HEADERS ////

/// Abstract interface for all tasks run by scheduler
class Task
{
public:
    virtual ~Task() {}

    /** Checks if all dependencies are met and the task can run
	 *  @returns true if scheduler can run task, false otherwise
	 */
    virtual BOOL isReady() = 0;

    /// User task code goes here
    virtual void run() = 0;

    /// Checks whether the task is marked complete
    BOOL complete() { return m_complete; }

    /** Sets the complete status of the task
	 *  @param v Completetion status
	 */
    void setComplete(BOOL v) { m_complete = v; }

private:
    /// Flag indicating task completion
    BOOL m_complete;
};

/// Runs Tasks across multiple threads on multiple cores
class TaskScheduler
{
public:
    /** Create scheduler with default number of worker threads.
	 *  Default is 1 thread per 1 logical core (core or HT unit)
	 */
    TaskScheduler();

    /** Create scheduler with specified number of worker threads
	 *  @param n Number of worker threads (must be less than MAX_THREADS)
	 */
    TaskScheduler(U32 n);

    /// Finishes all currently running tasks, then stops all worker threads.
    ~TaskScheduler();

    /** Schedules a task for execection
	 *  The task is assigned to the first idle work thread if there is one;
	 *  otherwise, the task is put on the queue of a worker thread. Pushed tasks
	 *  execute immediately.
	 */
    void pushTask(Task *t);

    /// Blocks execution until all worker threads have completed there tasks
    void runUntilDone();

    /** Gets number of worker threads
	 *  @return Number of worker threads
	 */
    U32 threadCount();

private:
    U32 m_workerCount;
    WorkerThread *m_workers[MAX_THREADS];
    BOOL m_running;
    U32 m_nextPushIndex;

    friend class WorkerThread;
};

/** Implementation of a task-stealing worker thread for the TaskScheduler
 *  WorkerThreads steal tasks from other WorkerThreads if they are out of tasks or
 *  blocked by task dependencies. If a WorkerThread is truly out of tasks, it sleeps on a
 *  condition variable until new tasks are available.
 */
class WorkerThread
{
public:
    /** Creates a new worker thread--only called by a TaskScheduler
	 *  The system thread is started and enters idle, waiting on a condition variable.
	 *  @param scheduler Parent TaskScheduler
	 */
    WorkerThread(TaskScheduler *scheduler);

    /// Deletes underlying system thread
    ~WorkerThread();

    /** Adds a task to the local task pool
	 *  This method is called by the TaskScheduler from the main thread and uses
	 *  a spinlock to access task queue. Execution of the task can begin immediately after
	 *  the lock mutex is released.
	 *  @param t Task to add to queue
	 */
    void pushTask(Task *t);

    /** Checks whether the worker thread is currently idling
	 *  @return true if idling, false otherwise
	 */
    BOOL idling();

    /** Blocks execution until the worker thread has completed all tasks in its queue
	 *  and can no longer find tasks to steal
	 */
    void blockUntilDone();

    /** Wakes the thread and joins execution
	 *  TaskScheduler must have m_running = false or method will block indefinitely
	 */
    void stop();

private:
    void thread_proc();
    BOOL run();
    void idle();
    BOOL steal();
    BOOL stealFromWorker(WorkerThread *wt);

    TaskScheduler *m_scheduler;
    boost::thread *m_internalThread;
    boost::mutex m_workerMutex;
    boost::mutex m_idleMutex;
    boost::condition_variable m_wakeUp;
    boost::condition_variable m_done;
    std::queue<Task *> m_tasks;
    U32 m_taskCount;
    BOOL m_idling;
    BOOL m_dependencyBlocked;
};

//// HEADERS ////

//// IMPLEMENTATIONS ////

/// TASK SCHEDULER ///
TaskScheduler::TaskScheduler()
{
    m_running = true;

    // use number of 'logical cores' as default number of worker threads
    // on CPUs with Hyperthreading, each core counts as 2
    m_workerCount = boost::thread::hardware_concurrency();

    for (U32 i = 0; i < m_workerCount; i++)
        m_workers[i] = new WorkerThread(this);
    m_nextPushIndex = 0;
}

TaskScheduler::TaskScheduler(U32 n)
{
    m_workerCount = n;
    for (U32 i = 0; i < m_workerCount; i++)
        m_workers[i] = new WorkerThread(this);
    m_nextPushIndex = 0;
}

TaskScheduler::~TaskScheduler()
{
    m_running = false;
    for (U32 i = 0; i < m_workerCount; i++)
        m_workers[i]->stop();
}

void TaskScheduler::pushTask(Task *t)
{
    // try to find an idling worker thread
    for (U32 i = 0; i < m_workerCount; i++)
    {
        if (m_workers[i]->idling())
        {
            m_workers[i]->pushTask(t);
            return;
        }
    }

    // push it onto the next worker thread round-robin style
    // if there isn't an idling thread
    m_workers[m_nextPushIndex++]->pushTask(t);
    if (m_nextPushIndex >= m_workerCount)
        m_nextPushIndex = 0;
}

void TaskScheduler::runUntilDone()
{
    for (U32 i = 0; i < m_workerCount; i++)
        m_workers[i]->blockUntilDone();
}

U32 TaskScheduler::threadCount()
{
    return m_workerCount;
}
/// TASK SCHEDULER ///

/// WORKER THREAD ///
WorkerThread::WorkerThread(TaskScheduler *scheduler)
{
    m_scheduler = scheduler;
    m_taskCount = 0;
    m_idling = false;
    m_dependencyBlocked = false;

    // creates system thread
    // thread_proc begins execution immediately
    m_internalThread = new boost::thread(&WorkerThread::thread_proc, this);
}

WorkerThread::~WorkerThread()
{
    delete m_internalThread;
}

void WorkerThread::pushTask(Task *t)
{
    m_workerMutex.lock();
    m_tasks.push(t);
    m_taskCount++;
    m_workerMutex.unlock();

    m_idleMutex.lock();
    m_idling = false;
    m_idleMutex.unlock();

    // wake up the thread if idling
    m_wakeUp.notify_all();
}

BOOL WorkerThread::idling()
{
    boost::lock_guard<boost::mutex> lock(m_idleMutex);
    return m_idling;
}

void WorkerThread::blockUntilDone()
{
    // the m_done condition variable is notified when the thread enters idle,
    // which only happens when it is out of tasks and can't find any to steal
    boost::unique_lock<boost::mutex> lock(m_idleMutex);
    while (!m_idling)
        m_done.wait(lock);
}

void WorkerThread::thread_proc()
{
    // always idle when thread first starts because
    // not all other worker threads are gauranteed to
    // be initialized yet, and steal() relies on that.
    // Also, there shouldn't be any tasks yet anyway.
    idle();

    for (;;)
    {
        if (!m_scheduler->m_running)
            break;

        // try to run a task. If there are not tasks available,
        // try to steal tasks.  If there are no tasks to steal
        // and the task queue is empty, then idle. If there are
        // dependency-blocked tasks, the thread does not idle.
        if (!run())
        {
            if (!steal() && m_taskCount <= 0)
                idle();
        }
    }
}

BOOL WorkerThread::run()
{
    if (m_taskCount <= 0)
        return false;

    // Try to find a task to run. If all tasks in the queue
    // have been checked, then return false so we can try to steal.
    // If we have tasks waiting on dependencies, set m_dependencyBlocked
    // so other WorkerThreads know not to steal from this one.
    m_workerMutex.lock();
    m_dependencyBlocked = false;
    U32 numPops = 0;
    Task *t;
    while (numPops < m_taskCount)
    {
        t = m_tasks.front();
        m_tasks.pop();
        if (t->isReady())
        {
            m_taskCount--;
            m_workerMutex.unlock();
            t->run();
            return true;
        }
        numPops++;
        m_tasks.push(t);
    }
    if (numPops > 0)
        m_dependencyBlocked = true;
    m_workerMutex.unlock();
    return false;
}

void WorkerThread::idle()
{
    m_idleMutex.lock();
    if (m_taskCount > 0)
    {
        m_idleMutex.unlock();
        return;
    }
    m_idling = true;
    m_idleMutex.unlock();

    // If another thread is waiting on us to finish execution,
    // notify that this thread is done now
    // Used by blockUntilDone()
    m_done.notify_all();

    boost::unique_lock<boost::mutex> lock(m_idleMutex);
    while (m_idling)
        m_wakeUp.wait(lock);
}

BOOL WorkerThread::steal()
{
    // check each worker thread for extra work
    U32 workerCount = m_scheduler->m_workerCount;
    for (U32 i = 0; i < workerCount; i++)
    {
        WorkerThread *wt = m_scheduler->m_workers[i];
        if (wt == this)
            continue;

        if (stealFromWorker(wt))
            return true;
    }

    return false;
}

BOOL WorkerThread::stealFromWorker(WorkerThread *wt)
{
    wt->m_workerMutex.lock();

    // steal half of the other thread's tasks,
    // rounding up. If they don't have tasks
    // (the check in steal() is not guaranteed because,
    // it does not lock the mutex), then return false so
    // we can try another worker thread.
    U32 numToSteal;
    U32 taskCount = wt->m_taskCount;
    if (wt->m_taskCount <= 0 || wt->m_dependencyBlocked)
    {
        wt->m_workerMutex.unlock();
        return false;
    }
    else
        numToSteal = (wt->m_taskCount + 1) / 2;

    m_workerMutex.lock();
    for (U32 i = 0; i < numToSteal; i++)
    {
        m_tasks.push(wt->m_tasks.front());
        wt->m_tasks.pop();
        wt->m_taskCount--;
        m_taskCount++;
    }
    wt->m_workerMutex.unlock();
    m_workerMutex.unlock();
    return true;
}

void WorkerThread::stop()
{
    m_idleMutex.lock();
    m_idling = false;
    m_idleMutex.unlock();
    m_wakeUp.notify_all();
    m_internalThread->join();
}

/// WORKER THREAD ///

int main()
{
    TaskScheduler scheduler;
    MyTaskA taskA;
    MyTaskB taskB;

    BOOL running = true while (running)
    {
        scheduler.pushTask(&taskA);
        scheduler.pushTask(&taskB);
        scheduler.runUntilDone();
    }
}

//// IMPLEMENTATIONS ////