def print_mtx(m):
    for i in m:
        for j in i:
            if j is not None:
                print("{:.3f}".format(j), end=' ')
        print()


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


def main():

    f = open('input.txt', 'r')
    data = []
    for line in f:
        data.append((float(line.split()[0]), float(line.split()[1])))
    f.close()

    n = int(input("Введите степень многочлена: "))
    x = float(input("Введите x: "))

    y = interpolation(data, n, x)

    print("f({:.3f}) = {:.3f}".format(x, y))


main()


