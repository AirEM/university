from Figure import Figure
from PyQt5.QtCore import QPoint, QSize, Qt, QEvent
from PyQt5.QtGui import QPainter, QPixmap, QPalette, QPen, QKeyEvent
from PyQt5.QtWidgets import QWidget
import time


class RenderArea(QWidget):

    def __init__(self, pListWidget):
        super().__init__()

        self.pointsListWidget = pListWidget

        self.shift = False

        self.figure = Figure()

        self.pixmap = QPixmap(self.size()).scaled(800, 633, Qt.IgnoreAspectRatio)
        self.pixmap.fill()

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    def sizeHint(self):
        return QSize(800, 600)

    def resizeEvent(self, ev):
        self.pixmap.scaled(self.width(), self.height(), Qt.IgnoreAspectRatio)

    def mousePressEvent(self, ev):

        if ev.button() == Qt.LeftButton:
            x = ev.pos().x()
            y = ev.pos().y()

            self.pointsListWidget.addItem("({}; {})".format(x, y))

            self.figure.add_point(x, y)
            self.draw()

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

        state = True

        count = 0
        while state:

            count += 1

            p = QPainter(self.pixmap)
            pen = QPen(Qt.blue)
            p.setPen(pen)

            state = self.figure.fillBr(p, self.pixmap.toImage(), slow)

            p.end()

            #if slow:
                #time.sleep(500)

            self.update()
        print("TEST COUNT = ", count)

    def close_figure(self):
        self.figure.close()
        self.draw()

    def clean_all(self):
        self.pixmap = QPixmap(self.size())
        self.pixmap.fill(Qt.transparent)

        self.figure.clean()

        self.pointsListWidget.clear()

        self.update()
