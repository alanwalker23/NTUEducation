'''
import random
def GenerateAnswer():
    answer = []
    while True:
        if len(answer)!=6:
            number = int(random.randint(0,9))
            #this line makes the generated number unique.
            #if number in answer:
            #    continue
            #else:
            #    answer.append(number)
            
            answer.append(number)
        else:
            break

    return(answer)

def singlebubblesort(list):
    for i in range(len(list)):
        if i==0:
            continue
        else:
            if list[i]<list[i-1]:
                replace=list[i-1]
                list[i-1] = list[i]
                list[i] = replace
    return list


sixnum = GenerateAnswer()
print(sixnum)

newlist=singlebubblesort(sixnum)
print(newlist)

comlist=completebubblesort(sixnum)
print(comlist)
'''

def bubbleSort(alist):
    attempt=0
    for passnum in range(len(alist)-1):
        for i in range(len(alist)-passnum-1):
            if alist[i]>alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp
                attempt+=1
    print(attempt)

def completebubblesort(list):
    attempt = 1
    inter = 0
    while attempt != 0:
        attempt = 0
        for i in range(len(list)):
            if i==0:
                continue
            else:
                if list[i]<list[i-1]:
                    replace=list[i-1]
                    list[i-1] = list[i]
                    list[i] = replace
                    attempt+=1
                    inter+=1
    print(inter)
    return list

#alist = [54,26,93,17,77,31,44,55,20]
#blist = [54,26,93,17,77,31,44,55,21]
alist = [1,2,3]
blist = [1,2,3]
comlist=completebubblesort(blist)
print(comlist)
bubbleSort(alist)
print(alist)


'''
from operator import itemgetter
restaurant_info = [['Kentucky', 15, 6, 'Fried chicken'],
['Macdonald', 12, 5,'Burger'],
['Subway', 13, 7, 'Sandwiches']]
# filed 1 (index 0): name of restaurant
# field 2 (index 1): distance of restaurant
# field 3 (index 2): average price per person of the restaurant
# field 4 (index 3): signature dish of the restaurant
sort_info = sorted (restaurant_info, key = itemgetter(3))
print('sort by distance', sort_info)
'''