#Discussion Question 4
'''
2 Lists of grades
Check which class has highest average score and highest maximum score
Average = total/num of students
Max = highest in an array (use max(list))
'''
#Generate random numbers and append into 2 lists, class A and B
import random
classes= [] #classA,classB
for n in range(2):
    classes.append([])
    for i in range (10):
        grade = random.randint(0,10)
        classes[n].append(grade)


#Take note that for these codes, it does not account for when both classes average or max are equal.
#In the scenario where both average and max are equal, it will default B.
for n in classes:
    print("Elements in class {0}: {1}".format(classes.index(n)+1,n))
    
if sum(classes[0])>sum(classes[1]):
    print("Class 1 has a higher average mark of {}".format(sum(classes[0])/len(classes[0])))
else:
    print("Class 2 has a higher average mark of {}".format(sum(classes[1])/len(classes[1])))

if max(classes[0])>max(classes[1]):
    print("Class 1 has a higher maximum mark of {}".format(max(classes[0])))
else:
    print("Class 2 has a higher maximum mark of {}".format(max(classes[1])))
    

'''
Matrix creation reference
matrix = []
for i in range(2):
    # Append an empty sublist inside the list
    matrix.append([])
    for j in range(5):
        grade=random.randint(0,10)
        matrix[i].append(grade)
print(matrix)
'''