print("Leap year checker")
while True:
    year=int(input("Input your desired year:"))
    if year<=0:
        print("Please input a valid year")
    else:
        if year%400==0:
            print("{} is a leap year".format(year))
        elif year%4==0 and year%100!=0:
            print("{} is a leap year".format(year))
        else:
            print("{} is not a leap year".format(year))
        
