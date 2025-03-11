
#def decimal_to_binary(num):
#    if num >= 1:
#        decimal_to_binary(num // 2)
#        print(num % 2, end = ' ')

#if __name__ == '__main__':
 #   decimal_value = int(input("Enter Decimal Value: "))

#    decimal_to_binary(decimal_value)
def num_str(remainder):
    return str(remainder)
def conv_base2(quotient):
    bin = ' '
    while quotient != 0:
        new_q = quotient // 2
        remainder = quotient % 2
        bin = num_str(remainder) + bin
        quotient = new_q
    return bin
while True:
    num = int(input("Enter Decimal Number: "))
    bin_num = conv_base2(num)
    print("Binary of",num, "in base 10 is: ",bin_num)
    choice = input("Continue Converting? Y for Yes, N for No: ")
    if choice == 'N':
        break


