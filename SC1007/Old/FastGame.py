import random
from typing import Type

def getExpression(level,operator):
    if (level==1):
        num1 = random.randrange(1,10)
        num2 = random.randrange(1,10)
    elif (level==2):
        num1 = random.randrange(10,100)
        num2 = random.randrange(10,100)
    else:
        num1 = random.randrange(100,1000)
        num2 = random.randrange(100,1000)
    #print(type(num1),type(num2))
    if (operator=='+'):
        return str(num1)+" + "+str(num2),int(num1+num2)
    if (operator=='-'):
        while (num2>=num1):
            num2 = int(num2-1) 
        return str(num1)+" - "+str(num2),int(num1-num2)
    if (operator=='*'):
        num2 = random.randrange(2,10)
        return str(num1)+" * "+str(num2),int(num1*num2)

# for i in range(50):
#     number = random.randrange(1,10)
#     #print(number)

#Addition - 1-9;10-99;100-999
#Subtraction - left always > right 
#Multiplication - 2-9;10-99;100-999 2nd operand ALWAYS 2-9

level = 0
while not int(level) in range(1,6):
    level = int(input("Enter highest level to achieve (1-5): "))
    if int(level) not in range(1,6):
        print("Highest level must be between 1 and 5.")
for i in range(0,level,1):
        wrong = 0
        repeat = 1
        while (repeat == 1):
            print("Level",i+1)
            for j in range(3):
                operatorchoice = random.randrange(1,4)
                if (operatorchoice==1):
                    operator = '+'
                elif (operatorchoice==2):
                    operator = '-'
                else:
                    operator = '*'
                #print("Operator generated is",operator)
                expression,answer = getExpression(i+1,operator)
                print("Q%d. %s = " %(j+1,expression),end="")
                attempt = int(input())
                if (attempt!=answer):
                    print("Wrong! Answer is %d" %(answer))
                    wrong = wrong+1
                else:
                    print("Correct!")
                #print("Answer is %d" %(answer))
            if(wrong==0):
                if(level>i+1):
                    input("Well done! Press <Enter> to proceed to level %d. <Enter>" %(i+2))
                else:
                    print("Well done! You have completed the highest level %d!" %(i+1))
                repeat = repeat - 1
            else:
                input("You have %d errors. Press <Enter> to repeat this level. <Enter>" %(wrong))
                wrong = 0

