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
print("Average={:.2f}".format(total/count))
for i in marks:
    if i>(total/count):
        counter+=1
print("{:d} marks are above the average".format(counter))
