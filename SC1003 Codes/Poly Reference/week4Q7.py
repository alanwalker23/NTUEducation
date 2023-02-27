print("•First 100 pages: 3 cents per page\n\
•Next 200 pages: 2 cents per page\n\
•Over 300 pages: 1 cent per page\n")
a=int(input("How many pages are you printing?"))
if a<=100:
    print("The total cost is $",a*0.03)
elif a<=300:
    print("The total cost is $",(a-100)*0.02+(100*0.03))
else:
    print("The total cost is $",(100*0.03)+(200*0.02)+(a-300)*0.01)
