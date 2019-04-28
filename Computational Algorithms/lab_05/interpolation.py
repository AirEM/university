from math import fabs


def point_selection(data, n, x):
    # n + 1 points

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


def get_table(data, n):
    m = [[None for _ in range(2 + n)] for _ in range(n + 1)]

    for i in range(n + 1):
        m[i][0] = data[i][0]
        m[i][1] = data[i][1]

    for col in range(n):
        for row in range(n - col):
            denominator = (m[row + 1 + col][0] - m[row][0])
            denominator = denominator if denominator != 0 else 1e-10
            m[row][col + 2] = (m[row + 1][col + 1] - m[row][col + 1]) / denominator

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

    data = [(data[0][i], data[1][i]) for i in range(len(data[0]))]

    data = point_selection(data, n, x)

    table = get_table(data, n)

    y = p(table, n, x)

    return y
