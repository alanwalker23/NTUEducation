while True:
    gender = input("Enter gender [M/F] :")
    age = int(input("Enter age:"))
    surcharge = input("Have you been in a traffic accident before? [Y/N] :")
    insurance = 800
    #For male
    if (gender.upper() == "M"):
        if age < 25:
            insurance *= 1.8
        elif age <= 34:
            insurance *= 1.5
        elif age <= 44:
            insurance *= 1.2
        elif age <= 54:
            insurance *= 1.0
        elif age <= 64:
            insurance *= 1.4
        else:
            multiplier *= 1.7
    #For female
    elif (gender.upper() == "F"):
        if age < 25:
            insurance *= 1.4
        elif age <= 34:
            insurance *= 1.3
        elif age <= 44:
            insurance *= 1.1
        elif age <= 54:
            insurance *= 0.9
        elif age <= 64:
            insurance *= 1.2
        else:
            insurance *= 1.4
    if (surcharge.upper() == "Y"):
        insurance += 300
    print("Your annual premium is:\n", insurance)
        

        
