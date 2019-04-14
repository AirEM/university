from PyQt5.QtGui import QColor
from PyQt5.QtCore import Qt, QPoint


class Figure:
    def __init__(self):
        self.__points = list()
        self.__points_len = 0
        self.__state = 0

    # protected functions

    def __find_middle(self):
        min_x = min(self.__points, key=lambda item: item[0])[0]
        max_x = max(self.__points, key=lambda item: item[0])[0]
        mid_x = (max_x + min_x) / 2

        diff = abs(mid_x - self.__points[0][0])
        index = 0

        for i in range(len(self.__points)):
            if diff > abs(mid_x - self.__points[i][0]):
                index = i
                diff = abs(mid_x - self.__points[i][0])

        return self.__points[index][0]

    def __fill_edge(self, painter, image, pb, pe, mid_x):

        left = False

        # horizontal line
        if pb[1] == pe[1]:
            self.__state += 1
            return

        # Is the line to the left of the partition?
        if pb[0] < mid_x or pe[0] < mid_x:
            left = True

        start_x = pb[0]
        y = pb[1]
        y_end = pe[1]
        dx = (pe[0] - pb[0]) / (pe[1] - pb[1])

        while y < y_end:

            x = start_x

            if left:
                while x < mid_x:
                    self.__inversion(painter, image, x, y)
                    x += 1
                start_x += dx
                y += 1

            else:
                while x >= mid_x:
                    self.__inversion(painter, image, x, y)
                    x -= 1
                start_x += dx
                y += 1

        self.__state += 1
        return

    def __inversion(self, painter, image, x, y):

        col = QColor(image.pixel(x, y))

        if col == Qt.blue:
            pen = painter.pen()
            pen.setColor(Qt.white)
            painter.setPen(pen)
        else:
            pen = painter.pen()
            pen.setColor(Qt.blue)
            painter.setPen(pen)

        painter.drawPoint(x, y)

    # secondary functions

    def add_point(self, x, y):
        self.__points.append((x, y))
        self.__points_len += 1

    def draw(self, painter):
        if self.__points_len > 1:
            painter.drawLine(self.__points[self.__points_len - 1][0],
                             self.__points[self.__points_len - 1][1],
                             self.__points[self.__points_len - 2][0],
                             self.__points[self.__points_len - 2][1])

    # main functions

    def fill(self, painter, image, slow=False):

        mid_x = self.__find_middle()

        for i in range(self.__state, self.__points_len - 1):

            pb = min(self.__points[i], self.__points[i + 1], key=lambda item: item[1])
            pe = max(self.__points[i], self.__points[i + 1], key=lambda item: item[1])

            if pb[0] < mid_x < pe[0] or pb[0] > mid_x > pe[0]:
                y_new = ((pe[1] - pb[1]) * mid_x - (pb[0] * pe[1] - pe[0] * pb[1])) / (pe[0] - pb[0])
                y_new = round(y_new)

                self.__fill_edge(painter, image, pb, (mid_x, y_new), mid_x)
                self.__fill_edge(painter, image, (mid_x, y_new), pe, mid_x)

            else:
                self.__fill_edge(painter, image, pb, pe, mid_x)

            # painter.drawLine(pb[0], pb[1], pe[0], pe[1])

            break

    def close(self):
            self.add_point(self.__points[0][0],
                           self.__points[0][1])

    def clean(self):
        self.__points.clear()
        self.__points_len = 0
        self.__state = 0
