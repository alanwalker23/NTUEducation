def payTable(hours):
    if hours <=3:
        return(hours*6)
    elif hours<=7:
        return((hours-3)*7+3*6)
    else:
        return((hours-7)*8+3*6+4*7)
hours=int(input("Enter nubmer of hours:"))
for i in range (1,hours+1):
    print("Total pay for {:d} hours(s): ${:d}".format(i,payTable(i)))
