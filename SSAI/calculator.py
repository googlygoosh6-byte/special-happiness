from os import system

def add(a, b):
    return a + b
def subtract(a, b):
    return a - b
def multiply(a, b):
    return a * b
def divide(a, b):
    if b == 0:
        system("echo 'Error: Division by zero is undefined.'")
        return None
    return a / b

def main():
    system("clear")
    print("Simple Calculator")
    print("------------------------------")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("------------------------------")
    print("")
    option=input("Select operation: ")
    menu(option)

def menu(option):
    match option:
        case "1":
            a = float(input("Enter first number: "))
            b = float(input("Enter second number: "))
            print(f"{a} + {b} = {add(a, b)}")
        case "2":
            a = float(input("Enter first number: "))
            b = float(input("Enter second number: "))
            print(f"{a} - {b} = {subtract(a, b)}")
        case "3":
            a = float(input("Enter first number: "))
            b = float(input("Enter second number: ")) 
            print(f"{a} * {b} = {multiply(a, b)}")
        case "4":
            a = float(input("Enter first number: "))
            b = float(input("Enter second number: "))
            result = divide(a, b)
            if result is not None:
                print(f"{a} / {b} = {result}")
        case _:
            print("Invalid option selected.")

main()