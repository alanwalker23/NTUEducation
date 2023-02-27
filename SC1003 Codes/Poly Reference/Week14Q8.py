def printTimetable(times,number):
    for times in range(1,13):
        print("{:d} x {:d} = {:d}".format(times,number,number*times))
number=int(input("Enter a number:"))
printTimetable(1,number)
