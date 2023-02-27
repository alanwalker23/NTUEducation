while True:
    a = int(input("Please key in length of Side A:"))
    b = int(input("Please key in length of Side B:"))
    c = int(input("Please key in length of Side C:"))
    s = (a+b+c)/2
    area = (s*((s-a)*(s-b)*(s-c)))**0.5
    if a + b > c and a + c > b and b + c > a:
        print("Input lengths can form a triangle of area {:.2f} square units\n".format(area))
    else:
        print("Input lengths cannot form a triangle\n")
