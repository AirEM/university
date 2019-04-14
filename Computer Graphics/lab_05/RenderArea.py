from Figure import Figure
from PyQt5.QtCore import QPoint, QSize, Qt, QEvent
from PyQt5.QtGui import QPainter, QPixmap, QPalette, QPen, QKeyEvent
from PyQt5.QtWidgets import QWidget


class RenderArea(QWidget):

    def __init__(self, pListWidget):
        super().__init__()

        self.pointsListWidget = pListWidget

        self.shift = False

        self.figure = Figure()

        self.pixmap = QPixmap(self.size()).scaled(800, 633, Qt.IgnoreAspectRatio)
        self.pixmap.fill()#Qt.transparent)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    #def sizeHint(self):
        # return QSize(800, 600)

    def mousePressEvent(self, ev):
        if ev.button() == Qt.LeftButton:
            x = ev.pos().x()
            y = ev.pos().y()

            # print(self.shift)
            '''
            if self.shift and self.points_len > 0:
                if abs(x - self.points[self.points_len - 1][0]) < abs(y - self.points[self.points_len - 1][1]):
                    self.pointsListWidget.addItem("({}; {})".format(self.points[self.points_len - 1][0], self.height() - y))
                    self.figure.addPoint((self.points[self.points_len - 1][0], y))
                else:
                    self.pointsListWidget.addItem("({}; {})".format(x, self.height() - self.points[self.points_len - 1][1]))
                    self.points.append((x, self.points[self.points_len - 1][1]))
            else:
            '''
            self.pointsListWidget.addItem("({}; {})".format(x, self.height() - y))
            self.figure.add_point(x, y)

            self.draw()

    '''
    def keyPressEvent(self, event):
        print(event.key())
        if event.key() == Qt.Key_Shift:
            self.shift = True

    def keyReleaseEvent(self, event):
        print(event.key())
        if event.key() == Qt.Key_Shift:
            self.shift = False
    '''

    def resizeEvent(self, ev):
        self.pixmap.scaled(self.width(), self.height(), Qt.IgnoreAspectRatio)

    def draw(self):
        p = QPainter(self.pixmap)
        pen = QPen(Qt.blue)
        p.setPen(pen)

        self.figure.draw(p)

        p.end()

        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)

    def fill(self, slow=False):
        p = QPainter(self.pixmap)
        pen = QPen(Qt.blue)
        p.setPen(pen)

        self.figure.fill(p, self.pixmap.toImage(), slow)

        p.end()

        self.update()

    def close_figure(self):
        self.figure.close()
        self.draw()

    def clean_all(self):
        self.pixmap = QPixmap(self.size())
        self.pixmap.fill(Qt.transparent)

        self.figure.clean()

        self.pointsListWidget.clear()

        self.update()
