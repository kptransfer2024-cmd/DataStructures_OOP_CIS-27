import random

class Common_Alg:

    def __init__(self):
        self.numbers = []
        for i in range(1000):
            self.numbers.append(random.randint(1, 1000))


    def show_numbers(self):
        print("The array of 1000 random integers is: ")
        for i in range(1000):
            print(self.numbers[i])


    def sumAllValues(self):
        sum = 0
        for i in range(1000):
            sum += self.numbers[i]
        print("Sum of all values:", sum)


    def showOddNumbers(self):
        for i in range(1000):
            if self.numbers[i] % 2 == 1:
                print(self.numbers[i])


    def showEvenNumbers(self):
        for i in range(1000):
            if self.numbers[i] % 2 == 0:
                print(self. numbers[i])


    def linearSearch(self, key):
        is_found = False
        for i in range(1000):
            if self.numbers[i] == key:
                print(f"Value {key} is found at index {i}")
                is_found = True
        if not is_found:
            print(f"Value {key} not found in the array.")


    def middleValue(self):
        mid_i = 1000 // 2
        print("The values in the middle are:")
        print(self.numbers[mid_i - 1], "and", self. numbers[mid_i])


    def firstValue(self):
        first_i = 0
        print("The first value is:", self.numbers[first_i])


    def lastValue(self):
        last_i = 1000 - 1
        print("The last value is:", self.numbers[last_i])


    def highestValue(self):
        highest = self.numbers[0]
        location = 0
        for i in range(1, 1000):
            if self.numbers[i] > highest:
                highest = self. numbers[i]
                location = i
        print("The highest value is:", highest)
        print("The index of the highest value is:", location)


    def lowestValue(self):
        lowest = self.numbers[0]
        location = 0
        for i in range(1, 1000):
            if self.numbers[i] < lowest:
                lowest = self.numbers[i]
                location = i
        print("The lowest value is:", lowest)
        print("The index of the lowest value is:", location)


    def bubbleSort(self):
        sorted_numbers = self.numbers.copy()
        for i in range(1000 - 1):
            for j in range(1000 - i - 1):
                if sorted_numbers[j] > sorted_numbers[j + 1]:
                    temp = sorted_numbers[j]
                    sorted_numbers[j] = sorted_numbers[j + 1]
                    sorted_numbers[j + 1] = temp

        print("The sorted array is: [")
        for i in range(1000 - 1):
            print(sorted_numbers[i])
        print(f"{sorted_numbers[1000 - 1]}] ")


    def meanAverage(self):
        sum = 0
        for i in range(1000):
            sum += self.numbers[i]
        mean = sum / 1000
        print("The mean average is:", mean)


def main():
    print("-------- ---------------- ---------")
    print("-------- Common Algorithm ---------")
    print("-------- ---------------- ---------")
    print()

    choice = input("Do you want to generate a random array of 1000 integers between 1 - 1000? (y/n): ")
    print()

    if choice.lower() in ("n", "no"):
        print("You chose not to generate a random array.")
        print("See you next time!")

    elif choice.lower() in ("y", "yes"):
        common_alg_1 = Common_Alg()
        print("A array of 1000 random integers generated.")
        print()

        print("Please select an option from the menu below:")
        print("1. Show all numbers")
        print("2. Sum of all values")
        print("3. Show odd numbers")
        print("4. Show even numbers")
        print("5. Linear search for a value")
        print("6. Show middle value")
        print("7. Show first value")
        print("8. Show last value")
        print("9. Show highest value")
        print("10. Show lowest value")
        print("11. Sort the array using bubble sort")
        print("12. Calculate mean average")
        print()

        option = int(input("Enter 1-12: "))

        if option == 1:
            common_alg_1.show_numbers()
        elif option == 2:
            common_alg_1.sumAllValues()
        elif option == 3:
            common_alg_1.showOddNumbers()
        elif option == 4:
            common_alg_1.showEvenNumbers()
        elif option == 5:
            key = int(input("Enter a value to search for: "))
            common_alg_1.linearSearch(key)
        elif option == 6:
            common_alg_1.middleValue()
        elif option == 7:
            common_alg_1.firstValue()
        elif option == 8:
            common_alg_1.lastValue()
        elif option == 9:
            common_alg_1.highestValue()
        elif option == 10:
            common_alg_1.lowestValue()
        elif option == 11:
            common_alg_1.bubbleSort()
        elif option == 12:
            common_alg_1.meanAverage()
        else:
            print("Please enter a number between 1 and 12.")

    else:
        print("Exiting the program.")


main()
