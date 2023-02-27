'''
import random
count = 0
for i in range (0,10,2): #Range ending does not include itself (0-9, ends before 10)
    print(random.randint(0,10),end=" ") #Sep not needed since nothing else is printed between each iteration
    count = count + 1
print("\nNum of variables generated:",count)
'''

#Generate Diagram
def Diagram(allelements):
    largestDisc = max(allelements)
    diagram = []
    count = 0
    while count!=len(allelements):
        layer = []
        for i in range(3):
            layer.append(allelements[count])
            count+=1
        diagram.append(layer)

    for i in range(len(diagram)):
        print("Row {}".format(i+1),end="\t")
        for j in range(3):
            currentDisc = diagram[i][j]
            if currentDisc == 0:
                print(" "*largestDisc,end="\t")
            elif currentDisc == largestDisc:
                print("x"*largestDisc,end="\t")
            else:
                space = int((largestDisc-currentDisc)/2)
                print(" "*space+"x"*currentDisc+" "*space,end="\t")
        print()

#Stick Generation
list1 = [0,0,1,3]
list2 = [0,0,0,5]
list3 = [0,0,0,9]
listList = [list1,list2,list3]
listSize = len(list1)

allelements = []
for i in range(listSize):
    allelements.append(listList[0][i])
    allelements.append(listList[1][i])
    allelements.append(listList[2][i])
#Diagram(allelements)

'''
#Sorting Algorithm
Prevent 2nd element in list to be higher than previous element 
[1-->3 okay but 3-->1 not okay]
Always push to furthest end
'''












'''
def discDiag(list):
    discSize = [1,3,5,7,9] #Max 5 discs
    discMax = discSize[max(list)-1]
    for element in list:
        disc = discSize[element-1]
        space = (discMax - disc)/2
        printDisc = ""
        printDisc = printDisc+" "*int(space)
        for i in range(disc):
            printDisc = printDisc+"x"
        printDisc = printDisc+" "*int(space)
        print("{:<20}".format(printDisc))

discDiag(list1)
'''