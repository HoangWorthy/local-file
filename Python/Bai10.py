n = input().split()
max = 0
for i in range(len(n)):
    if max < len(n[i]): max = len(n[i])
for i in n:
    if max == len(i): print(i,end=" ")