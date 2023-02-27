P = 10000
r = 8/100
n = 12
t = int(input("How many years do you want the money to be compounded?"))
A = P*(1+r/n)**(n*t)
print("This is your compounded interest", "%.2f" % A , "(rounded off to 2dp)")

#To make the compound interest go to 2 decimal place, figure out "string formatting"
