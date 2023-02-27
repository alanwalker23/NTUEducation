fileName = input("Enter file name: ")
infile = open(fileName, "r")
wordcount = 1
for line in infile:
    print(line,end=" ")
    for i in range(len(line)):
        if line [i]==" " or line[i] =="\n":
            wordcount +=1
print("Number of words:", wordcount)
infile.close()


    
