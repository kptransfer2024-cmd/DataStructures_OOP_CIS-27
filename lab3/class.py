import random


class studentIDList:
    def __init__(self):
        self.numbers = []

        for i in range(1000):
            random_number = random.randint(1, 1000)
            self.numbers.append(random_number)

    def show_numbers(self):
        for number in self.numbers:
            print(number)


def main():
    student_list = studentIDList()
    student_list.show_numbers()


if __name__ == "__main__":
    main()