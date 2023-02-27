mylist=[0,0,0,0,0]
secondlist=["a","e","i","o","u"]
sentence=input("Enter a sentence:").lower()
for i in range(int(len(sentence))):
    for j in range(int(len(secondlist))):
        if secondlist[j]==sentence[i]:
            mylist[j]+=1
print("A:",mylist[0],"\nE:",mylist[1],"\nI:",mylist[2],"\nO:",mylist[3],"\nU:",mylist[4])
            

               
