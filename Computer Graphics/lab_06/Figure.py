from PyQt5.QtGui import QColor
from PyQt5.QtCore import Qt, QPoint


class Figure:
    def __init__(self):
        self.__polygon = list()
        self.__polygon.append([])
        self.__polygon_state = 0
        self.__edge_lst = list()

        self.__state_fill = None

        self.__is_close = False

    # Функуии заливки

    # отрисовка линии алгоритмом Брезейнхема
    def __drawLine(self, painter, xn, yn, xk, yk):

        painter.drawLine(xn, yn, xk, yk)

        # !!! вставка не относится к алгориитму отрисовки
        # текущее ребро
        current_edge = ((xn, yn), (xk, yk))

        self.__edge_lst.append(current_edge)
        # !!! конец вставки

    # закраска области от ребра до перегородки
    def fill(self, point, painter, image, color, slow=False):

        # Настройка цвета
        color_edge = Qt.black

        pen = painter.pen()
        pen.setColor(color)
        painter.setPen(pen)

        # ---------------------------------------------

        # Сохранение состояния
        if self.__state_fill is not None:
            stack = self.__state_fill
        else:
            stack = [point]

        # пока стек не пуст
        while stack:

            # извлечение пикселя (х,у) из стека
            current_point = stack.pop()
            x = current_point[0]
            y = current_point[1]

            # tx = x, запоминаем абсицссу
            current_x = current_point[0]
            Fl = 0

            # цвет(х,у) = цвет закраски
            painter.drawPoint(x, y)

            # заполняем интервал слева от затравки
            x = x - 1
            while QColor(image.pixel(x, y)) != color_edge:
                painter.drawPoint(x, y)
                x = x - 1

            # сохраняем крайний слева пиксел
            x_left = x + 1
            x = current_x

            # заполняем интервал справа от затравки
            x = x + 1

            while QColor(image.pixel(x, y)) != color_edge:
                painter.drawPoint(x, y)
                x = x + 1

            # сохраняем крайний справа пиксел
            x_right = x - 1
            y = y + 1
            x = x_left

            # ----------------------------------------
            # ищем затравку на строке выше
            while x <= x_right:
                Fl = 0
                cur_col = QColor(image.pixel(x, y))
                while cur_col != color_edge and cur_col != color and x <= x_right:
                    if Fl == 0:
                        Fl = 1
                    x = x + 1
                    cur_col = QColor(image.pixel(x, y))

                if Fl == 1:
                    cur_col = QColor(image.pixel(x, y))
                    if x == x_right and cur_col != color_edge and cur_col != color:
                        stack.append((x, y))
                    else:
                        stack.append((x - 1, y))
                    Fl = 0

                current_x = x
                cur_col = QColor(image.pixel(x, y))
                while (cur_col == color_edge or cur_col == color) and x < x_right:
                    x = x + 1
                    cur_col = QColor(image.pixel(x, y))

                if x == current_x:
                    x = x + 1

            y = y - 2
            x = x_left
            while x <= x_right:
                Fl = 0
                cur_col = QColor(image.pixel(x, y))
                while cur_col != color_edge and cur_col != color and x <= x_right:
                    if Fl == 0:
                        Fl = 1
                    x = x + 1
                    cur_col = QColor(image.pixel(x, y))

                if Fl == 1:
                    cur_col = QColor(image.pixel(x, y))
                    if x == x_right and cur_col != color_edge and cur_col != color:
                        stack.append((x, y))
                    else:
                        stack.append((x - 1, y))
                    Fl = 0

                current_x = x
                cur_col = QColor(image.pixel(x, y))
                while (cur_col == color_edge or cur_col == color) and x < x_right:
                    x = x + 1
                    cur_col = QColor(image.pixel(x, y))

                if x == current_x:
                    x = x + 1

            self.__state_fill = stack
            return bool(len(stack))

        return False

    # служебные функции

    def is_close(self):
        return self.__is_close

    def set_close(self, f=False):
        self.__is_close = f
        self.__polygon.append([])
        self.__polygon_state += 1

    def add_point(self, x, y):
        self.__is_close = False
        self.__polygon[self.__polygon_state].append((x, y))

    def draw(self, painter):

        polygon_len = len(self.__polygon[self.__polygon_state])

        if polygon_len > 1:
            self.__drawLine(painter, self.__polygon[self.__polygon_state][polygon_len - 1][0],
                              self.__polygon[self.__polygon_state][polygon_len - 1][1],
                              self.__polygon[self.__polygon_state][polygon_len - 2][0],
                              self.__polygon[self.__polygon_state][polygon_len - 2][1])

    def close(self):
        self.add_point(self.__polygon[self.__polygon_state][0][0],
                       self.__polygon[self.__polygon_state][0][1])

    def clean(self):
        self.__polygon.clear()
        self.__polygon.append([])
        self.__polygon_state = 0
        self.__edge_lst.clear()
        self.__state_fill = None
        self.__is_close = False
