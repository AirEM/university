from Figure import Circle, Ellipse
from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QPainter, QPixmap, QPalette, QPen)
from PyQt5.QtWidgets import QWidget


class RenderArea(QWidget):

    def __init__(self):
        super().__init__()

        self.colors = {0: Qt.black,
                       1: Qt.red,
                       2: Qt.green,
                       3: Qt.blue,
                       4: Qt.yellow,
                       5: Qt.white}

        self.pixmap = QPixmap(self.size()).scaled(800, 600, Qt.IgnoreAspectRatio)
        self.pixmap.fill(Qt.transparent)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    def sizeHint(self):
        return QSize(800, 600)

    def clean_all(self):
        self.pixmap = QPixmap(self.size())
        self.pixmap.fill(Qt.transparent)

        self.update()

    def createFigure(self, figure, color, alg, **args):

        p = QPainter(self.pixmap)
        p.translate(self.width() / 2, self.height() / 2)
        pen = QPen(self.colors[color])
        p.setPen(pen)

        self.figure = Ellipse(args['a'], args['b'], p, alg) if figure \
            else Circle(args['r'], p, alg)
        self.figure.draw()

        p.end()

        self.update()

    def test(self, figure, color, alg,):

        if figure:
            self.testEllipse(color, alg)
        else:
            self.testCircle(color, alg)

    def testEllipse(self, color, alg):

        p = QPainter(self.pixmap)
        p.translate(self.width() / 2, self.height() / 2)
        pen = QPen(self.colors[color])
        p.setPen(pen)

        a = 50
        b = 25
        step = 25

        for _ in range(9):
            self.figure = Ellipse(a, b, p, alg)
            self.figure.draw()
            a += step
            b += step

        p.end()

        self.update()

    def testCircle(self, color, alg):
        p = QPainter(self.pixmap)
        p.translate(self.width() / 2, self.height() / 2)
        pen = QPen(self.colors[color])
        p.setPen(pen)

        r = 25
        step = 25

        for i in range(10):
            self.figure = Circle(r, p, alg)
            self.figure.draw()
            r += step

        p.end()

        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)
