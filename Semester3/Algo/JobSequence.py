def JobSchedule(x, t):
    n = len(x)
    for i in range(n):
        for j in range(n - 1 - i):
            if x[j][2] < x[j + 1][2]:
                x[j], x[j + 1] = x[j + 1], x[j]
    result = [False] * t
    job = ["-1"] * t
    for i in range(len(x)):
        for j in range(min(t - 1, x[i][1] - 1), -1, -1):
            if result[j] is False:
                result[j] = True
                job[j] = x[i][0]
                break
    print(job)


x = [["a", 2, 100], ["b", 1, 19], ["c", 2, 27], ["d", 1, 25], ["e", 3, 15]]


print("Following is maximum profit sequence of jobs")
JobSchedule(x, 3)
