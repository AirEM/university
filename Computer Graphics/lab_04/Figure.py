from math import sqrt, sin, cos, pi
from PyQt5.QtCore import QPoint


class Figure:
    def __init__(self, painter, alg):
        self._painter = painter
        self._alg = alg

    def __alg_canon(self):
        print(self.__alg_canon)

    def __alg_param(self):
        print(self.__alg_param)

    def __alg_brez(self):
        print(self.__alg_brez)

    def __alg_middle(self):
        print(self.__alg_middle)

    def __alg_lib(self):
        print(self.__alg_lib)

    def draw(self):
        print(self.draw)


class Circle(Figure):
    def __init__(self, radius, painter, alg):
        super().__init__(painter, alg)

        self.__radius = radius

    def __alg_canon(self):
        for x in range(0, self.__radius + 1, 1):
            y = round(sqrt(self.__radius ** 2 - x ** 2))
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

        for y in range(0, self.__radius + 1, 1):
            x = round(sqrt(self.__radius ** 2 - y ** 2))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

    def __alg_param(self):
        len_circle = round(pi * self.__radius / 2)  # длина четврети окружности

        for i in range(0, len_circle + 1, 1):
            x = round(self.__radius * cos(i / self.__radius))
            y = round(self.__radius * sin(i / self.__radius))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

    def __alg_brez(self):
        x = 0
        y = self.__radius
        d = 2 - 2 * self.__radius
        while y >= 0:
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            if d < 0:
                buf = 2 * d + 2 * y - 1
                x += 1

                if buf <= 0:
                    d = d + 2 * x + 1
                else:
                    y -= 1
                    d = d + 2 * x - 2 * y + 2

                continue

            if d > 0:
                buf = 2 * d - 2 * x - 1
                y -= 1

                if buf > 0:
                    d = d - 2 * y + 1
                else:
                    x += 1
                    d = d + 2 * x - 2 * y + 2

                continue

            if d == 0.0:
                x += 1
                y -= 1
                d = d + 2 * x - 2 * y + 2

    def __alg_middle(self):
        x = 0
        y = self.__radius
        p = 5 / 4 - self.__radius
        while True:
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, -y))
            self._painter.drawPoint(QPoint(x, y))

            self._painter.drawPoint(QPoint(-y, x))
            self._painter.drawPoint(QPoint(y, -x))
            self._painter.drawPoint(QPoint(-y, -x))
            self._painter.drawPoint(QPoint(y, x))

            x += 1

            if p < 0:
                p += 2 * x + 1
            else:
                p += 2 * x - 2 * y + 5
                y -= 1

            if x > y:
                break

    def __alg_lib(self):
        self._painter.drawEllipse(QPoint(0, 0), self.__radius, self.__radius)

    def draw(self):
        if self._alg == 0:
            self.__alg_brez()
        elif self._alg == 1:
            self.__alg_middle()
        elif self._alg == 2:
            self.__alg_param()
        elif self._alg == 3:
            self.__alg_canon()
        elif self._alg == 4:
            self.__alg_lib()


class Ellipse(Figure):
    def __init__(self, a, b, painter, alg):
        super().__init__(painter, alg)

        self.__a = a
        self.__b = b

    def __alg_canon(self):
        for x in range(0, self.__a + 1, 1):
            y = round(self.__b * sqrt(1.0 - x ** 2 / self.__a / self.__a))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

        for y in range(0, self.__b + 1, 1):
            x = round(self.__a * sqrt(1.0 - y ** 2 / self.__b / self.__b))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

    def __alg_param(self):
        m = max(self.__a, self.__b)
        len_circle = round(pi * m / 2)

        for i in range(0, len_circle + 1, 1):
            x = round(self.__a * cos(i / m))
            y = round(self.__b * sin(i / m))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

    def __alg_brez(self):
        x = 0  # начальные значения
        y = self.__b
        a = self.__a ** 2
        d = round(self.__b * self.__b / 2 - a * self.__b * 2 + a / 2)
        b = self.__b ** 2
        while y >= 0:
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))
            if d < 0:  # пиксель лежит внутри эллипса
                buf = 2 * d + 2 * a * y - a
                x += 1
                if buf <= 0:  # горизотальный шаг
                    d = d + 2 * b * x + b
                else:  # диагональный шаг
                    y -= 1
                    d = d + 2 * b * x - 2 * a * y + a + b

                continue

            if d > 0:  # пиксель лежит вне эллипса
                buf = 2 * d - 2 * b * x - b
                y -= 1

                if buf > 0:  # вертикальный шаг
                    d = d - 2 * y * a + a
                else:  # диагональный шаг
                    x += 1
                    d = d + 2 * x * b - 2 * y * a + a + b

                continue

            if d == 0.0:  # пиксель лежит на окружности
                x += 1  # диагональный шаг
                y -= 1
                d = d + 2 * x * b - 2 * y * a + a + b

    def __alg_middle(self):
        x = 0  # начальные положения
        y = self.__b
        p = self.__b * self.__b - self.__a * self.__a * self.__b + 0.25 * self.__a * self.__a  # начальное значение параметра принятия решения в области tg<1
        while 2 * (self.__b ** 2) * x < 2 * self.__a * self.__a * y:  # пока тангенс угла наклона меньше 1
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            x += 1

            if p < 0:  # средняя точка внутри эллипса, ближе верхний пиксел, горизонтальный шаг
                p += 2 * self.__b * self.__b * x + self.__b * self.__b
            else:  # средняя точка вне эллипса, ближе диагональный пиксел, диагональный шаг
                y -= 1
                p += 2 * self.__b * self.__b * x - 2 * self.__a * self.__a * y + self.__b * self.__b

        p = self.__b * self.__b * (x + 0.5) * (x + 0.5) + self.__a * self.__a * (y - 1) * (y - 1) - self.__a * self.__a * self.__b * self.__b
        # начальное значение параметра принятия решения в области tg>1 в точке (х + 0.5, y - 1) полседнего положения

        while y >= 0:
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            y -= 1

            if p > 0:
                p -= 2 * self.__a * self.__a * y + self.__a * self.__a
            else:
                x += 1
                p += 2 * self.__b * self.__b * x - 2 * self.__a * self.__a * y + self.__a * self.__a

    def __alg_lib(self):
        self._painter.drawEllipse(QPoint(0, 0), self.__a, self.__b)

    def draw(self):
        if self._alg == 0:
            self.__alg_brez()
        elif self._alg == 1:
            self.__alg_middle()
        elif self._alg == 2:
            self.__alg_param()
        elif self._alg == 3:
            self.__alg_canon()
        elif self._alg == 4:
            self.__alg_lib()

