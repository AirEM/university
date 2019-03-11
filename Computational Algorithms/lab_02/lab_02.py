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
        data.append((left, f(left)))
        left += step

    return data


# interpolation


def interpolation(data, x, n):

    # h

    h = [None] * n
    for i in range(1, n):
        h[i] = round(data[i][0] - data[i-1][0], eps)

    # A B D F

    A = [None] * n
    B = [None] * n
    D = [None] * n
    F = [None] * n

    for i in range(2, n):
        A[i] = h[i-1]
        B[i] = -2 * (h[i-1] + h[i])
        D[i] = h[i]
        F[i] = -3 * ((data[i][1] - data[i-1][1]) / h[i] - (data[i-1][1] - data[i-2][1]) / h[i-1])

    # ksi eta

    ksi = [None] * (n + 1)
    eta = [None] * (n + 1)

    ksi[2] = 0
    eta[2] = 0

    for i in range(2, n):
        ksi[i + 1] = D[i] / (B[i] - A[i] * ksi[i])
        eta[i + 1] = (A[i] * eta[i] + F[i]) / (B[i] - A[i]*ksi[i])

    # U, она же c

    U = [None] * (n + 1)
    U[n] = 0
    U[1] = 0

    for i in range(n, 2, -1):
        U[i-1] = ksi[i] * U[i] + eta[i]
    #for i in range(n - 1 - 1, 1, -1):
        #U[i] = ksi[i + 1] * U[i + 1] + eta[i + 1]

    # Обратные преобразования

    a = [0] * n
    b = [0] * n
    c = [0] * n
    d = [0] * n

    for i in range(1, n):
        a[i] = data[i-1][1]
        b[i] = ((data[i][1] - data[i-1][1]) / h[i]) - (h[i] * (U[i + 1] + 2 * U[i]) / 3)
        c[i] = U[i]
        d[i] = (U[i+1] - U[i]) / (3 * h[i])

    # y

    k = -1
    for i in range(1, n):
        if data[i-1][0] <= x < data[i][0]:
            k = i
            break

    y = a[k] + b[k]*(x - data[k-1][0]) + c[k]*pow((x - data[k-1][0]), 2) + d[k]*pow((x - data[k-1][0]), 3)

    return y


# main


def main():

    data = data_input()

    print_data(data)

    x = float(input("Введите x: "))

    if data[0][0] <= x <= data[len(data) - 1][0]:

        y = interpolation(data, x, len(data))

        print("f({:.3f}) = {:.3f}".format(x, y))

    else:
        print("Невозможно посчитать, Х не попадает в заданный промежуток.")


if __name__ == '__main__':
    main()
