from sense_hat import SenseHat
sense = SenseHat()

weight = float(input("Please key in your weight(KG):"))
height = float(input("Please key in your height(Meter):"))
reply = weight/(height*height)
if reply < 18.5:
    print("BMI={:.2f}\nFat Amount:Underweight\
\nHealth Risk:Risk of nutritional deficiency".format(reply))
    sense.show_message("Risk of nutritional deficiency",text_colour=[255,255,0])
elif reply <= 23:
    print("BMI={:.2f}\nFat Amount:Normal weight\
\nHealth Risk:Low risk, healthy range".format(reply))
    sense.show_message("Low risk, healthy range",text_colour=[0,255,0])
elif reply <= 27.5:
    print("BMI={:.2f}\nFat Amount:Overweight\
\nHealth Risk:Moderate risk".format(reply))
    sense.show_message("Moderate risk",text_colour=[255,128,0])
else:
    print("BMI={:.2f}\nFat Amount:Obese\
\nHealth Risk:High risk".format(reply))
    sense.show_message("High risk",text_colour=[255,0,0])
    

