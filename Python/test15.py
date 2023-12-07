import sys
n = (x for x in input().split(','))
c = list(map(int,n))
set = list()
for i in c:
    if i*-1 > 0 : 
        set.append(i)
for i in set :
    c.remove(i)
for i in range(len(set)-1):
    sum = 0
    sum = set[i] + set[i+1]
    for j in range(len(c)-1):
        sum1 = c[j] + c[j+1]
        if abs(sum) == c[j] : 
            print(set[i],set[i+1],c[j])
            sys.exit()
        elif sum1 == abs(set[i]):
            print(c[j],c[j+1],set[i])
            sys.exit()
print('Không có số phù hợp')