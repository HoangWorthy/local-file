lst = str(input())
lst = lst.lower()
if len(lst) % 2 == 0 :    
    for i in range(0,len(lst)) :
        if lst[i] != lst[-(i+1)] :
            print(f'{lst} không phải là palindrome')
            exit()
    print('Chuỗi {} là palindrome'.format(lst))
elif len(lst) % 2 != 0 : 
    for i in range(0,len(lst)):
        if i == int((len(lst)/2)) : continue
        if lst[i] != lst[-(i+1)] :
            print(f'{lst} không phải là palindrome')
            exit()
    print('Chuỗi {} là palindrome'.format(lst))