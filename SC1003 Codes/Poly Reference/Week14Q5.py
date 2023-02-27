item=[]
price=[]
def readdata(item,price):
    infile=open('menu.txt','r')
    for line in infile:
        lines = line.split("#")
        item.append(lines[0])
        price.append(float(lines[1]))
readdata(item,price)
print('-'*50,"\n\tBreakfast Menu\n",'-'*50)
for i in range(int(len(item))):
    print("{:d}. {:s}".format(i+1,item[i]))
choice=int(input("\nEnter your choice of breakfast menu:"))
print("You've selected {:s} \nPrice: ${:.2f}".format(item[choice-1],price[choice-1]))
