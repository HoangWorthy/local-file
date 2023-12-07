n = [1,2,3,4,5,6,7,8,9,10]
d = list(filter(lambda a:a%2 == 0 , n))
print(d)
n = list(map(lambda x:x**2,d))
print(n)