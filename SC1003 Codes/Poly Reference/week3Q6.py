#Formula to convert celsius to fahrenheit: F=  9/5 C+32

print("Celsius(C) to Fahrenheit(F) CONVERTER TABLE")
c = 100

for i in range (0,10):
    print("Celsius \t Fahrenheit \n {:.2f} \t {:.2f}".format(c,9*c/5 +32))
    c-=10


