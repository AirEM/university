from PyQt5.QtCore import QPoint


class Figure:
    def __init__(self, painter, alg):
        self._painter = painter
        self._alg = alg

    def __alg_lib(self):
        pass

    def draw(self):
        pass


class Circle(Figure):
    def __init__(self, r, painter,  alg):
        super().__init__(painter, alg)

        self.__r = r

    def __alg_lib(self):
        self._painter.drawEllipse(QPoint(0, 0), self.__r, self.__r)

    def draw(self):
        self.__alg_lib()
        print("Circle : ", self.__r)


class Ellipse(Figure):
    def __init__(self, a, b, painter, alg):
        super().__init__(painter, alg)

        self.__a = a
        self.__b = b

    def __alg_lib(self):
        self._painter.drawEllipse(QPoint(0, 0), self.__a, self.__b)

    def draw(self):
        self.__alg_lib()
        print("Ellipse : ", self.__a, self.__b)

