from sense_hat import SenseHat
sense=SenseHat()

organization=input("Input organization:")
member=[]
name=0
while name!="":
    name=input("Input name(return/enter to end):")
    member.append(name)
sense.show_message("ICT welcomes guests from {:s}".format(organization),text_colour=[255,0,0])
for i in member:
    sense.show_message(i,text_colour=[0,0,255])
    
    
    
    
