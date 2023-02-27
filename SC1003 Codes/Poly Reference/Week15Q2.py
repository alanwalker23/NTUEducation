def goodMoreThan5(*val):
    if len(val)>5:
        print("Good! Number of parameters are more than 5")
    else:
        print("Bad! Number of parameters are 5 or less")
goodMoreThan5(1,2,3,4,5,6,7,8)
