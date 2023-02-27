#Discussion Question 2
'''
Input string needs to pass certain checks to ensure that it is a good password
Generally for HTML password encoding, to prevent brute force we should ensure that passwords do not have "." or "/"
Rules to check for
1.No blank spaces or random spacing --> check if == " " for every character [Need for loop]
2.At least 1 caps --> isupper() for every character [Need for loop]
3.At least 10 characters long --> Len of password >= 10
4.At least 1 special symbols within list[@,?,!,`] --> Need to iterate within this list with a Symbol Checker 
5. Unicode setting (?)
To make the codes more readable, we shall employ the usage of functions
'''
#Functions
def Symbol_Checker(password):
    symbolused = 0
    symbols = ["@","?","!","`"]
    for character in password:
        if character in symbols:
            symbolused+=1
    if symbolused==0:
        print("Password does not have any special characters used within list[@,?,!,`]")
        return 1
    else:
        return 0

def Space_Checker(password):
    SpaceChecker = 0
    for character in password:
        if character==" ":
            SpaceChecker+=1
    if SpaceChecker >0:
        print("Password has blanks! There are {} spaces in your password.".format(SpaceChecker))
        return 1
    else:
        return 0

def Caps_Checker(password):
    CapsChecker = 0
    for character in password:
        if character.isupper():
            CapsChecker+=1
    if CapsChecker==0:
        print("Lacking 1 capitalized character!")
        return 1
    else:
        return 0

#Actual Codes
print("Password Checker\n\
RULES\n\
1.No blank spaces or random spacing\n\
2.At least 1 capital letter\n\
3.At least 10 characters long\n\
4.At least 1 special symbols within list[@,?,!,`]")

while True:
    Password = str(input("\nPlease enter your desired password: "))
    if len(Password) <10:
        print("Password too short! {} more characters needed.".format(10-len(Password)))
        continue
    else:
        checks=0
        checks += Space_Checker(Password)
        checks += Symbol_Checker(Password)
        checks += Caps_Checker(Password)
    if checks==0:
        print("Password successfully created: {}".format(Password))
        break
'''
Appends Earth to the list
Rejects = [".","/"," "]
print(Rejects.index("Earth"))
'''
