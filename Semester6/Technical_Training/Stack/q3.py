def solution(n, digits):
    curr = digits[-1]
    arr = {i: 0 for i in range(0, 10)}
    n -= 1
    while n > -1:
        arr[digits[n]] += 1
        if digits[n] < curr:
            break
        else:
            curr = curr if curr > digits[n] else digits[n]
        n -= 1
    if n == -1:
        return n
    answer = "".join(map(str, digits[:n]))
    for i in range(digits[n] + 1, 10):
        if arr[i]:
            arr[i] -= 1
            answer += str(i)
            break
    for i in range(0, 10):
        answer += str(i) * arr[i]
    return int(answer)


for _ in range(int(input())):
    print(solution(int(input()), list(map(int, input().split()))))
