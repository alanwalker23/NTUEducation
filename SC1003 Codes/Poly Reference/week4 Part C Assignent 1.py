weight = float(input("Please key in your weight(KG):"))
height = float(input("Please key in your height(Meter):"))
reply = weight/(height*height)
if reply < 18.5:
    print("BMI={:.2f}\nFat Amount:Underweight\
\nHealth Risk:Risk of nutritional deficiency".format(reply))
elif reply <= 23:
    print("BMI={:.2f}\nFat Amount:Normal weight\
\nHealth Risk:Low risk, healthy range".format(reply))
elif reply <= 27.5:
    print("BMI={:.2f}\nFat Amount:Overweight\
\nHealth Risk:Moderate risk".format(reply))
else:
    print("BMI={:.2f}\nFat Amount:Obese\
\nHealth Risk:High risk".format(reply))
    

