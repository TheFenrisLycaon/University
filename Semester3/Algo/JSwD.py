class Job:

    def __init__(self,id,profit,deadline):
        self.id = id
        self.profit = profit 
        self.deadline = deadline
        self.details = [self.id, self.profit, self.deadline]
    
    def printJob(self):
        print(self.details, sep='|\t')
    
if __name__ == "__main__":
    k = int(input('Enter number of jobs::\t'))
    jobs = []
    for i in range(k):
        x = Job(input("Enter Job ID::\t"),int(input("Enter profit::\t")),int(input("Enter deadline::\t")))
        jobs.append(x)

    # for i in jobs:
    #     i.printJob()
    
    jobs = sorted(jobs, key= lambda x: x.profit, reverse=True)

    for i in jobs:
        i.printJob()

    j = max(jobs, key=lambda x : x.deadline).deadline

    slots = [False]*j
    print(slots)

    


    
    
    


    
