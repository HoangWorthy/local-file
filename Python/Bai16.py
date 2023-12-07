m = int(input())
n = int(input())
while (m!=n):
    if m > n: m-=n
    elif n > m: n-=m
print(f'Uoc chung lon nhat cua hai so la: {n}')