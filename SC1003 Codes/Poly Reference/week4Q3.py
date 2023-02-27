while True:
    #allow users to understand the limit of the program
    print("This program is only valid for temperatures between -58 degrees Fahrenheit and\
 41 degrees Fahrenheit (inclusive) and wind speed above 2 mph.\n")
    #Prompt user for input of the temperature
    a = float(input("Please enter the outside temperature in Fahrenheit:"))
    #Prompt user for input of the wind speed
    b = int(input("Please enter the wind speed in miles per hour:"))
    #Calculation for programmme
    c = 35.74 + 0.6215 * a - 35.75 * b ** 0.16 + 0.4275 * a * b ** 0.16
    if (a< -58 or a> 41) or b<2:
        print("Incorrect input, please refer to line 1\n")
    else:
        print("The wind-chill index is {:.2f}\n".format (c))
        
    
    
    
