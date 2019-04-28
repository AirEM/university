from methods import integral, main_root
from N import N


def T(z):
    return T0 + (Tw - T0) * pow(z, m)


def Nt(z, P):
    if z == 0:
        return 0
    return N(T(z), P, v, x) * z

if __name__ == '__main__':

    T0 = 5860 #float(input("Введите T0 : "))
    Tw = 5860 # float(input("Введите Tw : "))
    P0 = 0.5 # float(input("Введите P0 : "))
    m = 1 # int(input("Введите m : "))

    x = [None, 3, -1, -20, -20, -20]
    v = -1

    Tn = 293

    def F(P):

        return 7243 * P0 / Tn - 2 * integral(lambda z: N(T(z), P, v, x) * z, 0, 1, 20)


    result = main_root(lambda z: F(z), 0, 20)

    print("result : ", result)
