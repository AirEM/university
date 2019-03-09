from math import fabs

eps = 5

def f(x):
    return x**2


def print_data(data):
    for i in data:
        print("x = {:.3f}; f(x) = {:.3f}".format(i[0], i[1]))


def data_input():
    data = list()

    left, right, step = map(float, input('Введите "Левая граница Правая граница Шаг":').split())

    while left < right + step / 2:
        data.append((round(left, eps), round(f(left), eps)))
        left += step

    return data


# interpolation


def interpolation(data, x, n):

    # h

    h = [0] * n
    for i in range(1, n):
        h[i] = round(data[i][0] - data[i-1][0], eps)

    print("h = ", h)

    # A B D F

    A = [0] * n
    B = [0] * n
    D = [0] * n
    F = [0] * n

    for i in range(2, n):
        A[i] = h[i-1]
        B[i] = -2 * (h[i-1] + h[i])
        D[i] = h[i]
        F[i] = -3 * ((data[i][1] - data[i-1][1]) / h[i] - (data[i-1][1] - data[i-2][1]) / h[i-1])

    print("A = ", A)
    print("B = ", B)
    print("D = ", D)
    print("F = ", F)

    # ksi eta

    ksi = [0] * n
    eta = [0] * n

    for i in range(2, n - 1):
        ksi[i + 1] = D[i] / (B[i] - A[i] * ksi[i])
        eta[i + 1] = (A[i] * eta[i] + F[i]) / (B[i] - A[i]*ksi[i])

    print("ksi = ", ksi)
    print("eta = ", eta)

    # U, она же c

    U = [0] * (n + 1)

    for i in range(2, n):
        U[i-1] = ksi[i] * U[i] + eta[i]

    # Обратные преобразования

    a = [0] * n
    b = [0] * n
    c = [0] * n
    d = [0] * n

    for i in range(1, n):
        a[i] = data[i-1][1]
        b[i] = (data[i][1] - data[i-1][1]) / h[i] - h[i] / 3 * (U[i + 1] - 2 * U[i])
        c[i] = U[i]
        d[i] = (U[i+1] - U[i]) / (3 * h[i])

    # print

    print("============================")
    for i in range(1, n):
        print("{:.5f} {:.5f} {:.5f} {:.5f}".format(a[i], b[i], c[i], d[i]))
    print("============================")

    # y

    k = -1
    for i in range(1, n):
        if data[i-1][0] <= x <= data[i][0]:
            k = i
            break

    y = a[k] + b[k]*(x - data[k-1][0]) + c[k]*pow((x - data[k-1][0]), 2) + d[k]*pow( (x - data[k-1][0]), 3)

    return y


# main


def main():

    data = data_input() # [(1, 1.0002), (2, 1.0341), (3, 0.6), (4, 0.40105), (5, 0.1), (6, 0.23975) ]

    print_data(data)

    x = float(input("Введите x: "))

    if data[0][0] <= x <= data[len(data) - 1][0]:

        y = interpolation(data, x, len(data))

        print("f({:.3f}) = {:.3f}".format(x, y))

    else:
        print("Невозможно посчитать, Х не попадает в заданный промежуток.")


if __name__ == '__main__':
    main()
