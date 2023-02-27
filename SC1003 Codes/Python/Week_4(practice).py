#You cannot append a list into a dictionary
value=[]
value.append("Hello")
value.append("Potato")
database = {'firstname':'boi', 'lastname':'girl',value:'potato'}
print(database[value])

'''
string = "Hello World"
string1 = "123"
string2 = "abc"
print(string1.join(string2)) #Result is a123b123c
'''

'''
List methods
list.append(e) #Adds an element to the end
list.extend(L) #Joins a List behind the current list
list.pop(i) #Removes the element index i or last element if unspecified
list.insert(i,e) #Insert element at index i
list.remove(e) #Removes a specified element (Only first matching element removed)
list.sort()
list.reverse()
'''

'''
myStr = 'Python Rules'
print(myStr[::-2].upper().find('Y')) 
#Subsetting of string myStr [::-2] = slRnhy
#New substring converted to upper = SLRNHY
#Find 'Y' within new string returns 5 as index is 5
'''

'''
count = 0
for char in string:
    print("{}".format(char),end=" ")
    print(count)
    count += 1
'''

'''
for i in range(len(string)):
    print(i,end=" ")

newstring = string[:]
newstring = ''.join(string)
reverse = string[::-1]
print(string[-1:-6:-2]) 
#In case it is [:-6:-2], start from back because first is -1
print(newstring)
print(reverse)
'''

#ord takes a char and return unicode of char
#chr takes Unicode and return corresponding char
code = ord('a')
chr(code+1) #Gives b, hence encrpyt

'''
Code can be used for comparison given their unicode placing
e.g "a" == "a"       returns true   
'a' < 'b' (97 vs 98) returns true
'1' < '9'            returns true
'a' < 'B' (97 vs 64) hence false
'''
