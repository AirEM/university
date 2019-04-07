from PyQt5.QtGui import QColor
from PyQt5.QtCore import Qt, QPoint


class Figure:
    def __init__(self):
        self.__points = list()
        self.__points_len = 0
        self.__state = 0

    def _find_middle(self):
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

    def _find_y(self):
        return min(self.__points, key=lambda item: item[1])[1],\
               max(self.__points, key=lambda item: item[1])[1]

    def addPoint(self, x, y):
        self.__points.append((x, y))
        self.__points_len += 1

    def clean(self):
        self.__points.clear()
        self.__points_len = 0
        self.__state = 0

    def draw(self, painter):
        if self.__points_len > 1:
            painter.drawLine(self.__points[self.__points_len - 1][0],
                             self.__points[self.__points_len - 1][1],
                             self.__points[self.__points_len - 2][0],
                             self.__points[self.__points_len - 2][1])

    def fill(self, painter, pixmap, slow=False):
        mid_x = self._find_middle()
        min_y, max_y = self._find_y()

        for i in range(self.__state, self.__points_len - 1):

            pb = self.__points[i]
            pe = self.__points[i + 1]

            image = pixmap.toImage()

            # horizontal line

            if pb[1] == pe[1]:
                self.__state += 1
                continue

            if pb[0] < mid_x < pe[0]:

                y_new = ((pe[1] - pb[1]) * mid_x - (pb[0] * pe[1] - pe[0] * pb[1])) / (pe[0] - pb[0])
                y_new = round(y_new)

                self.fill_area(pb, (mid_x, y_new), mid_x, image, painter)
                self.fill_area((mid_x, y_new), pe, mid_x, image, painter)

            elif pb[0] > mid_x > pe[0]:
                y_new = ((pe[1] - pb[1]) * mid_x - (pb[0] * pe[1] - pe[0] * pb[1])) / (pe[0] - pb[0])
                y_new = round(y_new)

                self.fill_area(pe, (mid_x, y_new), mid_x, image, painter)
                self.fill_area((mid_x, y_new), pb, mid_x, image, painter)
            else:
                self.fill_area(pb, pe, mid_x, image, painter)

            self.__state += 1
            break

    def fill_area(self, pb, pe, mid_x, image, painter):

        pb, pe = min(pb, pe, key=lambda item: item[1]), max(pb, pe, key=lambda item: item[1])

        for y in range(pb[1], pe[1]):

            x_start = mid_x + 1

            x_end = ((pb[0] - pe[0]) * (y + 0.5) - (pb[0] * pe[1] - pe[0] * pb[1])) / (pb[1] - pe[1])
            x_end = round(x_end)

            '''
            f0 = 1 if QColor(image.pixel(x_end - 1, y)) == Qt.blue else 0
            f1 = 1 if QColor(image.pixel(x_end, y)) == Qt.blue else 0
            f2 = 1 if QColor(image.pixel(x_end + 1, y)) == Qt.blue else 0

            print(f0, f1, f2)
            '''

            x_start, x_end = min(x_start, x_end), max(x_start, x_end)

            for x in range(x_start, x_end):

                if QColor(image.pixel(x, y)) == Qt.blue:

                    pen = painter.pen()
                    pen.setColor(Qt.white)
                    painter.setPen(pen)

                    painter.drawPoint(QPoint(x, y))
                else:
                    pen = painter.pen()
                    pen.setColor(Qt.blue)
                    painter.setPen(pen)

                    painter.drawPoint(QPoint(x, y))

    def close(self):
            self.addPoint(self.__points[0][0],
                          self.__points[0][1])
