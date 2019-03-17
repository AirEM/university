from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QPainter, QPixmap, QPalette, QPen)
from PyQt5.QtWidgets import (QApplication, QGridLayout, QGroupBox,
                             QVBoxLayout, QComboBox, QButtonGroup,
                             QLabel, QWidget, QPushButton, QLineEdit,
                             QMessageBox, QRadioButton)


def sign(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    else:
        return 0


def b_whole_numbers(painter, xn, yn, xk, yk):
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


def b_real_number(painter, xn, yn, xk, yk):
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


def b_modified(painter, xn, yn, xk, yk):
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

        self.algorithm = None
        self.algorithms = {'Алгоритм Брезенхема\n c действительными числами': b_real_number,
                           'Алгоритм Брезенхема\n с целыми числами': b_whole_numbers,
                           'Алгоритм Брезенхема\n с устранением ступенчатости': b_modified,
                           'CDA': None,
                           'Библиотечный алгоритм': None}

        self.color = Qt.black
        self.colors = {0: Qt.black, 1: Qt.red, 2: Qt.green, 3: Qt.blue, 4: Qt.yellow}

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
        b_modified(p, xb, yb, xe, ye)
        p.end()

        self.update()

    def paintEvent(self, event):
        if self.points is None:
            return

        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)


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
        self.colorComboBox.addItem("Черный", 0)  # Qt.black)
        self.colorComboBox.addItem("Красный", 1)  # Qt.red)
        self.colorComboBox.addItem("Зеленый", 2)  # Qt.green)
        self.colorComboBox.addItem("Синий", 4)  # Qt.blue)
        self.colorComboBox.addItem("Желтый", 5)  # Qt.yellow)

        colorLabel = QLabel("&Цвет:")
        colorLabel.setAlignment(Qt.AlignRight)
        colorLabel.setBuddy(self.colorComboBox)

        # Radio Button

        rb_0 = QRadioButton('Алгоритм Брезенхема\n c действительными числами')
        rb_1 = QRadioButton('Алгоритм Брезенхема\n с целыми числами')
        rb_2 = QRadioButton('Алгоритм Брезенхема\n с устранением ступенчатости')
        rb_3 = QRadioButton('CDA')
        rb_4 = QRadioButton('Библиотечный алгоритм')

        rb_0.setChecked(True)

        button_group = QButtonGroup()
        button_group.addButton(rb_0)
        button_group.addButton(rb_1)
        button_group.addButton(rb_2)
        button_group.addButton(rb_3)
        button_group.addButton(rb_4)

        # Buttons

        drawButton = QPushButton("Отрисовать")
        cleanButton = QPushButton("Очистить")

        # Connection

        drawButton.clicked.connect(self.drawButtonClicked)

        # layout

        mainLayout = QGridLayout()

        # Right Layout

        rightLayout = QGridLayout()
        rightLayout_2 = QGridLayout()

        rightLayout.addWidget(beginLabel, 0, 0, 1, 4)

        rightLayout.addWidget(QLabel("x = "), 1, 0, Qt.AlignRight)
        rightLayout.addWidget(self.xbEdit, 1, 1)  # , Qt.AlignRight)
        rightLayout.addWidget(QLabel("y = "), 1, 2, Qt.AlignRight)
        rightLayout.addWidget(self.ybEdit, 1, 3)  # , Qt.AlignRight)

        rightLayout.addWidget(endLabel, 2, 0, 1, 4)

        rightLayout.addWidget(QLabel("x = "), 3, 0, Qt.AlignRight)
        rightLayout.addWidget(self.xeEdit, 3, 1)  # , Qt.AlignRight)
        rightLayout.addWidget(QLabel("y = "), 3, 2, Qt.AlignRight)
        rightLayout.addWidget(self.yeEdit, 3, 3)  # , Qt.AlignRight)

        # right layout 2

        rightLayout_2.addWidget(colorLabel, 0, 0, 1, 1)
        rightLayout_2.addWidget(self.colorComboBox, 0, 1, 1, 3)
        rightLayout_2.addWidget(rb_0, 1, 0, 1, 4)
        rightLayout_2.addWidget(rb_1, 2, 0, 1, 4)
        rightLayout_2.addWidget(rb_2, 3, 0, 1, 4)
        rightLayout_2.addWidget(rb_3, 4, 0, 1, 4)
        rightLayout_2.addWidget(rb_4, 5, 0, 1, 4)

        # Group Box

        rightGB = QGroupBox("Координаты")
        rightGB.setLayout(rightLayout)

        rightGB_2 = QGroupBox("Параметры")
        rightGB_2.setLayout(rightLayout_2)

        rW = QWidget()
        rl = QVBoxLayout()
        rl.addWidget(lineLabel)
        rl.addWidget(rightGB)
        rl.addWidget(rightGB_2)
        rl.addWidget(drawButton)
        rW.setLayout(rl)

        # Main Window

        mainLayout.setColumnStretch(0, 3)
        mainLayout.addWidget(self.renderArea, 0, 0, 4, 4)

        mainLayout.addWidget(rW, 0, 4)  # rightGB, 0, 4)

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
