limit =int(input("Enter the limit:"))
print("List of prime numbers up to",limit,"are:")
for i in range(limit+1):
    if i>1:
        for j in range(2,i):
            if (i%j)==0:
                break
        else:
            print(i)
            
        
