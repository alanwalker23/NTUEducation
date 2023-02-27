import random
user=int(input("How many numbers do you want to generate?"))
total=[]
total1=0
counter=0
counter1=0
counter2=0
for i in range(user):
    a=random.randint(0,101)
    print(a)
    total1+=a
    total.append(a)
average=total1/user
for i in total:
    if i>average:
        counter+=1
    if i%2==0:
        counter1+=1
    if i<50:
        counter2+=1
print("Generate",user,"random numbers in the range of 0 to 100")
print("Average={:.2f}".format(average))
print(counter,"numbers above the average")
print(counter1,"numbers are even numbers")
print(counter2,"numbers in the range of 0 to 49")
