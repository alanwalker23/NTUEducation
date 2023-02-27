import random
print("Welcome to Mastermind, a game of patience and intelligence.\nI will personally pick \
3 colours for slots A,B and C, and it is \nyour mission to guess the colours that I have picked.")
while True:
    a=random.randint(1,5)
    b=random.randint(1,5)
    c=random.randint(1,5)
    print("1 - Red \n2 - Green \n3 - Blue \n4 - Black \n5 - White")
    a1=0
    b1=0
    c1=0
    attempt=0
    for i in range(8):
        correct=0
        similar=0
        a1=int(input("Select a colour for slot A:"))
        b1=int(input("Select a colour for slot B:"))
        c1=int(input("Select a colour for slot C:"))
        if a1==a:
            correct+=1
        elif b1 == a:
            similar+=1
        elif c1 == a:
            similar+=1
        if b1==b:
            correct+=1
        elif a1 == b:
            similar+=1
        elif c1 == b:
            similar+=1
        if c1==c:
            correct+=1
        elif a1 == c:
            similar+=1         
        elif b1 == c:
            similar+=1
        attempt+=1
        print(correct,"Correct")
        print(similar,"Similar")
        print(attempt,"Attempts\n\n\n")
        if correct ==3:
            print("Congratulations! You've won in {:d} attempts".format(attempt))
            break
        if attempt ==8:
            print("Perhaps this was a little too challenging for someone like you...\nTry harder next time.")
    option=input("Try again? Y/N \nReply:")
    if option.upper()=="N":
        print("Thank you for playing!")
        break
    else:
        print("\n\n\n")
    
    
            
    
       
