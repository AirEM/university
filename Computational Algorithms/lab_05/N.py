from math import exp, log, fabs, pow
from methods import root, eps
from interpolation import interpolation
import numpy as np
import time

gamma_begin = 0
gamma_end = 3

E = [None, 12.13, 20.98, 31.00, 45.00]
z = [None, 0, 1, 2, 3, 4]
T_array = [None, 2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000, 22000, 24000, 26000]
Q = [None,
     [None, 1.0000, 1.0000, 1.0000, 1.0001, 1.0025, 1.0198, 1.0895, 1.2827, 1.6973, 2.4616, 3.6552, 5.3749, 7.6838],
     [None, 4.0000, 4.0000, 4.1598, 4.3006, 4.4392, 4.5661, 4.6817, 4.7923, 4.9099, 5.0511, 5.2354, 5.4841, 5.8181],
     [None, 5.5000, 5.5000, 5.5116, 5.9790, 6.4749, 6.9590, 7.4145, 7.8370, 8.2289, 8.5970, 8.9509, 9.3018, 9.6621],
     [None, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0],
     [None, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0]
     ]
power = 4


def get_alfa(gamma, T):

    res_alfa = 0.285 * pow(10, -11) * pow(gamma * T, 3)

    return res_alfa


def g(gam, T, v, x):

    s = 0
    res = 5.87 * (10 ** 10) / (T ** 3)

    for j in range(1, 5 + 1):
        s += (exp(x[j]) * pow(z[j], 2)) / (1 + pow(z[j], 2) * gam / 2)

    s += exp(v) / (1 + gam / 2)

    res *= s

    return gam ** 2 - res


def get_gamma(T, v, x):

    res_gamma = root(lambda z: g(z, T, v, x), gamma_begin, gamma_end)

    return res_gamma


def get_deltaE(gamma, T):
    dE = [None]

    for i in range(1, 4 + 1):
        res = 8.61 * pow(10, -5) * T * log(
            ((1 + (z[i + 1] ** 2) * gamma / 2) * (1 + gamma / 2)) / (1 + (z[i] ** 2) * gamma / 2))

        dE.append(res)

    return dE


def get_k(T, dE):
    K = [None]

    for i in range(1, 4 + 1):
        Qi1 = interpolation([T_array[1:], Q[i + 1][1:]], power, T)
        Qi = interpolation([T_array[1:], Q[i][1:]], power, T)

        res = 2 * 2.415 * pow(10, -3) * (Qi1 / Qi) * pow(T, 3 / 2) * exp(-(E[i] - dE[i]) * 11603 / T)
        K.append(res)

    return K


def N(T, P, v, x):
    x = [None, 3, -1, -20, -20, -20]
    v = -1

    # главная чать
    err_count = 0
    flag = True

    time_start = time.time()

    while err_count < 1000 and flag:
        err_count += 1

        # нахождение гамма(Г~)
        gamma = get_gamma(T, v, x)

        # нахождение alfa
        alfa = get_alfa(gamma, T)

        # Нахождение ΔE
        dE = get_deltaE(gamma, T)

        # Нахождение K
        K = get_k(T, dE)

        mtx = [[1, -1, 1, 0, 0, 0],
               [1, 0, -1, 1, 0, 0],
               [1, 0, 0, -1, 1, 0],
               [1, 0, 0, 0, -1, 1],
               [exp(v), 0, -z[2] * exp(x[2]), -z[3] * exp(x[3]), -z[4] * exp(x[4]), -z[5] * exp(x[5])],
               [-exp(v), -exp(x[1]), -exp(x[2]), -exp(x[3]), -exp(x[4]), -exp(x[5])]
               ]

        vtr = [log(K[1]) - v - x[2] + x[1],
               log(K[2]) - v - x[3] + x[2],
               log(K[3]) - v - x[4] + x[3],
               log(K[4]) - v - x[5] + x[4],
               -exp(v) + z[2] * exp(x[2]) + z[3] * exp(x[3]) + z[4] * exp(x[4]) + z[5] * exp(x[5]),
               exp(v) + exp(x[1]) + exp(x[2]) + exp(x[3]) + exp(x[4]) + exp(x[5]) - alfa - P * 7243 / T
               ]

        dv, dx1, dx2, dx3, dx4, dx5 = np.linalg.solve(mtx, vtr)

        test_list = list()
        test_list.append(v)
        test_list.extend(x[1:])

        if fabs(dv / v) > eps or fabs(dx1 / x[1]) > eps or \
                fabs(dx2 / x[2]) > eps or fabs(dx3 / x[3]) > eps or\
                fabs(dx4 / x[4]) > eps or fabs(dx5 / x[5]) > eps:

            v += dv

            x[1] += dx1

            x[2] += dx2

            x[3] += dx3

            x[4] += dx4

            x[5] += dx5
        else:
            flag = False

    time_end = time.time()

    #print("time = ", time_end - time_start)
    #print(err_count)

    result = exp(v) + exp(x[1]) + exp(x[2]) + exp(x[3]) + exp(x[4]) + exp(x[5])

    return result

def find_max_increment(X, d_X):
    max_inc = abs(d_X[0]/X[0])
    for i in range(1, len(X)):
        if abs(d_X[i]/X[i]) > max_inc:
            max_inc = abs(d_X[i]/X[i])
    return max_inc

def N_dima(T, P, v, x):
    count = 0

    while True:

        count += 1

        gamma = get_gamma(T, v, x)

        d_e = get_deltaE(gamma, T)

        K = get_k(T, d_e)

        lin_sys_left_side = [[1, -1, 1, 0, 0, 0],
               [1, 0, -1, 1, 0, 0],
               [1, 0, 0, -1, 1, 0],
               [1, 0, 0, 0, -1, 1],
               [exp(v), 0, -z[2] * exp(x[2]), -z[3] * exp(x[3]), -z[4] * exp(x[4]), -z[5] * exp(x[5])],
               [-exp(v), -exp(x[1]), -exp(x[2]), -exp(x[3]), -exp(x[4]), -exp(x[5])]
               ]

        alpha = get_alfa(gamma, T)

        lin_sys_right_side = [log(K[1]) - v - x[2] + x[1],
               log(K[2]) - v - x[3] + x[2],
               log(K[3]) - v - x[4] + x[3],
               log(K[4]) - v - x[5] + x[4],
               -exp(v) + z[2] * exp(x[2]) + z[3] * exp(x[3]) + z[4] * exp(x[4]) + z[5] * exp(x[5]),
               exp(v) + exp(x[1]) + exp(x[2]) + exp(x[3]) + exp(x[4]) + exp(x[5]) - alpha - P * 7243 / T
               ]

        #d_X = solve_lin_system_gauss(lin_sys_left_side, lin_sys_right_side)
        d_X = np.linalg.solve(lin_sys_left_side, lin_sys_right_side) # ~30% быстрее

        test_lst = list()
        test_lst.append(v)
        test_lst.extend(x[1:])

        if find_max_increment(test_lst, d_X) < eps:
            break

        for i in range(1, len(x)):
            x[i] += d_X[i]

    time_end = time()

    #print("time = ", time_end - time_start)

    return sum([exp(i) for i in x[1:]]) + exp(v)
