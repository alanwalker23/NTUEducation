mylist=[]
A=0
E=0
I=0
O=0
U=0
sentence=input("Enter a sentence:")
for i in range(int(len(sentence))):
    mylist.append(sentence[i])
for j in mylist:
    if j.lower()=="a":
        A+=1
    elif j.lower()=="e":
        E+=1
    elif j.lower()=="i":
        I+=1
    elif j.lower()=="o":
        O+=1
    elif j.lower()=="u":
        U+=1
print("A:",A,"\nE:",E,"\nI:",I,"\nO:",O,"\nU:",U)
               
