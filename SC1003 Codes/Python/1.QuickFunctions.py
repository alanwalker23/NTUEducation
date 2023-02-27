#If no blank, return 0, else return 1 with a message prompt
def Space_Checker(word):
    SpaceChecker = 0
    for character in word:
        if character==" ":
            SpaceChecker+=1
    if SpaceChecker >0:
        print("Input has blanks! There are {} spaces in your input.".format(SpaceChecker))
        return 1
    else:
        return 0

#Generate a list of unique values
import random
def GenerateAnswer():
    answer = []
    while True:
        if len(answer)!=4:
            number = str(random.randint(0,9))
            #this line makes the generated number unique.
            if number in answer:
                continue
            else:
                answer.append(number)
        else:
            break

    return(answer)
