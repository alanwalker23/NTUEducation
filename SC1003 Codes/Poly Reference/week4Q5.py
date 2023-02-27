import random
while True:
    a = random.randrange (0,101)
    b = random.randrange (0,101)
    c= int(input("Enter the sum of {0} and {1}:".format(a,b)))
    if c != a + b:
        print("Your answer is wrong! \nThe correct answer is {}\n.".format(a+b))
    else:
        print("Your answer is correct!\n")
    
