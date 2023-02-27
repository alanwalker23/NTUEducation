a=input("Input your sentence (Leave a spacing behind the last word):")
a1=a.find(" ")
print(a[:a1])
b1=0
while b1>=0:
    b1=a.find(" ",a1+1)
    print(a[a1+1:b1])
    a1=b1
    
    
