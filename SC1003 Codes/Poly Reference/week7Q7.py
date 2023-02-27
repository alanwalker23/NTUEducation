decision=print("Budget calculator")
budget=float(input("How much do you have budgeted for a week?"))
while decision!= "done":
    expense=float(input("Key in your expense:"))
    budget -= expense
    decision=input("Press enter to key in more expenses or Type 'done' to end calculation:")
print(budget)
    
