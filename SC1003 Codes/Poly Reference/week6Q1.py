#importing SenseHat
from sense_hat import SenseHat
sense = SenseHat()
#Let users understand what they are doing
print("Integer checker, checks if number is divisible by 5 and 6")
a = int(input("Input a number"))
#let program check number and determine the output
#For number that is divisible by 5&6
if a%5==0 and a%6==0:
    x=[0,255,0]
    o=[255,255,255]
    tick=[o,o,o,o,o,o,o,o,
            o,o,o,o,o,o,o,x,
            o,o,o,o,o,o,x,o,
            o,o,o,o,o,x,o,o,
            x,o,o,o,x,o,o,o,
            o,x,o,x,o,o,o,o,
            o,o,x,o,o,o,o,o,
            o,o,o,o,o,o,o,o]
    sense.set_pixels(tick)
    print("Your number is divisible by 5 and 6")
#For number that is not divisible by 5&6
else:
    x=[255,0,0]
    o=[255,255,255]
    cross=[x,o,o,o,o,o,o,x,
           o,x,o,o,o,o,x,o,
           o,o,x,o,o,x,o,o,
           o,o,o,x,x,o,o,o,
           o,o,o,x,x,o,o,o,
           o,o,x,o,o,x,o,o,
           o,x,o,o,o,o,x,o,
           x,o,o,o,o,o,o,x]
    sense.set_pixels(cross)
    print("Your number is not divisible by 5 and 6")
    
            
    
    
