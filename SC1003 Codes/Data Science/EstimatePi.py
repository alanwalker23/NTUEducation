import random
import math
circle = 0
square = 0
estimates = int(input("Enter value: "))
for i in range(estimates):
    x = random.uniform(0,1)
    y = random.uniform(0,1)
    distance = x**2 + y**2 #Sqrt not needed, <1 will remain <1 and viceversa
    #print(distance)
    if (distance <= 1):
        circle +=1
    square +=1 #Regardless need to add point to square
print(circle,square)
estimatePi = 4*(circle/square)
print(estimatePi)

"""
Question
Using only integers from 0 to 1, find pi without hard coding
"""