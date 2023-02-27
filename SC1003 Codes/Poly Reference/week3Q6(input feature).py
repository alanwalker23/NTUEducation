#Formula to convert celsius to fahrenheit: F=  9/5 C+32

print("Celsius(C) to Fahrenheit(F) CONVERTER TABLE")
while True:
    c = int(input("Please input your desired temperature in Celsius(C) [Multiples of 10 please]"))
    if c%10 == 0:
        print("Celsius \t Fahrenheit")
        for i in range (0,10):
            print(" {:.2f} \t {:.2f}".format(c,9*c/5 +32))
            c-=10
    elif c%10 > 0:
        print("Please input your temperature in multiples of 10")


