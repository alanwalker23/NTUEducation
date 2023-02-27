size = int(input())
newnum = int(input())
min = newnum
max = newnum
numbers= []
numbers.append(newnum)
for i in range(size-1):
    newnum = int(input())
    if (newnum<min):
        min = newnum
    if (newnum>max):
        max = newnum
    numbers.append(newnum)
print(numbers)
print(min)
print(max)

newsize = max-min+1
fullset = []
for i in range(newsize):
    fullset.append(min)
    min = min+1
print(fullset)

missingset = []
j = 0
for i in range(newsize):
    print(i)
    if (fullset[i]==numbers[j]):
        continue
    missingset.append(fullset[i])
    if (j!=size-1):
        j = j+1
print(missingset)