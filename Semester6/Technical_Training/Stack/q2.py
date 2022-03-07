n, k = map(int, input().split())
a = list(map(int, input().split()))

if n == 1:
    if k % 2 == 1:
        print(-1)
    else:
        print(a[0])

elif k >= n:
    print(max(a))

else:
    print(max(a[k], a[k - 2]))
