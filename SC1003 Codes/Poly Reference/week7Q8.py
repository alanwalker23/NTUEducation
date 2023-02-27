while True:
    total = 0
    nric = input("Please input the numbers in your NRIC:")
    if len(nric)==7:
        a=nric[0]
        total+= int(a)*2
        b=nric[1]
        total+= int(b)*7
        c=nric[2]
        total+= int(c)*6
        d=nric[3]
        total+= int(d)*5
        e=nric[4]
        total+= int(e)*4
        f=nric[5]
        total+= int(f)*3
        g=nric[6]
        total+= int(g)*2
        checker =11-total%11
        if checker==11:
            nric+="J"
        elif checker==10:
            nric+="Z"
        elif checker==9:
            nric+="I"
        elif checker==8:
            nric+="H"
        elif checker==7:
            nric+="G"
        elif checker==6:
            nric+="F"
        elif checker==5:
            nric+="E"
        elif checker==4:
            nric+="D"
        elif checker==3:
            nric+="C"
        elif checker==2:
            nric+="B"
        else:
            nric+="A"
        print("Your NRIC is S{}".format(nric))
    else:
        print("Please input a valid NRIC. [7 digits required]\n\n\n")
            
