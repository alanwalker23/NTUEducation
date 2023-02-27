def calcAreaOfRectangle (length,width):
    answer=length*width
    return answer
length=float(input("Enter length:"))
width=float(input("Enter width:"))
area=calcAreaOfRectangle(length,width)
print("Area of the rectangle {:.1f} x {:.1f} is {:.1f}".format(length,width,area))
