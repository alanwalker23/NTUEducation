while True:
    a = int(input("Please key in an integer number:"))
    if a%5 == 0 and a%6 == 0:
        print(a,"is divisible by 5 and 6")
    else:
        print(a,"is not divisible by 5 and 6")
