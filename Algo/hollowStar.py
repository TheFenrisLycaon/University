k = int(input())

for i in range(1, k+1):
    print('*'*(i != k) + '* '*(i == k) + str(' '*2*(i-1)*(i != k)) +
          str('* '*(k-2)*(i == k)) + str('*'*(i != 1)))
