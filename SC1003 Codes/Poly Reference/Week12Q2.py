marks=[]
total=0
count=0
counter=0
while count>=0:
    mark=int(input("Enter mark:"))
    if mark==-1:
        break
    total+=mark
    count+=1
    marks.append(mark)
average=total/count
print("Average={:.2f}".format(average))
for i in marks:
    if i>average:
        counter+=1
print("{:d} marks are above the average\nGraph:".format(counter))
for i in marks:
    if i>average:
        print(i*"#")
    else:
        print(i*"$")
        
