
def get_first(data, derivatives):

    for i in range(len(data[1]) - 1):

        h = data[0][i+1] - data[0][i]

        derivatives[0][i] = (data[1][i+1] - data[1][i]) / h


def get_second(data, derivatives):

    for i in range(1, len(data[1]) - 1):

        h = data[0][i + 1] - data[0][i - 1]

        derivatives[1][i] = (data[1][i + 1] - data[1][i - 1]) / h


def get_third(data, derivatives):

    # первая точка
    h = data[0][2] - data[0][0]
    derivatives[2][0] = (-3*data[1][0] + 4*data[1][1] - data[1][2]) / h

    # последняя точка
    len_data = len(data[1]) - 1
    h = data[0][len_data] - data[0][len_data - 2]
    derivatives[2][len_data] = (data[1][len_data - 2] - 4*data[1][len_data - 1] + 3*data[1][len_data]) / h


def get_fourth(data, derivatives):

    def psi(ind, k):
        h = data[0][ind + k] - data[0][ind]
        return (data[1][ind + k] - data[1][ind]) / h

    h = 1
    q = 2
    p = 1

    for i in range(len(data[1]) - 2):

        derivatives[3][i] = psi(i, h) + (psi(i, h) - psi(i, q*h)) / (q**p - 1)


def get_fifth(data, derivatives):

    # новыцй X
    eta = [1 / data[0][i] for i in range(len(data[0]))]

    # новый Y
    ksi = [1 / data[1][i] for i in range(len(data[1]))]

    new_derivatives = [None] * len(ksi)

    for i in range(len(ksi) - 1):
        h = eta[i + 1] - eta[i]
        new_derivatives[i] = (ksi[i + 1] - ksi[i]) / h

    for i in range(len(data[1]) - 1):
        derivatives[4][i] = new_derivatives[i] * (data[1][i] / data[0][i])
