def dequy(n):
    if n ==0 :
        return 0
    return dequy(n-1) + 100
n = int(input())
print(dequy(n))