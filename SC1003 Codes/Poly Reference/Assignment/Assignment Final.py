'''DECLARATIONS'''
NRICList=[]
Namelist=[]
Weight=[]
Height=[]
bmi=0
BMI=[]
BloodType=[]
AllAttributes=[NRICList,Weight,Height,BMI,BloodType]
counter=0
option=0
nameposition=0
attributeposition=0
import math
'''FUNCTIONS'''
#Main Menu Function (Displays main menu)
def MainMenu ():
    print('MENU')
    print('='*4)
    print('[1] Read student info from file')
    print('[2] Display all student info with BMI')
    print('[3] Display average BMI')
    print('[4] Display tallest student')
    print('[5] Display all students taller than a given height')
    print('[6] Display additional features')
    print('[0] Exit')
    option=int(input("Enter your option:"))
    return option
    
#Read Data Function (Reads data from file)
def ReadData ():
    counter=0
    NRICList.clear()
    Namelist.clear()
    Weight.clear()
    Height.clear()
    BMI.clear()
    BloodType.clear()
    print("Option 1: Read student info from file\n")
    filename=input("Enter the name of the data file:")
    infile=open(filename,'r')
    for line in infile:
        text=line.split(';')
        NRICList.append(text[0])
        Namelist.append(text[1])
        Weight.append(text[2])
        Height.append(float(text[3]))
        bmi=(float(text[2])/(float(text[3])**2))
        BMI.append(round(bmi,2))
        BloodType.append(text[4].strip('\n'))
        counter+=1
    print("Number of records read:",counter)

#Display BMI Function
def DisplayBMI():
    print("Option 2: Display all student info with BMI\n")
    print("{:10s} \t {:<18s} \t {:7s} \t {:7s} \t {:6s} \t {:10s}".format("NRIC No.","Name",\
                                                                         "Weight","Height","BMI","Blood Type"))
    print("{:12s} \t {:18s} \t {:7s} \t {:7s} \t {:6s} \t {:10s}".format("-"*12,"-"*18,'-'*7,'-'*7,\
                                                                         '-'*6,'-'*10))
    for i in range(len(NRICList)):
        print("{:10s} \t {:18s} \t {:7s} \t {:5.2f} \t {:4.2f} \t{:10s}".format(NRICList[i],Namelist[i],\
                                                                               Weight[i],Height[i],BMI[i],BloodType[i]))

#Display Average BMI
def DisplayAverageBMI():
    print("Option 3: Display average BMI\n")
    global averageBMI
    averageBMI=sum(BMI)/len(BMI)
    print("Average BMI: {:.2f}".format(averageBMI))

#Display tallest student
def TallestStudent():
    print("Option 4: Display tallest student\n")
    tallest=max(Height)
    counter=-1
    for i in Height:
        counter+=1
        if tallest==i:
            tallestperson=Namelist[counter]
    print("Tallest student is {:s} who is {:.2f}m".format(tallestperson,tallest))

#Display all students taller than a given height
def StudentsTallerThan():
    print("Option 5: Display all students taller than a given height\n")
    while True:
        targetheight=float(input("Enter target height:"))
        if targetheight<1.5 or targetheight>2:  
            print("Invalid input")
        else:
            break
    print("The following students are taller than {:.2f}m".format(targetheight))
    counter=-1
    for i in Height:
        counter+=1
        if float(i)>=targetheight:
            print("\t{:s}\t-{:.2f}m".format(Namelist[counter],i))

#Invalid Input
def InvalidInput():
    print("Please enter a valid input.")

'''ADDITIONAL FEATURES'''
def AdditionalFeaturesMenu():
    print('\n\n\nAdditional Features Menu')
    print('='*25)
    print('[1] Display Average BMI')
    print('[2] Blood Type Graph')
    print('[3] BMI Graph')
    print('[4] Height Graph')
    print('[5] Special Feature')
    print('[0] Exit')
    option=int(input("Enter your option:"))
    return option

#Display average BMI on sense hat on Raspberry Pi
'''
def SenseHatAverageBMI():
    sense.show_message("{:.2f}".format(averageBMI))
'''

