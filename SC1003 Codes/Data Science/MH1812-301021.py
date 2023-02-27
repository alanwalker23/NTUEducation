#import math
length = 10000
string = "hi"

for i in range(10,20):
    string = str(i)
    print("string=",string)
    sum = 0
    for j in range(len(string)):
        sum += int(string[j])
    print("i=",i)
    print("sum of digit=",sum)

