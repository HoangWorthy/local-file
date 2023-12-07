chuhoa = 0
chuthuong = 0
with open('input.txt','r') as f :
    doc = f.read()
    for s in doc :
        if s.isupper() :
            chuhoa += 1
        if s.islower() :
            chuthuong += 1
    f.close()
with open('output.txt','w',encoding=('utf-8')) as f :
    f.write(f'{chuhoa} chữ hoa \n{chuthuong} chữ thường')
    f.close()