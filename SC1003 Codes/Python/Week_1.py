'''
Discussion Q5
Boys = int(input("Enter the number of boys:"))
Girls = int(input("Enter the number of girls:"))
Total = Boys + Girls
print("Boys: {0}%\nGirls: {1}%".format(round(Boys/Total*100),round(Girls/Total*100)))
'''

'''
Discussion Q3
num = 1
while num <= 20:
    if (num%3 == 0):
        if (num%5 == 0):
            print("FizzBuzz")
        print("Fizz")
    elif (num%5 == 0):
        print("Buzz")
    else:
        print(num)
    num += 1
'''

'''
Discussion Q2
NoOfStud = 0
TotalScore = 0

while (NoOfStud <= 10):
    TestScore = int(input("Test score for person {}:".format(NoOfStud+1)))
    NoOfStud += 1
    TotalScore = TotalScore + TestScore
else:
    print("Average score for 10 students is {}".format(TotalScore/NoOfStud))
'''