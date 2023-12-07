import math
pos = [0,0]
while True:
    n = input()
    if not n :
        break
    c = n.split(" ")
    dirct = c[0]
    step = int(c[1])
    if dirct =='UP':
        pos[1] += step
    elif dirct =='DOWN':
        pos[1] -= step
    elif dirct == 'LEFT':
        pos[0] -= step
    elif dirct == 'RIGHT':
        pos[0] += step
print(int(round(math.sqrt(pos[0]**2+pos[1]**2))))