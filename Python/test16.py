c = {}
n = input().split(' ')
for i in n:
    c[i] = c.get(i,0)+1
for i in c:
    print(f'{i}:{c[i]}')