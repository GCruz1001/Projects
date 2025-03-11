a = int(input("Enter age of child: "))
b = int(input("Enter age of child: "))
c = int(input("Enter age of child: "))
def oldest_kid():
    if a > b and a > c:
        major = a
    elif b > a and b > c:
        major = b
    else:
        major = c
    return major
print("The oldest child is: ", oldest_kid())


x = int(input("How many kids do you have? "))
y = 0
while y < x:
    z = int(input("How old is the child? "))
    y = y + 1


print("out of your", y, "kids, the oldest is")
