from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QBrush, QLinearGradient, QPainter,
                         QPalette, QPen, QPolygon)
from PyQt5.QtWidgets import (QApplication, QGridLayout,
                             QLabel, QWidget, QPushButton)


RADIUS = 2504


def f_circle(x):
    return (RADIUS - x*x)**0.5


def f_hep(x):
    return 100/x


class RenderArea(QWidget):

    def __init__(self, parent=None):
        super(RenderArea, self).__init__(parent)

        self.d = 0
        self.k = 1
        self.fi = 0

        self.array = [(x + self.width() / 2, self.height() / 2 -
                       round(f_circle(x), 5)) for x in range(2, 51)]
        self.array.extend([(x + self.width() / 2, self.height() / 2 -
                            round(f_hep(x), 5)) for x in range(50, 1, -1)])

        self.pen = QPen()
        self.brush = QBrush(Qt.green, Qt.BDiagPattern)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(300, 300)

    def sizeHint(self):
        return QSize(400, 200)

    def do_carry(self, brush):
        self.brush = brush
        self.update()

    def paintEvent(self, event):

        #rect = QRect(10.0 + self.d, 20.2 + self.d, 100.1, 100.2)

        p = QPolygon([QPoint(item[0], item[1]) for item in self.array])

        painter = QPainter(self)
        painter.setPen(self.pen)
        painter.setBrush(self.brush)

        #painter.drawEllipse(rect)
        painter.drawPolygon(p)
        painter.restore()

        painter.setPen(self.palette().dark().color())
        painter.setBrush(Qt.NoBrush)


class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()

        self.renderArea = RenderArea()

        mainBut = QPushButton("TEST")
        mainLabel = QLabel("TEST = ")
        mainLabel.setBuddy(mainBut)

        mainBut.clicked.connect(self.buttonClicked)

        # layout

        mainLayout = QGridLayout()

        mainLayout.setColumnStretch(0, 1)
        mainLayout.setColumnStretch(3, 1)
        mainLayout.addWidget(self.renderArea, 0, 0, 1, 4)
        mainLayout.setRowMinimumHeight(1, 6)

        mainLayout.addWidget(mainLabel, 1, 7, Qt.AlignRight)
        mainLayout.addWidget(mainBut, 1, 8)

        self.setLayout(mainLayout)

        self.setGeometry(500, 300, 700, 600)
        self.setWindowTitle("Lab_02")

    def buttonClicked(self):
        linearGradient = QLinearGradient(0, 0, 100, 100)
        self.renderArea.d += 5
        self.renderArea.do_carry(QBrush(Qt.green, Qt.BDiagPattern))# QBrush(linearGradient))


if __name__ == '__main__':

    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
