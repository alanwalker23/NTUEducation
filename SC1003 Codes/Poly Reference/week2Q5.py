#BMI = Weight in Kilograms / (Height in Meters x Height in Meters )

Weight = int(input("Weight in Kilograms?"))
Height = float(input("Height in Meters?"))
BMI = Weight/(Height * Height)
print ("Your BMI is", "%.3f" % BMI, "(round off to nearest 3sf)")