#Display Blood Type Graph
def BloodTypeGraph():
    BloodTypeGroup=[' O+',' O-',' A+',' A-',' B+',' B-',' AB+',' AB-']
    BloodTypeCounter=[0,0,0,0,0,0,0,0]
    for i in range(len(BloodType)):
        for v in range(len(BloodTypeGroup)):
            if BloodType[i]==BloodTypeGroup[v]:
                BloodTypeCounter[v]+=1
    limit=max(BloodTypeCounter)
    BloodTypeGraph=[]
    for i in BloodTypeCounter:
        i=math.ceil(i/limit*8)
        BloodTypeGraph.append(i)
    print(BloodTypeGraph)
    #Sense.set_pixel here

def BMIGraph():
    BMICounter=[0,0,0,0]
    for i in BMI:
        if i<18.5:
            BMICounter[0]+=1
        elif i<23:
            BMICounter[1]+=1
        elif i<27.5:
            BMICounter[2]+=1
        else:
            BMICounter[3]+=1
    BMIGraph=[]
    limit=max(BMICounter)
    for i in BMICounter:
        i=math.ceil(i/limit*8)
        BMIGraph.append(i)
    print(BMIGraph)
    #Sense.set_pixel here
    
def HeightGraph():
    HeightCounter=[0,0,0,0,0,0,0,0]
    HeightSummary=[]
    for i in Height:
        if i<=1.5:
            HeightCounter[0]+=1
        elif i<=1.55:
            HeightCounter[1]+=1
        elif i<=1.6:
            HeightCounter[2]+=1
        elif i<=1.65:
            HeightCounter[3]+=1
        elif i<=1.7:
            HeightCounter[4]+=1
        elif i<=1.75:
            HeightCounter[5]+=1
        elif i<=1.8:
            HeightCounter[6]+=1
        else:
            HeightCounter[7]+=1
    HeightGraph=[]
    limit=max(HeightCounter)
    for i in HeightCounter:
        i=math.ceil(i/limit*8)
        HeightGraph.append(i)
    print(HeightGraph)
    #Sense.set_pixel here

'''Special Feature'''
def UniqueFeatureMenu():
    print('\n\n\nUnique Features Menu')
    print('='*20)
    print('[1] Next name')
    print('[2] Previous name')
    print('[3] Next attirbute')
    print('[4] Previous attribute')
    print('[0] Exit')
    print('Current:',Namelist[nameposition],AllAttributes[attributeposition][nameposition])
    option=int(input("Enter your option:"))
    return option

def NameScrollUp():
    global nameposition
    nameposition=nameposition+1
    if nameposition==len(Namelist):
        nameposition=0
    print(Namelist[nameposition])

def NameScrollDown():
    global nameposition
    nameposition=nameposition-1
    if nameposition==-1:
        nameposition=len(Namelist)-1
    print(Namelist[nameposition])

def DisplayAttributeLeft():
    global attributeposition
    attributeposition-=1
    if attributeposition==-1:
        attributeposition=4
    print(AllAttributes[attributeposition][nameposition])

def DisplayAttributeRight():
    global attributeposition
    attributeposition+=1
    if attributeposition==5:
        attributeposition=0
    print(AllAttributes[attributeposition][nameposition])

def SpecialFeature():
    while True:
        option=UniqueFeatureMenu()
        if option==1:
            NameScrollUp()
        elif option==2:
            NameScrollDown()
        elif option==3:
            DisplayAttributeLeft()
        elif option==4:
            DisplayAttributeRight()
        elif option==0:
            break
        else:
            InvalidInput()
            
'''MAIN PROGRAM'''
while True:
    option=MainMenu()
    if option==1:
        ReadData()
    elif option==2:
        DisplayBMI()
    elif option==3:
        DisplayAverageBMI()
    elif option==4:
        TallestStudent()
    elif option==5:
        StudentsTallerThan()
    elif option==6:
        while True:
            option=AdditionalFeaturesMenu()
            if option==1:
                print("Function done in other program code")
                #SenseHatAverageBMI()
            elif option==2:
                BloodTypeGraph()
            elif option==3:
                BMIGraph()
            elif option==4:
                HeightGraph()
            elif option==5:
                SpecialFeature()
            elif option==0:
                break
            else:
                InvalidInput()
            print("\n\n\n")
    elif option==0:
        print("Thank you for using HealthCheck by Alan")
        break
    else:
        InvalidInput()
            
    print("\n\n\n")
