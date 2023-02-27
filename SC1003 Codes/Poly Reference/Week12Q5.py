import random
print("Numbers generated:")
list1=[]
list2=[]
for i in range(10):
    a=random.randint(0,11)
    print(a)
    list1.append(a)
list1.sort()
for i in list1:
    if (i in list2)==False:
        list2.append(i)
print("List in ascending order:\n",list2)
    
    
