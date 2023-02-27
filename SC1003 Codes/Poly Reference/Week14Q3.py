def calcGST (x,y):
    answer=x*(y/100)
    return(answer)
glist=[5,7,9]
totalprice=int(input("Enter the total price:"))
for i in range(int(len(glist))):
    gst=calcGST(totalprice,glist[i])
    print("GST for the ${:.1f} based on {:d}% GST is ${:.1f}".format(totalprice,glist[i],gst))
    
