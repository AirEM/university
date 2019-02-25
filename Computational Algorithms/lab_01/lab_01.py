from math import fabs


def print_mtx(m):
    for i in m:
        for j in i:
            if j is not None:
                print("{:.3f}".format(j), end=' ')
        print()


def data_input():
    data = list()

    left, right, step = map(float, input('Введите "Левая граница Правая граница Шаг":').split())

    while left < right + step / 2:
        data.append((left, f(left)))
        left += step

    return data


def f(x):
    return x * x


def point_selection(data, n, x):
    # n + 1 points

    d_len = len(data)
    new_data = list()

    if x < data[0][0]:
        new_data = [(data[i][0], data[i][1]) for i in range(n + 1)]
    elif data[d_len - 1][0] < x:
        new_data = [(data[i][0], data[i][1]) for i in range(d_len - (n + 1), d_len)]
    else:
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

        while left != -1 and right != d_len:
            if right != d_len:
                new_data.append(data[right])
                right += 1
                count += 1

            if count == n:
                break

            if left != -1:
                new_data.append(data[left])
                left -= 1
                count += 1

            if count == n:
                break

        new_data = sorted(new_data)

    return new_data


# interpolation


def get_table(data, n):
    m = [[None for j in range(2 + n)] for i in range(n + 1)]

    for i in range(n + 1):
        m[i][0] = data[i][0]
        m[i][1] = data[i][1]

    for col in range(n):
        for row in range(n - col):
            m[row][col + 2] = (m[row + 1][col + 1] - m[row][col + 1]) / (m[row + 1 + col][0] - m[row][0])

    return m


def p(table, n, x):
    # Pn(x) = f(x0) + (x − x0) · f(x0, x1) + (x − x0)(x − x1) · f(x0, x1, x2) + ...
    # +(x − x0)(x − x1) ...(x − xn−1) · f(x0, x1, ..., xn).

    mult = 1
    Pn = table[0][1]

    for i in range(n):
        mult *= (x - table[i][0])

        Pn += mult * table[0][2 + i]

    return Pn


def interpolation(data, n, x):
    print(data)
    print(n)
    print(x)

    table = get_table(data, n)
    print_mtx(table)

    y = p(table, n, x)

    return y


# main


def main():
    '''
    # f = open('input.txt', 'r')
    # data = []
    # for line in f:
        # data.append((float(line.split()[0]), float(line.split()[1])))
    # f.close()
    '''

    data = data_input()
    n = int(input("Введите степень многочлена: "))
    x = float(input("Введите x: "))

    data = point_selection(data, n, x)

    y = interpolation(data, n, x)

    print("f({:.3f}) = {:.3f}".format(x, y))


if __name__ == '__main__':
    main()
