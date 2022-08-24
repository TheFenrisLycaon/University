# Deadlock

Deadlock in a condition in computing where two or more entities are unable to move forward in transactioning as each member awaits a for a response from another member, including itself. The transaction of providing the response so that the whole system can move forward is called releasing the lock. Deadlock is a very common problem in various fields of computing like Operating systems, Networking and Database Management.

In database management, Deadlock usually occurs when two or more transactions are waiting for each other to complete their operations.

## Deadlock Conditions

- Mutual Exclusion :: When at least on resource is set as non-sharable, i.e., only one transaction can use it at any given time. This is a necessary condition as if there are no such resources, any transaction can use any resource at any given time.

- Hold & Wait (Resource Conflict) :: When a resource is currently holding one resource and is asking for another resource which are being held by other transactions to complete the given task.

- No preemption :: When a resource can be released voulantarily by the transaction holding it.

- Circular Wait :: When a given transaction is waiting for a resource which in turn is waiting for the first transaction to be completed.

## Deadlock Handling

### Ignoring

When we assume that there will be no deadlock condition and it has been proen formally, we may use deadlock ignoring.

Systems like UNIX and MINIX used to use Deadlock ignoring when the time interval between deadlocks was high and the dataloss was bearable.

### Detection

In this method, the state of the system is examined to detect that a deadlock has occurred and subsequently it is corrected. We use algorithms to track resource allocation and process states and roll back and restart one or more of the processes in order to remove the detected deadlock.

Detecting a deadlock that has already occurred is easy as the resources that each process has locked and/or currently requested are known.

When a deadlock is detected, we use one of the following methods to resolve it :

- Process Termination :: Where we abort one or more processes to resolve the deadlock. We can also abort all the processes at once for certainity and speed at the cost of partial computations. Or we can abort one process at a time to keep these computations at a cost of speed as we have to check for a deadlock after each termination.

- Resource preemption :: Here, we assign resources to other processes until the deadlock is broken after preempting them.

### Prevention

- We can remove the mutual exclusion condition such that no particular process has an exclusive access to a given resource. These algorithms are called non-blovking synchronization algorithms.

- The hold & wait condition can be resolved by asking processes to list up all the resources they require before starting up. This might lead to resource starvation though as a given resource can be assigned and held unused for a long period of time. These algorithms are called all-or-none algorithms.

- The no preemption condition is difficult to resolve as a process has to be able have a resource for a certain amount of time, or the processing outcome maybe inconsistent or thrashing may occur. We can use priority algorithms but preemption usually requires a rollback which again has to be avoided as it is costly. Algorithms that allow preemption include lock-free and wait-free algorithms and optimistic concurrency control. If a process holding some resources and requests for some another resource(s) that cannot be immediately allocated to it, the condition may be removed by releasing all the currently being held resources of that process.

- The circular wait condition can be solved by disabling interrupts during critical sections and using a hierarchy to determine a partial ordering of resources. If no obvious hierarchy exists, even the memory address of resources has been used to determine ordering and resources are requested in the increasing order of the enumeration. Dijkstra's solution can also be useful.

### Avoidance

Deadlock avoidance is similar to deadlock prevention as it also tries that a deadlock doesn't occur. They are however, quite different in the way they handle deadlocks. Deadlock avoidance does not impose any conditions as seen in prevention but, here each resource request is carefully analyzed to see whether it could be safely fulfilled without causing deadlock.

It requires that the system has all the information in advance concerning the request and usage of the resources by the upcoming processes. A common algorithm used is the Banker's algorithm.
