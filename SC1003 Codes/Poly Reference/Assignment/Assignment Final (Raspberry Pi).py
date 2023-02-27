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
filereaded=0
import math
import time
from sense_hat import SenseHat
sense=SenseHat()
sense.clear()

'''FUNCTIONS'''
#Main Menu Function (Displays main menu)
def MainMenu ():
    print('MENU')
    print('='*4)
    if filereaded==0:
        print("Please select [1] first to allow computer to process file data")
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
        Weight.append(float(text[2]))
        Height.append(float(text[3]))
        bmi=(float(text[2])/(float(text[3])**2))
        BMI.append(round(bmi,2))
        BloodType.append(text[4].strip('\n'))
        counter+=1
    global averageBMI
    averageBMI=sum(BMI)/len(BMI)
    print("Number of records read:",counter)

#Display BMI Function
def DisplayBMI():
    print("Option 2: Display all student info with BMI\n")
    print("{:10s} \t {:18s} \t {:7s} \t {:7s} \t {:6s} \t {:10s}".format("NRIC No.","Name",\
                                                                         "Weight","Height",\
                                                                         "BMI","Blood Type"))
    print("{:12s} \t {:18s} \t {:7s} \t {:7s} \t {:6s} \t {:10s}".format("-"*12,"-"*18,'-'*7,'-'*7,\
                                                                         '-'*6,'-'*10))
    for i in range(len(NRICList)):
        print("{:10s} \t {:18s} \t {:5.2f} \t \t {:5.2f} \t \t {:6.2f} \t{:10s}".format(NRICList[i],\
                                                                                        Namelist[i],\
                                                                               Weight[i],Height[i],\
                                                                                BMI[i],BloodType[i]))

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
            print("\t{:s}\t-  {:.2f}m".format(Namelist[counter],i))

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

def SenseHatAverageBMI():
    sense.show_message("{:.2f}".format(averageBMI))

#Display Blood Type Graph
def BloodTypeGraph():
    sense.clear()
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
    print("Blood type statistics:")
    for i in range(len(BloodTypeGroup)):
        print("{:4s} {:s} {:2d}".format(BloodTypeGroup[i],"\t-\t",BloodTypeGraph[i]))
    y=0
    for i in BloodTypeGraph:
        for j in range (i):
            sense.set_pixel(j,y,255,0,0)
        y+=1

#Display BMI Graph
def BMIGraph():
    sense.clear()
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
    print("BMI Statistics:")
    print("{:30s}{:s}{:5d}".format("Risk of nutritional deficiency","\t-\t",BMIGraph[0]))
    print("{:30s}{:s}{:5d}".format("Low risk","\t-\t",BMIGraph[1]))
    print("{:30s}{:s}{:5d}".format("Moderate risk","\t-\t",BMIGraph[2]))
    print("{:30s}{:s}{:5d}".format("High risk","\t-\t",BMIGraph[3]))
    y=0
    for i in BMIGraph:
        for j in range (i):
            sense.set_pixel(j,y,0,255,0)
        y+=1

#Display Height Graph
def HeightGraph():
    sense.clear()
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
    print("Height statistics:")
    print("{:20s}{:s}{:5d}".format("<=1.50","\t-\t",HeightGraph[0]))
    print("{:20s}{:s}{:5d}".format("1.50~1.55","\t-\t",HeightGraph[1]))
    print("{:20s}{:s}{:5d}".format("1.55~1.60","\t-\t",HeightGraph[2]))
    print("{:20s}{:s}{:5d}".format("1.60~1.65","\t-\t",HeightGraph[3]))
    print("{:20s}{:s}{:5d}".format("1.65~1.70","\t-\t",HeightGraph[4]))
    print("{:20s}{:s}{:5d}".format("1.70~1.75","\t-\t",HeightGraph[5]))
    print("{:20s}{:s}{:5d}".format("1.75~1.80","\t-\t",HeightGraph[6]))
    print("{:20s}{:s}{:5d}".format(">=1.80","\t-\t",HeightGraph[7]))
    y=0
    for i in HeightGraph:
        for j in range (i):
            sense.set_pixel(j,y,0,0,255)
        y+=1

