def libFines(days):
    if days<7:
        cost=0.1*days
    else:
        cost=0.2*days
    return(cost)
print("Fine imposed on 3 books overdue for 5 days is ${:.2f}".format(libFines(5)*3))
print("Fine imposed on 2 books overdue for 10 days is ${:.2f}".format(libFines(10)*2))
print("Total fine imposed altogether on the books is ${:.2f}".format(libFines(5)*3+libFines(10)*2))
