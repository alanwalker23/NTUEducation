#import of random
import random

#For clicking function
import tkinter
root = tkinter.Tk()
def leftClick(event):
    print("Left")
def rightClick(event):
    print("Right")
frame = tkinter.Frame(root,width=300,height=250)
frame.bind("<Button-1>",leftClick)
frame.bind("<Button-3>",rightClick)
frame.pack()
root.mainloop()    



#shape of grid is 10x8
grid = []
for i in range(8):
    newrole = []
    for i in range(10):
        newrole.append("O")
    grid.append(newrole)

for rows in grid:
    #print(rows)
    pass

#define bomb locations
#Total of 10 bombs to be instantiate
bombs = []
bombpositions = []
while len(bombs)!=10:
    newbomb = random.randint(0,80)
    if newbomb in bombs:
        continue
    else:
        bombs.append(newbomb)
bombs.sort()
print(bombs)
for i in bombs:
    RHS = i%10
    LHS = int((i-RHS)/10)
    position = [LHS,RHS]
    bombpositions.append(position)
bombpositions.sort()
print(bombpositions)

#Implant bombs onto grid
for i in bombpositions:
    LHS=i[0]
    RHS=i[1]
    for rows in range(len(grid)):
        if rows==LHS:
            grid[rows][RHS]="X"

for rows in grid:
    print(rows)
    pass
