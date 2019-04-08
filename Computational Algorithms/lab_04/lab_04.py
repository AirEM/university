import numpy as np
import matplotlib.pyplot as plt


def f(x, argv):
    item = 1
    res = 0

    for i in argv:
        res += i * item
        item *= x

    return res


def print_data(data):
    for i in range(len(data[0])):
        print("{:3.3f} {:3.3f} {:3.3f}".format(data[0][i], data[1][i], data[2][i]))


def data_input():
    f = open('input.txt', 'r')

    x = list()
    y = list()
    p = list()

    for line in f:
        item_x, item_y, item_p = map(float, line.split())
        x.append(item_x)
        y.append(item_y)
        p.append(item_p)

    f.close()

    return x, y, p


def sum_px(p, x, step):
    s = 0
    for i in range(len(x)):
        s += p[i] * (x[i] ** step)

    return s


def sum_pxy(p, x, y, step):
    s = 0
    for i in range(len(x)):
        s += p[i] * (x[i] ** step) * y[i]

    return s

# main


def main():
    x, y, p = data_input()

    print_data((x, y, p))

    n = int(input("Введите степень : "))

    mtx = [[None for _ in range(n + 1)] for _ in range(n +1 )]
    vtx = [None for _ in range(n+1)]


    # print(mtx)

    for i in range(n + 1):
        for j in range(n + 1):
            mtx[i][j] = sum_px(p, x, i + j)

    for i in range(n + 1):
        vtx[i] = sum_pxy(p, x, y, i)

    res = np.linalg.solve(mtx, vtx)

    plot_x = np.arange(x[0], x[len(x) - 1] + 0.1/2, 0.1)
    plot_y = np.array([f(item, res) for item in plot_x])

    plt.title("Graph")

    for i in range(len(x)):
        plt.plot(x[i], y[i], color='green', marker='o', markersize=5)

    # Plot the points using matplotlib
    plt.plot(plot_x, plot_y)
    plt.show()


if __name__ == '__main__':
    main()
