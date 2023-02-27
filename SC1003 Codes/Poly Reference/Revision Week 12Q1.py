blist=[]
total=0
binary=str(input("Enter a binary:"))
a=int(len(binary))
for i in range(a):
    blist.append(int(binary[i]))
for j in blist:
    a-=1
    c=j*(2**a)
    total+=c
print(total)
