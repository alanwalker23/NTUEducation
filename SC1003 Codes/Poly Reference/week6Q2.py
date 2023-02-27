from sense_hat import SenseHat
sense = SenseHat()
#obtain the temperature in degrees celcius
temperature = sense.get_temperature()
#convert the temperature to degrees fahrenheit
ftemp = temperature*9/5 +32
#obtain the relative humidity
humidity = sense.get_humidity()
#calculating heat index
HI = -42.38 + 2.05*ftemp + 10.14*humidity - 0.225*ftemp*humidity - 0.007*ftemp**2\
     - .0548*humidity**2 + 0.00123*ftemp**2*humidity + 0.00085*ftemp*humidity**2\
     - 0.000002*ftemp**2*humidity**2
if HI <=90:
    print("Effects on the body:\n\
Fatigue possible with prolonged exposure and/or physical activity")
    sense.show_message("",back_colour=[0,255,0])
elif HI<=103:
    print("Effects on the body:\n\
Heat stroke, heat cramps, or heat exhaustion \
possible with prolonged exposure and/or physical activity")
    sense.show_message("",back_colour=[255,255,0])
elif HI<=125:
    print("Effects on the body:\n\
Heat cramps or heat exhaustion likely, and heat stroke\
possible with prolonged exposure and/or physical activity")
    sense.show_message("",back_colour=[255,128,0])
else:
    print("Effects on the body:\n\
Heat stroke highly likely")
    sense.show_message("",back_colour=[255,0,0])
    
