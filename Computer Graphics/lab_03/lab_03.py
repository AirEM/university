from math import radians, cos, sin
from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QPainter, QPixmap, QPalette, QPen)
from PyQt5.QtWidgets import (QApplication, QGridLayout, QGroupBox,
                             QVBoxLayout, QComboBox, QLabel, QWidget,
                             QPushButton, QLineEdit, QMessageBox, QRadioButton)


def sign(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    else:
        return 0


def alg_b_whole_numb(painter, xn, yn, xk, yk):
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


def alg_b_real_numb(painter, xn, yn, xk, yk):
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

    for i in range(dx + 1):
        painter.drawPoint(QPoint(x, y))

        if e >= 0:
            if flag == 0:
                y += sy
            else:
                x += sx

            e -= 1
            
        if flag == 0:
            x += sx
        else:
            y += sy

        e += m


def alg_b_modified(painter, xn, yn, xk, yk):
    I = 255

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
    W = 1 - m
    e = 0.5
    a = round(I * e)

    # plot(X, Y, m / 2);
    pen = painter.pen()
    color = pen.color()
    color.setAlpha(a)

    pen.setColor(color)
    painter.setPen(pen)

    painter.drawPoint(QPoint(x, y))

    for i in range(dx + 1):

        pen = painter.pen()
        color = pen.color()
        color.setAlpha(a)

        pen.setColor(color)
        painter.setPen(pen)

        painter.drawPoint(QPoint(x, y))

        if e < W:
            if flag:
                y += sy
            else:
                x += sx
            e += m
        else:
            y += sy
            x += sx
            e -= W

        a = round(I * e)


def alg_cda(painter, xn, yn, xk, yk):
    if abs(xk - xn) >= abs(yk - yn):
        l = abs(xk - xn)
    else:
        l = abs(yk - yn)

    px = (xk - xn) / l
    py = (yk - yn) / l

    x = xn + 0.5 * sign(px)
    y = yn + 0.5 * sign(py)

    i = 1

    while i <= l:
        painter.drawPoint(QPoint(x, y))
        x += px
        y += py
        i += 1


def alg_lib(painter, xn, yn, xk, yk):
    painter.drawLine(xn, yn, xk, yk)


class RenderArea(QWidget):

    def __init__(self):
        super().__init__()

        self.points = None

        self.algorithm = alg_b_real_numb
        self.algorithms = {0: alg_b_real_numb,
                           1: alg_b_whole_numb,
                           2: alg_b_modified,
                           3: alg_cda,
                           4: alg_lib}

        self.color = Qt.black
        self.colors = {0: Qt.black,
                       1: Qt.red,
                       2: Qt.green,
                       3: Qt.blue,
                       4: Qt.yellow}

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

    def createSun(self, col, alg):

        xb = self.width() / 4
        xe = xb * 3

        yb = self.height() / 2
        ye = self.height() / 2

        xc = self.width() / 2
        yc = self.height() / 2

        fi = 30
        
        for i in range(12):
            self.createLine(round(xb), round(yb), round(xe), round(ye), col, alg)
            
            new_x = xc + (xb - xc)*cos(radians(fi)) + (yb - yc)*sin(radians(fi))          
            new_y = yc - (xb - xc)*sin(radians(fi)) + (yb - yc)*cos(radians(fi))
            xb = new_x
            yb = new_y

            new_x = xc + (xe - xc)*cos(radians(fi)) + (ye - yc)*sin(radians(fi))          
            new_y = yc - (xe - xc)*sin(radians(fi)) + (ye - yc)*cos(radians(fi))
            xe = new_x
            ye = new_y

    def createLine(self, xb, yb, xe, ye, color, alg):
        self.color = self.colors[color]
        self.points = [(xb, yb,), (xe, ye)]
        self.algorithm = self.algorithms[alg]

        self.drawLine()

    def drawLine(self):
        p = QPainter(self.pixmap)
        pen = QPen(self.color)
        p.setPen(pen)
        self.algorithm(p, self.points[0][0], self.points[0][1],
                       self.points[1][0], self.points[1][1])

        p.end()

        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)


class Window(QWidget):

    def __init__(self):
        super(Window, self).__init__()

        self.renderArea = RenderArea()

        self.alg = 0

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
        self.colorComboBox.addItem("Черный", 0)
        self.colorComboBox.addItem("Красный", 1)
        self.colorComboBox.addItem("Зеленый", 2)
        self.colorComboBox.addItem("Синий", 3)
        self.colorComboBox.addItem("Желтый", 4)

        colorLabel = QLabel("&Цвет:")
        colorLabel.setAlignment(Qt.AlignRight)
        colorLabel.setBuddy(self.colorComboBox)

        # Radio Button

        rb_0 = QRadioButton('Алгоритм Брезенхема\n c действительными числами')
        rb_0.setChecked(True)
        rb_0.toggled.connect(lambda: self.but_rest(0))
        rb_1 = QRadioButton('Алгоритм Брезенхема\n с целыми числами')
        rb_1.toggled.connect(lambda: self.but_rest(1))
        rb_2 = QRadioButton('Алгоритм Брезенхема\n с устранением ступенчатости')
        rb_2.toggled.connect(lambda: self.but_rest(2))
        rb_3 = QRadioButton('CDA')
        rb_3.toggled.connect(lambda: self.but_rest(3))
        rb_4 = QRadioButton('Библиотечный алгоритм')
        rb_4.toggled.connect(lambda: self.but_rest(4))

        # Buttons

        drawButton = QPushButton("Отрисовать")
        testButton = QPushButton("Тест")
        cleanButton = QPushButton("Очистить")

        # Connection

        drawButton.clicked.connect(self.drawButtonClicked)
        testButton.clicked.connect(self.testButtonClicked)
        cleanButton.clicked.connect(self.cleanButtonClicked)

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
        rl.addWidget(testButton)
        rl.addWidget(cleanButton)
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
            yb = self.renderArea.height() - float(self.ybEdit.text())
            xe = float(self.xeEdit.text())
            ye = self.renderArea.height() - float(self.yeEdit.text())

            color = self.colorComboBox.itemData(self.colorComboBox.currentIndex())

            self.renderArea.createLine(round(xb), round(yb),
                                       round(xe), round(ye), color, self.alg)

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    def testButtonClicked(self):
        color = self.colorComboBox.itemData(self.colorComboBox.currentIndex())
        self.renderArea.createSun(color, self.alg)
        
    def cleanButtonClicked(self):
        self.renderArea.clean_all()
    
    def but_rest(self, n):
        self.alg = n


if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
