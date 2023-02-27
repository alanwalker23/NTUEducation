breakfastlist=['Toast bread with coffee','Cereals in chocolate milk',\
               'Croissant sandwich with tuna filling','Hotcakes with syrup','French toast with tea']
def breakfastMenu():
    print("-"*30,"\n {:10s}Breakfast Menu\n".format(""),"-"*30)
    print("1. Toast bread with coffee")
    print("2. Cereals in chocolate milk")
    print("3. Croissant sandwich with tuna filling")
    print("4. Hotcakes with syrup")
    print("5. French toast with tea")
    choice=int(input("Enter your choice of breakfast menu:"))
    return choice
choice=breakfastMenu()
print("You will be served {:s}".format(breakfastlist[choice-1]))
    

