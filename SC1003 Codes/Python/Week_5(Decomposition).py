import random

def GenerateAnswer():
    answer = []
    while True:
        if len(answer)!=4:
            number = str(random.randint(0,9))
            if number in answer:
                continue
            else:
                answer.append(number)
        else:
            break

    return(answer)

def CheckCow(answer,guess):
    cow=0
    for i in answer:
        for j in guess:
            if i == j:
                cow+=1
                break
    return(cow)

def CheckBull(answer,guess,cow):
    bull=0
    answerchar = []
    guesschar = []
    for i in answer:
        answerchar.append(i)
    for j in guess:
        guesschar.append(j)
    for k in range(len(answerchar)):
        if answerchar[k] == guesschar[k]:
            bull+=1
    cow-=bull
    return[bull,cow]

answer = GenerateAnswer()
attempt=0
while True:
    attempt+=1
    guess = str(input("Please input 4 digits: "))
    check = CheckBull(answer,guess,CheckCow(answer,guess))
    bull=check[0]
    cow=check[1]
    if bull == 4:
        print("You win!")
        print("Attempts: ",attempt)
        break
    else:
        print("{} A (Bulls) {} B (Cows)".format(bull,cow))
    

