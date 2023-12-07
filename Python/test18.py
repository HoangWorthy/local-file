c = []
while True:
    s = input()
    if not s:
       break
    c.append(tuple(s.split(',')))
d = lambda c:(c[0],c[1],c[2])
sorted_c = sorted(c,key=d)
print(sorted_c)