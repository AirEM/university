from PyQt5.QtGui import QColor
from PyQt5.QtCore import Qt, QPoint


class Figure:
    def __init__(self):
        self.__polygon = list()
        self.__polygon.append([])
        self.__polygon_state = 0
        self.__edge_lst = list()
        self.__state = 0
        self.__state_coord = 0
        self.__is_close = False

    # Функуии заливки

    # Функция нахождения координаты X перегородки
    def __find_middle(self):
        min_x = min(self.__polygon[0], key=lambda item: item[0])[0]
        max_x = max(self.__polygon[0], key=lambda item: item[0])[0]
        mid_x = (max_x + min_x) / 2

        diff = abs(mid_x - self.__polygon[0][0][0])
        index = 0

        for i in range(len(self.__polygon[0])):
            if diff > abs(mid_x - self.__polygon[0][i][0]):
                index = i
                diff = abs(mid_x - self.__polygon[0][i][0])

        return self.__polygon[0][index][0]

    # отрисовка линии алгоритмом Брезейнхема
    def __drawLineBr(self, painter, xn, yn, xk, yk):

        def sign(t):
            if t > 0:
                return 1
            elif t < 0:
                return -1
            else:
                return 0

        # !!! вставка не относится к алгориитму отрисовки
        # текущее ребро

        current_edge = dict()

        # !!! конец вставки

        x = xn
        y = yn

        dx = xk - xn
        dy = yk - yn

        sx = sign(dx)
        sy = sign(dy)

        dx = abs(dx)
        dy = abs(dy)

        flag = 0

        if not (dx > dy):
            flag = 1
            dx, dy = dy, dx

        e = 2 * dy - dx

        for i in range(dx + 1):
            painter.drawPoint(QPoint(x, y))

            # !!! вставка не относится к алгориитму отрисовки
            data_x = current_edge.get(y)

            # если нет точки с координатой у,, то добавляем
            if data_x is None:
                current_edge[y] = (x, x)
            else:
                # если есть, то смотрим масимальный и минимальный х по координате у
                if x < data_x[0]:
                    data_x = (x, data_x[1])
                elif data_x[1] < x:
                    data_x = (data_x[0], x)

                current_edge[y] = data_x

            # !!! конец вставки

            if e >= 0:
                if flag == 0:
                    y += sy
                else:
                    x += sx

                e -= 2 * dx

            if flag == 0:
                x += sx
            else:
                y += sy

            e += 2 * dy

        # !!! вставка не относится к алгориитму отрисовки
        self.__edge_lst.append(current_edge)
        # !!! конец вставки

    # закраска области от ребра до перегородки
    def fillBr(self, painter, image, color, slow=False):

        # накшли координату Х перегородки
        mid_x = self.__find_middle()

        num_edges = len(self.__edge_lst)

        for i in range(self.__state, num_edges):

            state = self.__fill_edgeBr(painter, image, color, self.__edge_lst[i], mid_x, slow)

            if state:
                self.__state += 1
            break

        return self.__state != num_edges

    def __fill_edgeBr(self, painter, image, color, edge, mid_x, slow=False):

        y_arr = sorted(edge.keys())
        len_y_arr = len(y_arr) - 1

        # горизонтальная линия
        if y_arr[0] == y_arr[len_y_arr-1]:
            return True

        if not slow:
            self.__state_coord = 0

        for i in range(self.__state_coord, len_y_arr):

            y = y_arr[i]

            x_array = edge.get(y)

            self.__inversion(painter, image, color, mid_x, x_array[0], x_array[1], y)

            if slow:
                self.__state_coord = (self.__state_coord + 1) % len_y_arr
                return not bool(self.__state_coord)

        return True

    def __inversion(self, painter, image, color, mid_x, x_left, x_right, cur_y):

        if x_left <= mid_x <= x_right:
            return

        # отрезое [begin, end)

        if x_left < mid_x:
            self.__inversionBr(painter, image, color, x_left + 1, mid_x, cur_y)

        if mid_x < x_right:
            self.__inversionBr(painter, image, color, mid_x, x_right, cur_y)

    def __inversionBr(self, painter, image, color, x_begin, x_end, y):

        for x in range(x_begin, x_end):
            col = QColor(image.pixel(x, y))

            if col != color and col != Qt.white:
                pen = painter.pen()
                pen.setColor(Qt.black)
                painter.setPen(pen)
            elif col == color:
                pen = painter.pen()
                pen.setColor(Qt.white)
                painter.setPen(pen)
            else:
                pen = painter.pen()
                pen.setColor(color)
                painter.setPen(pen)

            painter.drawPoint(x, y)

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
            self.__drawLineBr(painter, self.__polygon[self.__polygon_state][polygon_len - 1][0],
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
        self.__state = 0
        self.__is_close = False
