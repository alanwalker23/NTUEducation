import random
test=int(input("\
1: Addition\n\
2:Subtraction\n\
3:Multiplication\n\
4:Division\n\
5:Exponential \n\
Pick an option number:"))
a = random.randrange (0,101)
b = random.randrange (0,101)
c = random.randrange (0,5)
if test == 1:
    answer = a+b
    reply =int(input("What is {0} + {1}?".format(a,b)))
elif test == 2:
    answer = a-b
    reply =int(input("What is {0} - {1}?".format(a,b)))
elif test == 3:
    answer = a*b
    reply =int(input("What is {0} X {1}?".format(a,b)))
elif test == 4:
    answer = a/c
    reply =int(input("What is {0} / {1}?".format(a,c)))
elif test == 5:
    answer = a**c
    reply =int(input("What is {0} to the power of {1}?".format(a,c)))
else:
    print("Please select an option.")
if answer == reply:
    print("Congratulations, you got it right!")
else:
    print("Wrong! The answer is",answer)


    
