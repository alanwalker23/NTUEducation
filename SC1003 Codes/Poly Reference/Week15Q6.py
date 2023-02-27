def findNRICNumber(index):
    print(nriclist[index])
nriclist=['S101','S102','S103','S104','S105']
while True:
    print(nriclist)
    index=int(input("Select a NRIC:"))-1
    if index <0 or index>(len(nriclist)):
        print("Please enter a valid index\n")
    else:
        break
findNRICNumber(index)
