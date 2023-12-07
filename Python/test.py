n = list((x for x in input().split(',')))
for i in range(len(n)):
    for j in range(len(n[i])):
        print(n[i][j],end='')
