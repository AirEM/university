from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QBrush, QPainter, QPalette, QPixmap,
                         QPalette, QPen, QPolygon, QColor, QPicture)
from PyQt5.QtWidgets import (QApplication, QGridLayout, QGroupBox, QVBoxLayout, QComboBox, QMainWindow,
                             QLabel, QWidget, QPushButton, QLineEdit, QMessageBox, QErrorMessage)


def sign(x):

    if x > 0:
        return 1
    elif x < 0:
        return -1
    else:
        return 0


def b_simple(painter, xn, yn, xk, yk):
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

    for i in range(dx):
        painter.drawPoint(QPoint(x, y))

        if e >= 0:
            if flag == 0:
                y += sy
            else:
                x += sx

            e -= 2 * dx

        else:
            if flag == 0:
                x += sx
            else:
                y += sy

            e += 2 * dy


def b_norm(painter, xn, yn, xk, yk):
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

    m = dy / dx
    e = m - 0.5

    for i in range(dx):
        painter.drawPoint(QPoint(x, y))

        if e >= 0:
            if flag == 0:
                y += sy
            else:
                x += sx

            e -= 1

        else:
            if flag == 0:
                x += sx
            else:
                y += sy

            e += m


def b_s(painter, xn, yn, xk, yk):

    I = 256

    x = xn
    y = yn

    dx = xk - xn
    dy = yk - yn

    sx = sign(dx)
    sy = sign(dy)

    dx = abs(dx)
    dy = abs(dy)

    m = (I * dy) / dx

    W = I - m

    e = I / 2

    # plot(X, Y, m / 2);
    pen = painter.pen()
    color = pen.color()
    color.setAlpha(m / 2)

    pen.setColor(color)
    painter.setPen(pen)

    painter.drawPoint(QPoint(x, y))

    while x < xk:
        if e < W:
            x += 1
            e += m
        else:
            x += 1
            y += 1
            e -= W

        # plot(X, Y, e)
        painter.drawPoint(QPoint(x, y))

        pen = painter.pen()
        color = pen.color()
        color.setAlpha(e)

        pen.setColor(color)
        painter.setPen(pen)

        painter.drawPoint(QPoint(x, y))


class RenderArea(QWidget):

    def __init__(self):
        super().__init__()

        self.points = None

        self.algorithm = 0
        self.color = Qt.black
        self.colors = {0: Qt.black, 1: Qt.red, 2: Qt.green, 3: Qt.blue, 4: Qt.yellow}


        # self.pen = QPen()
        # self.brush = QBrush()

        self.pixmap = QPixmap(self.size())
        self.pixmap.fill(Qt.transparent)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    def sizeHint(self):
        return QSize(800, 600)

    def drawLine(self, xb, yb, xe, ye, color):

        self.color = self.colors[color]
        self.points = [(xb, yb,), (xe, ye)]

        p = QPainter(self.pixmap)
        pen = QPen(Qt.red)
        p.setPen(pen)
        b_s(p, xb, yb, xe, ye)
        #p.drawLine(line)
        p.end()


        self.update()

    def paintEvent(self, event):

        if self.points is None:
            return

        # pen = QPen()
        # pen.setColor(self.color)

        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)

        # painter.restore()
        # painter.setPen(pen)
        # painter.setBrush(QBrush())

        # b_s(painter, round(self.points[0][0]), round(self.points[0][1]),
               # round(self.points[1][0]), round(self.points[1][1]))

        # painter.drawLine(self.points[0][0], self.points[0][1], self.points[1][0], self.points[1][1])
        # painter.restore()
        #painter.save()

        # painter.setPen(self.palette().dark().color())
        # painter.setBrush(Qt.NoBrush)


class Window(QWidget):

    def __init__(self):
        super(Window, self).__init__()

        self.renderArea = RenderArea()

        # Labels

        lineLabel = QLabel("Линия")
        lineLabel.setAlignment(Qt.AlignHCenter)
        beginLabel = QLabel("Координаты начала линии.")
        beginLabel.setAlignment(Qt.AlignHCenter)
        endLabel = QLabel("Координаты конца линии.")
        endLabel.setAlignment(Qt.AlignHCenter)

        # Edit

        self.xbEdit = QLineEdit()
        self.xbEdit.setFixedWidth(30)
        self.ybEdit = QLineEdit()
        self.ybEdit.setFixedWidth(30)
        self.xeEdit = QLineEdit()
        self.xeEdit.setFixedWidth(30)
        self.yeEdit = QLineEdit()
        self.yeEdit.setFixedWidth(30)

        # QComboBox

        self.colorComboBox = QComboBox()
        self.colorComboBox.addItem("Черный", 0)#Qt.black)
        self.colorComboBox.addItem("Красный", 1)#Qt.red)
        self.colorComboBox.addItem("Зеленый", 2)#Qt.green)
        self.colorComboBox.addItem("Синий", 4)#Qt.blue)
        self.colorComboBox.addItem("Желтый", 5)#Qt.yellow)

        colorLabel = QLabel("&Цвет:")
        colorLabel.setAlignment(Qt.AlignRight)
        colorLabel.setBuddy(self.colorComboBox)

        # Buttons

        drawButton = QPushButton("Отрисовать")
        cleanButton = QPushButton("Очистить")

        # Connection

        drawButton.clicked.connect(self.drawButtonClicked)

        # layout

        mainLayout = QGridLayout()

        # Right Layout

        rightLayout = QGridLayout()

        rightLayout.addWidget(lineLabel, 0, 0, 1, 4)

        rightLayout.addWidget(beginLabel, 1, 0, 1, 4)

        rightLayout.addWidget(QLabel("x = "), 2, 0, Qt.AlignRight)
        rightLayout.addWidget(self.xbEdit, 2, 1)  # , Qt.AlignRight)
        rightLayout.addWidget(QLabel("y = "), 2, 2, Qt.AlignRight)
        rightLayout.addWidget(self.ybEdit, 2, 3)  # , Qt.AlignRight)

        rightLayout.addWidget(endLabel, 3, 0, 1, 4)

        rightLayout.addWidget(QLabel("x = "), 4, 0, Qt.AlignRight)
        rightLayout.addWidget(self.xeEdit, 4, 1)  # , Qt.AlignRight)
        rightLayout.addWidget(QLabel("y = "), 4, 2, Qt.AlignRight)
        rightLayout.addWidget(self.yeEdit, 4, 3)  # , Qt.AlignRight)

        rightLayout.addWidget(colorLabel, 5, 0, 1, 2)
        rightLayout.addWidget(self.colorComboBox, 5, 2, 1, 2)

        rightLayout.addWidget(drawButton, 6, 0, 1, 4)

        # Group Box

        rightGB = QGroupBox("Линия")

        rightGB.setLayout(rightLayout) # (rightLayout)

        # Main Window

        mainLayout.setColumnStretch(0, 3)
        mainLayout.addWidget(self.renderArea, 0, 0, 4, 4)

        mainLayout.addWidget(rightGB, 0, 4)

        self.setLayout(mainLayout)

        self.setGeometry(500, 300, 800, 600)
        self.setWindowTitle("Lab_03")

    def drawButtonClicked(self):
        try:
            xb = float(self.xbEdit.text())
            yb = float(self.ybEdit.text())
            xe = float(self.xeEdit.text())
            ye = float(self.yeEdit.text())

            color = self.colorComboBox.itemData(self.colorComboBox.currentIndex())

            self.renderArea.drawLine(xb, yb, xe, ye, color)
        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()


if __name__ == '__main__':

    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
