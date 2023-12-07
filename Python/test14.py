n = input()
b = True
for i in range(len(n)):
    dem = 0
    for j in range(len(n)):
        if n[i] == n[j] : dem = dem+1
    if dem == 2 : b = False
if b : print('Chuỗi không trùng nhau')
else: print('Chuỗi trùng nhau')