def calcAreaOfRectangle(length,width):
    area=length*width
    return(area)
olength=float(input("Enter length of outside rectangle:"))
owidth=float(input("Enter width of outside rectangle:"))
ilength=float(input("Enter length of inside rectangle:"))
iwidth=float(input("Enter width of inside rectangle:"))
shadedarea=calcAreaOfRectangle(olength,owidth)-calcAreaOfRectangle(ilength,iwidth)
print("The shaded area is {:.2f}".format(shadedarea))
