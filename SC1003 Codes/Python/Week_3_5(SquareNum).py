#Discussion Question 4
'''
List of all x-squared numbers that are divisible by 3
Range of x 1-100, therefore max is 10,000 (x^2)
'''
#Solution 1 [Most portable and flexible]
divisibleby3 = []
for i in range(1,101):
    if (i*i)%3==0:
        divisibleby3.append(i*i)
print(divisibleby3)

#Solution 2 [Most editable]
list2 = [x**2 for x in range(1,101) if x**2 %3 == 0]
print(list2)

#Solution 3 [Shortest possible]
list3 = [x**2 for x in range(3,101,3)]
print(list3)