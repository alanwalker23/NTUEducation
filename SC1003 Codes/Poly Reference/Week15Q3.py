i=1
def arithmeticMean(x,*values):
    sum=x
    for i in values:
        sum+=i
    average=sum/(len(values)+1)
    return(average)
mean=arithmeticMean(1,2,3,4,5,6,7,8,9,10)
print(mean)
