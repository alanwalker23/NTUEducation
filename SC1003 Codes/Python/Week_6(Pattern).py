#Base case
def reverser(a_str):
    if len(a_str) == 1:
        return a_str
    else:
        new_str=reverser(a_str[1:]) + a_str[0]
        return new_str
#If you input abc, will return cba

def reverseAndRepeat(a_str,num):
    if len(a_str) == 1:
        return a_str *num
    else:
        new_str=reverseAndRepeat(a_str[1:],num) + a_str[0] *num
        return new_str

def OppositeCase(a_str):
    if a_str.isupper()==True:
        return a_str.lower()
    else:
        return a_str.upper()
        
def reverseAndOppositeCase(a_str):
    if len(a_str) == 1:
        return OppositeCase(a_str)
    else:
        new_str=reverseAndOppositeCase(a_str[1:]) + OppositeCase(a_str[0])
        return new_str

def symmetricString(a_str):
    if len(a_str) == 1:
        return a_str+a_str
    else:
        new_str=symmetricString(a_str[1:]) + a_str[0]
        return a_str[0]+new_str

def symmstring(a_str):
    return a_str+reverser(a_str)
#print(reverser("ABC"))
#print(reverseAndRepeat("ABC",3))
#print(reverseAndOppositeCase("AbCdE"))
print(symmetricString("ABCDE"))
print(symmstring("ABCDE"))