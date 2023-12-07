import math
c,h=50,30
daura = []
dauvao = (x for x in input().split(','))
for d in dauvao :
    daura.append(str(round(math.sqrt((2*c*int(d))/h))))
print(daura)