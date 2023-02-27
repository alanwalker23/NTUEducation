'''
#Returns 1,2,3,2,1
text = int(input("Enter a number: "))
counter = 0
for i in range(text):
    print(i+1)
for j in range(text-1):
    print(text-1)
    text -= 1
'''

#Q4 Alternate Solution
L = int(input("Enter pattern width: "))
pstr=''

for i in range(1,L+1):
    pstr=pstr+'*'
    print(pstr)

for i in range(L-1,0,-1):
    pstr1=pstr[0:i]
    print(pstr1)

'''
#Discussion Q4
width = int(input("Please enter pattern width: "))
for i in range(width):
    for j in range(i+1):
        print("*",end="")
    print("")
for l in range(width-1):
    for m in range(width-1):
        print("*",end="")
    print("")
    width -= 1
'''

'''
#Discussion Q3
num = 1
while num <= 20:
    if (num%3 == 0 and num%5==0):
        print("FizzBuzz")
    elif (num%3 == 0):
        print("Fizz")
    elif (num%5 == 0):
        print("Buzz")
    else:
        print(num)
    num += 1
'''

'''
#Discussion Q2
count = 0
while True:
    text = input("enter a string: ")
    for letter in text:
      if letter == 'a':
          count += 1
          break
    if text == "####":
        break
print(count , "strings with letter 'a'")
'''

'''
Question 1
value = 6
if value % 2 == 0:
   print("first", value)
elif value % 3 == 0:
   print("second", value)
   
while value <= 9:
   value = value + 1
   if value == 8:
      continue
   else:
      pass
   print ("third", value)
else:
   print ("fourth", value)

print("fifth", value)
'''
