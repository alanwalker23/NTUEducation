from typing import Sized


size = 0

size = int(input("Enter size of square: "))
for i in range(size):
    if i==0:
        print(" O"*size)
    elif i==size-1:
        print(" O"*size)
    else:
        print(" O"+"  "*(size-2)+" O")
