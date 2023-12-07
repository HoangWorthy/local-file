with open('input.txt','r') as f:
    a = f.readline()
    b = f.readline()
    f.close()
with open('output.txt','w') as f:
    c = a + b
    f.write(c)
    f.close()