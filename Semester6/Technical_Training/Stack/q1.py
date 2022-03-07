nums = list(map(int, input().split()))
mod = int(1e9 + 7)
stack = []
summ = 0
res = 0
nums.append(0)
for i, v in enumerate(nums):
    while stack and nums[stack[-1][0]] >= v:
        index, _ = stack.pop()
        arsumm = summ
        if stack:
            arsumm = summ - stack[-1][1]
        res = max(res, nums[index] * arsumm)
    summ += v
    stack.append((i, summ))
print( res % mod)
