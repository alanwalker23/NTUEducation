'''
Exchange currency of SGD - JPY
$1 = 82.88 Yen
'''
import time
while True:
    print ("Currency Converter \n    Option 1                 Option 2")
    MainOption = int(input("Local > Foreign OR Foreign > Local? \n Enter 1 or 2"))
    if MainOption ==1 :
        print ("""
1 = Japanese Yen
2 = Malaysian Ringgit
3 = USA Dollars
4 = British Pounds
5 = China Money
6 = Return back to main menu""")
        while True:
            option = int(input("Select your option"))
            if option ==1 :
                SGD = float(input("How much SGD do you have?"))
                a = SGD * 82.80127
            elif option == 2 :
                SGD = float(input("How much SGD do you have?"))
                a = SGD * 2.89950
            elif option == 3 :
                SGD = float(input("How much SGD do you have?"))
                a = SGD * 0.74089
            elif option == 4 :
                SGD = float(input("How much SGD do you have?"))
                a = SGD * 0.51002
            elif option == 5 :
                SGD = float(input("How much SGD do you have?"))
                a = SGD * 4.87061
            if option == 6 :
                break
            elif option > 6  :
                print ("I don't understand, 1 to 6 only please.")
            print ("calculating...")
            time.sleep(2)
            print(round(a,2))
    elif MainOption ==2 :
        print ("""
1 = Japanese Yen
2 = Malaysian Ringgit
3 = USA Dollars
4 = British Pounds
5 = China Money
6 = Return back to main menu""")
        while True:
            option = int(input("Select your option"))
            if option ==1 :
                SGD = float(input("How much foreign currency do you have?"))
                a = SGD / 82.80127
            elif option == 2 :
                SGD = float(input("How much foreign currency do you have?"))
                a = SGD / 2.89950
            elif option == 3 :
                SGD = float(input("How much foreign currency do you have?"))
                a = SGD / 0.74089
            elif option == 4 :
                SGD = float(input("How much foreign currency do you have?"))
                a = SGD / 0.51002
            elif option == 5 :
                SGD = float(input("How much foreign currency do you have?"))
                a = SGD / 4.87061
            elif option == 6:
                break
            if option > 6  :
                print ("I don't understand, 1 to 6 only please.")
            print ("calculating...")
            time.sleep(2)
            print(round(a,2))
