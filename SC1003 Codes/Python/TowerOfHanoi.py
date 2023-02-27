#Use recursion to solve a tower of hanoi puzzle
#3 Sticks, x number of discs
def stickDiag(stick1,stick2,stick3):
    pass

#Printing a single stick
#A list of discDiag will be parsed into stick1
def discDiag(list):
    discSize = [1,3,5,7,9] #Max 5 discs
    discMax = discSize[max(list)-1]
    for i in list:
        integer = i
        disc = discSize[integer-1]
        space = (discMax - disc)/2
        printDisc = ""
        printDisc = printDisc+" "*int(space)
        for i in range(disc):
            printDisc = printDisc+"x"
        printDisc = printDisc+" "*int(space)
        print("{:<20}".format(printDisc))

def CompareDisc(disc1,disc2):
    pass 

startingDisc = [1,2,3,4]
discDiag(startingDisc)

startingDisc = [startingDisc,[],[]]
print(startingDisc)