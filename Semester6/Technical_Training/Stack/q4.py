def answer(size, case):
    need = 1
    status = True
    lane = []
    for e in case:
        while bool(len(lane)) and lane[-1] == need:
            need += 1
            lane.pop()
        if e == need:
            need += 1
        elif bool(len(lane)) and e > lane[-1]:
            status = False
            return status
        else:
            lane.append(e)
    return "Yes" if status else "No"


for _ in range(int(input())):
    print(answer(int(input()), list(map(int, (input().split())))))
