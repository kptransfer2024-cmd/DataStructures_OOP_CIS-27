import random

def main():
    numbers = []

    for i in range(1000):
        number = random.randint(1, 1000)
        numbers.append(number)

    for i in range(1000):
        print(numbers[i])

    file = open("array_from_python.txt", "w")

    for i in range(1000):
        file.write(str(numbers[i]) + "\n")
    file.close()

main()
