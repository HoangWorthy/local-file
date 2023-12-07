import random as ra
n = str(ra.randint(1000,9999))
print(n)
cows = 0
bulls = 0
try :
    c = str(int(input()))
    for i in range(0,4):
        if c[i] != n[i] : bulls += 1
        if c[i] == n[i] : cows += 1
    print(f'{cows} cows, {bulls} bulls')
except:
    print('Bạn đã nhập sai')