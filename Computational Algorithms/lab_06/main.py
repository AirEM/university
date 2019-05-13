from funcs import *


def f(x):
    return x / (1 + 2*x)


def print_data(data):
    for i in range(len(data[0])):
        for j in range(len(data)):
            if data[j][i] is None:
                print("{:^6s}".format('None'), end=' ')
            else:
                print("{:^3.3f}".format(data[j][i]), end=' ')
        print()


def make_file():
    file = open('input.txt', 'w')

    for i in range(1, 11):
        print(i, f(i), file=file)

    file.close()

def data_input():
    file = open('input.txt', 'r')

    x = list()
    y = list()

    for line in file:
        item_x, item_y = map(float, line.split())
        x.append(item_x)
        y.append(item_y)

    file.close()

    return [x, y]

# main


def main():

    make_file()

    data = data_input()

    print_data(data)

    derivatives = [[None for _ in range(len(data[1]))] for _ in range(5)]

    get_first(data, derivatives)

    get_second(data, derivatives)

    get_third(data, derivatives)

    get_fourth(data, derivatives)

    get_fifth(data, derivatives)

    print_data(derivatives)


if __name__ == '__main__':
    main()
