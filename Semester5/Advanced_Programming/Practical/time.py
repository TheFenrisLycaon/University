#! /home/fenris/Apps/anaconda3/bin/python

array = [x for x in range(1,1001)]

l = 10
r = 579
res = 0
for i in range(l,r+1):
    res += array[i]

print(res)