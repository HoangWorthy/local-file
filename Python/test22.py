n = int(input())
c = 0.0
for i in range(1,n+1):
    c +=float(float(i)/(i+1))
print(f'{c:g}')