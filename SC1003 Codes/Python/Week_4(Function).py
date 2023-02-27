'''
Create function inputRecord(dataBase, group, id, score)
Allow entering of records into the function inputRecord
database --> database implemented in data structure  
group --> string representing group name
id --> integer from 1-40 
score --> string grade of student
'''
#Global Variables
dataBase = {}

def inputRecord(database, group, id, score):
    database[group,id]=score
    print("The grade score {} of student id {} in group {} has been entered into database.\n".format(score,id,group))
    return 0

def query(database,group,id):
    key = (group,id)
    if key in dataBase:
        grade = database[group,id]
        print("Grade of selected student id {} in group {} is {}.\n".format(id,group,grade))
    else:
        print("No such entry found in database.\n")

def listGrades(database,group):
    grades = []
    for keys in dataBase:
        a,b = keys
        #a refers to group, b refers to student id
        if a == group:
            grades.append(dataBase[keys])
    print("Grades of students within group {} are as followed".format(group))
    for i in grades:
        print(i)
    print()

def maxGrades(database,group):
    grades = []
    for keys in dataBase:
        a,b = keys
        #a refers to group, b refers to student id
        if a == group:
            grades.append(dataBase[keys])
    print("Highest grade within group {} is {}.\n".format(group,max(grades)))

def listGroups(database):
    print("The groups within the database are as followed.")
    for keys in dataBase:
        a,b = keys
        #a refers to group, b refers to student id
        print(a)
    print()
        
while True:
    option=int(input("Welcome to the grading system! Please enter your option:\n\
1:input record\n\
2:query a student\n\
3:list grades in a group\n\
4:get max in a group\n\
5:list all group names\n\
6:exit\n\
option: "))

    if option==1:
        #Function 1 code to run 
        group = str(input("Enter the group name: "))
        id = int(input("Enter the student's ID(1-40): "))
        score = int(input("Enter the grade(1-100): "))
        inputRecord(dataBase,group,id,score)
    elif option==2:
        #Function 2 code to run
        group = str(input("Enter the group name: "))
        id = int(input("Enter the student's ID(1-40): "))
        query(dataBase,group,id)
    elif option==3:
        #Function 3 code to run
        group = str(input("Enter the group name: "))
        listGrades(dataBase,group)
    elif option==4:
        #Function 4 code to run
        group = str(input("Enter the group name: "))
        maxGrades(dataBase,group)
    elif option==5:
        #Function 5 code to run
        listGroups(dataBase)
    elif option==6:
        print("Exiting system.")
        break
    else:
        print("Please enter a valid option.\n")









