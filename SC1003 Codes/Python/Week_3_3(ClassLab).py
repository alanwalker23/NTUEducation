#Discussion Question 3
'''
Need to create a class that stores the following variables
1. ID (1-40)
2. Group Name (E.g. "FE2")
3. Grade (1-100)
'''
class Student:
    def __init__(student,id,group,grade):
        student.id = id
        student.group = group
        student.grade = grade

    def declare(Object):
        print("\nStudent's elements are as follows\n\
ID: {0}\n\
Group Name: {1}\n\
Grade: {2}".format(Object.id,Object.group,Object.grade))

print("Student data creation")
while True:
    id=int(input("Enter ID of student (1-40): "))
    if id>0 and id<=40:
        break
    else:
        print("ID not in range (1-40)")
groupname=str(input("Enter Group Name of student: "))
while True:
    grade=int(input("Enter Grade of student (0-100): "))
    if grade>0 and grade<=100:
        break
    else:
        print("Grade not in range (1-100)")

student1 = Student(id,groupname,grade)
student1.declare()