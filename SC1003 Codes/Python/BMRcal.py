'''
FOR MALESBMR = 88.362 + (13.397 × weight in kg) + (4.799 × height in cm) - (5.677 × age in years)
FOR FEMALESBMR = 447.593 + (9.247 × weight in kg) + (3.098 × height in cm) - (4.330 × age in years)
'''

gender = input("Enter gender: ")
weight = float(input("Enter weight(kg): "))
height = float(input("Enter height(cm): "))
age = int(input("Enter age: "))

if gender=="male":
    print("{:.2f}".format(88.362+(13.397*weight)+(4.799*height)-(age*5.677)))
elif gender=="female":
    print("{:.2f}".format(447.593+(9.247*weight)+(3.098*height)-(4.330*age)))