from os import waitpid


so = 0
chu = 0
with open('input.txt','r') as f:
    doc = f.read()  
    for i in range(len(doc)):
        if doc[i].isdigit :
            so += 1
        elif doc[i].isalpha() :
            chu += 1
    f.close()
with open('output.txt','w',encoding=('utf-8')) as f:
    f.write(f'Số chữ cái là: {chu}\nSố chữ số là : {so}')
    f.close()