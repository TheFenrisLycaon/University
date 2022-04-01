from dataclasses import dataclass


@dataclass
class Job:
    id = int
    profit: int
    deadline = int


if __name__ == "__main__":
    k = int(input("Enter number of jobs::\t"))
    jobs = []
    for i in range(k):
        x = Job(
            input("Enter Job ID::\t"),
            int(input("Enter profit::\t")),
            int(input("Enter deadline::\t")),
        )
        jobs.append(x)

    jobs = sorted(jobs, key=lambda x: x.profit, reverse=True)

    for i in jobs:
        i.printJob()

    j = max(jobs, key=lambda x: x.deadline).deadline

    slots = [False] * j
    print(slots)
