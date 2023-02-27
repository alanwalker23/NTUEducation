import math
def calcAreaOfRectangle(length,width):
    area=length*width
    return(area)
def calcAreaOfCircle(radius):
    area=math.pi*radius**2
    return(area)
length=float(input("Enter the length of the rectangle:"))
width=float(input("Enter the width of the rectangle:"))
radius=float(input("Enter the radius of the circle:"))
RectangleArea=calcAreaOfRectangle(length,width)
CircleArea=calcAreaOfCircle(radius)
print("Area of rectangle is {:.2f}\n\
Area of circle is {:.2f} \n\
Area of the shaded portion is {:.2f}"\
      .format(RectangleArea,CircleArea,RectangleArea-CircleArea))
