def main():
    numbers = []
    with open("array_from_python.txt", "r") as file:
        for number in file:
            numbers.append(int(number.strip()))

        for number in numbers:
            print(number * 10)

main()

