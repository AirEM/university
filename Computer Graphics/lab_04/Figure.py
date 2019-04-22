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
        #                                       cos(45)
        for x in range(0, round(self.__radius / sqrt(2)) + 1, 1):

            # рассматривается 1\8 окружности

            y = round(sqrt(self.__radius ** 2 - x ** 2))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            self._painter.drawPoint(QPoint(y, x))
            self._painter.drawPoint(QPoint(y, -x))
            self._painter.drawPoint(QPoint(-y, x))
            self._painter.drawPoint(QPoint(-y, -x))

    def __alg_param(self):

        # длина четврети окружности

        len_circle = round(pi * self.__radius / 2)

        for i in range(0, len_circle + 1, 1):

            x = round(self.__radius * cos(i / self.__radius))
            y = round(self.__radius * sin(i / self.__radius))

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

    def __alg_brez(self):

        # начало в точке (0, R)

        x = 0
        y = self.__radius

        # ошибка
        d = 2 - 2 * self.__radius

        # Для любой заданной точки на окружности при генерации по
        # часовой стрелке существует только три возможности выбрать
        # следующий пиксел, наилучшим образом приближающий
        # окружность: горизонтально вправо, по диагонали вниз
        # и вправо, вертикально вниз

        # mH = | (xi + 1)^2 + (yi)^2 - R^2 |

        # mD = | (xi + 1)^2 + (yi - 1)^2 - R^2 |

        # mV = | (xi)^2 + (yi - 1)^2 - R^2 |

        while y >= 0:
            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            # в окрестности точки(xi, yi) возможны только пять
            # типов пересечений окружности и сетки растра

            if d < 0:

                # диагональная точка(xi, + 1, уi - 1)
                # находится внутри реальной окружности

                # buf - расстояние до сл. пикселей
                buf = 2 * d + 2 * y - 1
                x += 1

                # следует выбрать либо
                # пиксел(xi, + 1, уi) mH,
                # либо
                # пиксел(xi, + 1, уi - 1) mD

                if buf <= 0:
                    d = d + 2 * x + 1
                else:
                    y -= 1
                    d = d + 2 * x - 2 * y + 2

                continue

            if d > 0:

                # диагональная точка (xi, + 1, уi -1)
                # находится вне окружности

                buf = 2 * d - 2 * x - 1
                y -= 1

                # должен быть выбран либо пиксел (xi + 1, уi -1)
                # либо (xi, уi -1).

                if buf > 0:
                    d = d - 2 * y + 1
                else:
                    x += 1
                    d = d + 2 * x - 2 * y + 2

                continue

            if d == 0.0:

                # пиксел(xi, уi - 1) лежит
                # на окружности

                # выбирается диагональный
                # пиксел(xi + 1, уi - 1)

                x += 1
                y -= 1
                d = d + 2 * x - 2 * y + 2

    def __alg_middle(self):
        
        # начальные значения
        x = 0
        y = self.__radius
        
        # найти исходное значение параметра принятия решения
        p = 1 - self.__radius

        while x <= y:
            
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
                
                # следующая точка на окружности (x+1, y)
                
                p += 2 * x + 1
            else:

                # следующая точка на окружности (x+1, y-1)
                y -= 1
                p += 2 * x - 2 * y + 1

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

        x = 0
        y = self.__b

        a2 = self.__a ** 2
        b2 = self.__b ** 2

        d = round((a2 + b2) / 2 - 2 * a2 * self.__b)

        while y >= 0:

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            if d < 0:  # пиксель лежит внутри эллипса
                buf = 2 * d + 2 * a2 * y - a2
                x += 1

                if buf < 0:  # горизотальный шаг
                    d += 2 * b2 * x + b2

                else:  # диагональный шаг
                    y -= 1
                    d += 2 * b2 * x - 2 * a2 * y + a2 + b2

            elif d > 0:  # пиксель лежит вне эллипса
                buf = 2 * d - 2 * b2 * x - b2
                y -= 1

                if buf > 0:  # вертикальный шаг
                    d += a2 - 2 * y * a2

                else:  # диагональный шаг
                    x += 1
                    d += 2 * b2 * x - 2 * a2 * y + a2 + b2

            else:  # пиксель лежит на окружности
                x += 1  # диагональный шаг
                y -= 1
                d += 2 * b2 * x - 2 * a2 * y + a2 + b2

    def __alg_middle(self):

        x = 0  # начальные значения
        y = self.__b

        a2 = self.__a ** 2
        b2 = self.__b ** 2

        delta = round(b2 + a2 * (y - 0.5) * (y - 0.5) - a2 * b2)
        border = round(a2 / sqrt(b2 + a2))

        while x <= border:

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            x += 1

            if delta > 0:
                y -= 1
                delta += -2 * a2 * y

            delta += 2 * x * b2 + b2

        delta += 0.75 * (a2 - b2) - (b2 * x + a2 * y);

        while y >= 0:

            self._painter.drawPoint(QPoint(x, y))
            self._painter.drawPoint(QPoint(x, -y))
            self._painter.drawPoint(QPoint(-x, y))
            self._painter.drawPoint(QPoint(-x, -y))

            y -= 1

            if delta < 0:
                x += 1
                delta += 2 * b2 * x

            delta += -2 * y * a2 + a2

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
