def binary_to_decimal(binary):
    binary1 = binary
    decimal = 0
    i = 0
    n = 0
    while(binary != 0):
        dec = binary % 10
        decimal = decimal + dec * pow(2,i)
        binary = binary // 10
        i += 1
    print(decimal)

if __name__ == '__main__':
    x = int(input("Enter Binary Value: "))
    binary_to_decimal(x)
    