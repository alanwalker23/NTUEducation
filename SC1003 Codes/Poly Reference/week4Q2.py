while True:
    a = int(input("Please key in your monthly sales: $"))
    if a>=10000:
        print("Your commission is", a/10)
    else:
        print("Your commission is", a/20)
