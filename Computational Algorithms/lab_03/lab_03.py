from lab_01 import *


def f(x, y):
    return x**2 + y**2


def print_data(data):

    for item in data:
        print(" ".join("{:>3.3f}".format(el) if el is not None else " y \ x" for el in item))

    '''
    for i in range(len(data)):

        for j in range(len(data[i])):
            if data[i][j] is None:
                print(" y \ x", end='')
            else:
                print("{:>3.3f}".format(data[i][j]), end=' ')

            if j == 0:
                print("|", end='')

        if i == 0:
            print()
            for j in range(len(data[i]) * 6):
                print("_", end='')

        print()
    '''


def data_input():
    x = list()
    y = list()

    left, right, step = map(float, input('Введите для X "Левая граница Правая граница Шаг":').split())

    while left < right + step / 2:
        x.append(left)
        left += step

    left, right, step = map(float, input('Введите для Y "Левая граница Правая граница Шаг":').split())

    while left < right + step / 2:
        y.append(left)
        left += step

    data = [[None for _ in range(len(x) + 1)] for __ in range(len(y) + 1)]

    for i in range(len(x)):
        data[0][i + 1] = x[i]

    for i in range(len(y)):
        data[i + 1][0] = y[i]

    for i in range(len(y)):
        for j in range(len(x)):
            data[i+1][j+1] = f(x[j], y[i])

    return data


# work with data


def point_selection_y(data, n, x):
    # n + 1 points

    data = data[1:]
    d_len = len(data)
    new_data = list()

    if d_len < n + 1:
        return None


    left = -1
    index = 0
    right = 1
    mins = fabs(x - data[0][0])
    count = 0

    for i in range(d_len):

        if fabs(x - data[i][0]) < mins:
            left = i - 1
            index = i
            right = i + 1
            mins = fabs(x - data[i][0])

    new_data.append(data[index])

    while left != -1 or right != d_len:
        if right != d_len:
            new_data.append(data[right])
            right += 1
            count += 1

        if count == n:
            break

        if left != -1:
            new_data.insert(0, data[left])
            left -= 1
            count += 1

        if count == n:
            break

    return sorted(new_data)

# interpolation


def bilinear_interpolation(data, nx, ny, x, y):

    data_y = point_selection_y(data, ny, y)

    new_zx = list()

    for item in data_y:
        interpolation_data = [(data[0][i], item[i]) for i in range(1, len(data[0]))]

        res = interpolation(interpolation_data, nx, x)

        new_zx.append((item[0], res))

    res = interpolation(new_zx, ny, y)

    print(res)

    return res

# main


def main():

    data = data_input()

    print_data(data)

    nx = int(input('Введите Nx : '))
    ny = int(input('Введите Ny : '))

    x = float(input('Введите X : '))
    y = float(input('Введите Y : '))

    bilinear_interpolation(data, nx, ny, x, y)


if __name__ == '__main__':
    main()
