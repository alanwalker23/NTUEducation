nameList=["A","B","C"]
cwList=[59,71,45]
examList=[80,39,61]
finalList=[]
atotal=0
counter=-1
print("{:4s} \t {:10s} \t {:4s} \t {:5s}".format("Name","Coursework","Exam","Final"))
for i in range(len(nameList)):
    average=cwList[i]*0.3+examList[i]*0.7
    finalList.append(average)
    atotal+=average
    print("{:4s} \t {:2d} \t {:18d} \t {:.2f}".format(nameList[i],cwList[i],examList[i],finalList[i]))
print("Average final marks: {:.2f}".format(atotal/len(nameList)))
print("Those who failed:")
for j in finalList:
    counter+=1
    if j<50:
        print(nameList[counter])
top=max(finalList)
counter=-1
print("Highest scorer(s):")
for a in finalList:
    counter+=1
    if a==top:
        print(nameList[counter])
        
