import re

a = input()
point = 0
letter = 0

for i in range (0, len(a)):
    if  re.match(r'[A-Z]|[a-z]', a[i]):
        letter += 1 
    elif(a[i] == "."):
        point += 1


if(letter != 0):
    print("a is not a number")
else:
    if (point == 0):
        print("a is a int")
    else:
        print("a is a float")