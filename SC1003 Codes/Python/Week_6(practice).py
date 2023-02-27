'''
def myFun(param):
    param.append(4)
    return param


def myFun1(param):
    newlist = []
    #If you hard-code param=[1,2,3] it will return a newlist 1,2,3,4 that does not affect original list
    for i in param:
        newlist.append(i)
    newlist.append(4)
    return newlist

myList = [1,2,3]
#newList = myFun(myList)
newList1 = myFun1(myList)
print(myList,newList1)
'''

myVar = 127
def myFun ():
    a = myVar + 1
    print("a: ",a)

myFun()