'''Special Feature'''
def UniqueFeatureMenu():
    print('\n\n\nUnique Features Menu')
    print('='*20)
    print('Refer to Raspberry Pi from here')
    print('[UP]    Next name')
    print('[DOWN]  Previous name')
    print('[LEFT]  Next attirbute')
    print('[RIGHT] Previous attribute')
    print('[PUSH]  Re-Display / Exit')
    print('Please wait, displaying...')
    time.sleep(1)
    sense.show_message('Current:'+ Namelist[nameposition]+' '\
                       ,text_colour=[51,153,255],scroll_speed=0.065)
    sense.show_message(str(AllAttributes[attributeposition][nameposition])\
                       ,text_colour=[0,255,204],scroll_speed=0.065)
    print('Move joystick in desired direction to continue')

def NameScrollUp():
    global nameposition
    nameposition=nameposition+1
    if nameposition==len(Namelist):
        nameposition=0

def NameScrollDown():
    global nameposition
    nameposition=nameposition-1
    if nameposition==-1:
        nameposition=len(Namelist)-1  

def DisplayAttributeLeft():
    global attributeposition
    attributeposition-=1
    if attributeposition==-1:
        attributeposition=4

def DisplayAttributeRight():
    global attributeposition
    attributeposition+=1
    if attributeposition==5:
        attributeposition=0

def PushButton():
    while True:
        print('\n\n\n[1] Re-display')
        print('[0] Exit')
        global option
        option=int(input("Enter your option:"))
        if option==1 or option==0:
            return(option)
        else:
            print("Please enter a valid option")
        

def SpecialFeature():
    from sense_hat import SenseHat
    from Stick import SenseStick
    
    sense = SenseHat()
    stick = SenseStick()
    sense.clear()

    d ={
        stick.KEY_UP: 'up',
        stick.KEY_DOWN: 'down',
        stick.KEY_LEFT: 'left',
        stick.KEY_RIGHT: 'right',
        stick.KEY_ENTER: 'push',
        }
    UniqueFeatureMenu()
    while True:
        for event in stick:
            if event.state == stick.STATE_PRESS:
                if d[event.key] == 'up':
                    print("[UP] selected")
                    NameScrollUp()

                elif d[event.key] == 'down':
                    print("[DOWN] selected")
                    NameScrollDown()

                elif d[event.key] == 'left':
                    print("[LEFT] selected")
                    DisplayAttributeLeft()

                elif d[event.key] == 'right':
                    print("[RIGHT] selected")
                    DisplayAttributeRight()

                elif d[event.key] == 'push':
                    print("[PUSH] selected")
                    PushButton()
                    if option==0:
                        break
                UniqueFeatureMenu()
        break

'''MAIN PROGRAM'''
while True:
    option=MainMenu()
    if option==1:
        ReadData()
        filereaded+=1
    elif option==2:
        if filereaded==0:
            print("Please select [1] first to allow computer to process file data")
        else:
            DisplayBMI()
    elif option==3:
        if filereaded==0:
            print("Please select [1] first to allow computer to process file data")
        else:
            DisplayAverageBMI()
    elif option==4:
        if filereaded==0:
            print("Please select [1] first to allow computer to process file data")
        else:
            TallestStudent()
    elif option==5:
        if filereaded==0:
            print("Please select [1] first to allow computer to process file data")
        else:
            StudentsTallerThan()
    elif option==6:
        if filereaded==0:
            print("Please select [1] first to allow computer to process file data")
        else:
            while True:
                option=AdditionalFeaturesMenu()
                if option==1:
                    SenseHatAverageBMI()
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
