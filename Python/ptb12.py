import math
with open('input.txt','r') as f:
    hangso = f.readline().split()
    a = float(hangso[0])
    b = float(hangso[1])
    c = float(hangso[2])
    delta=float(b**2-4*a*c)
    if delta > 0:
        x1 = float((-b + math.sqrt(delta)) / (2 * a))
        x2 = float((-b - math.sqrt(delta)) / (2 * a))
        print("Phương trình có 2 nghiệm phân biệt là: \nx1 =",x1,"\nx2 =",x2,"")
    elif delta == 0:
        x = -b / (2 * a)
        print("Phương trình có nghiệm kép: \nx1 = x2 =",x,"")
    else:
        print("Phương trình vô nghiệm")
    f.close()