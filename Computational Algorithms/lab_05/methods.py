from math import fabs

"""
integral :
Нахождение интеграла меодом трапеций.

root :
Нахождение корня методом половинного деления

eps : 
Точность
"""


eps = 1e-10
max_count = 100


def integral(f, start, end, n):

    if fabs(end - start) < eps:
        return (end - start) / 2

    h = (end - start) / n

    f1 = f(start)
    f2 = f(end)

    res = f1 + f2

    current = start + h

    for i in range(1, n):
        res += 2 * f(current)

        current += h

    res *= h / 2

    return res


def root(f, start, end):

    count = 0

    middle = (end + start) / 2

    while fabs(end - start) > eps and count < max_count:

        if end - start < 2 * eps:
            middle = (start + end) / 2
            break

        if f(start) * f(middle) < 0:
            end = middle
        else:
            start = middle

        middle = (end + start) / 2
        count += 1

    return middle

def main_root(f, start, end):

    count = 0

    middle = (end + start) / 2

    while fabs(f(middle)) > eps and count < max_count:

        print("[{}, {}]".format(start, end))

        if end - start < 2 * eps:
            middle = (start + end) / 2
            break

        if f(start) * f(middle) < 0:
            end = middle
        else:
            start = middle

        middle = (end + start) / 2
        count += 1

    return middle
