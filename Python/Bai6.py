n = input()
s = ""
for i in n:
    if i not in s:
        s+=i
for i in s:
    print(f"{i} lặp {n.count(i)} lần")
