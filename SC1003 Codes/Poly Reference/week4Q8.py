x = float(input("Please key in your X Co-ordinates:"))
y = float(input("Please key in your Y Co-ordinates:"))
if x>0 and y>0:
    print("Your points are in the 1st quadrant.")
elif x<0 and y>0:
    print("Your points are in the 2nd quadrant.")
elif x<0 and y<0:
    print("Your points are in the 3rd quadrant.")
else:
    print("Your points are in the 4th quadrant.")
    
    
