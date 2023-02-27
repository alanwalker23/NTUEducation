#Fibonacci Sequence inp - 1 2 3 4 5 6 7  8  9 10 11
#Fibonacci Sequence out - 0 1 1 2 3 5 8 13 21 34 55
#Print Xn = X-1n + X-2n
def fibo(num):
    a = 0
    b = 1
    if num < 1:
        print("Input too small")
    elif num== 1:
        print(a)
    else:
        print(a)
        print(b)

        for i in range (2,num):
            c = a + b
            a = b
            b = c
            #To print sequence
            print(c)
        #To print end result of input
        print(c)
#fibo(10)

#If doing recursive function
def fib(num):
    if num == 1:
        return 0
    elif num == 2:
        return 1
    else:
        return fib(num-1)+fib(num-2)
#print(fib(10))

def printTree(t,level):
    if len(t) == 1:
        print(" " * level, end="")
        print(t[0])
    else:
        printTree(t[2], level + 1)
        print(" " * level, end="")
        print(t[1])
        printTree(t[0], level + 1)
tree = [[[7], 1, [9]], 3, [[8], 2, [4]]]
printTree(tree,1)

