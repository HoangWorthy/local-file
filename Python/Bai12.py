n = input()
a = 0
b = 0
c = 0
for i in range(len(n)):
    if n[i].isnumeric(): a+=1
    elif n[i].isupper(): b+=1
    elif n[i].islower(): c+=1
print("Số chữ cái in hoa:",b)
print("Số chữ cái in thường",c)
print("Số chữ số",a)