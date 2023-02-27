organization=input("Input organization:")
member=[]
name=0
while name!="":
    name=input("Input name(return/enter to end):")
    member.append(name)
print("ICT welcomes guests from {:s}".format(organization))
for i in member:
    print(i)
    
    
