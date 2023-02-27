count=0
total=0
balance=float(input("Enter the outstanding balance ($):"))
interest=float(input("Enter the monthly interest (%):"))
payment=float(input("Enter the monthly payment ($):"))
print("{:5s} \t {:10s} \t {:10s} \t {:16s}".format("Month","Payment($)","Balance($)","Total Payment($)"))
while balance>0:
    balance-=payment
    if balance<0:
        payment=payment+balance
        balance=0
    balance*=((100+interest)/100)
    count+=1
    total+=payment
    print("{:5d} \t {:<.2f} \t {:>16s}{:.2f} \t\t {:<.2f}".format(count,payment,"",balance,total))
    
    
    
