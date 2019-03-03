from math import cos, sin, radians
from PyQt5.QtCore import QPoint, QSize, Qt
from PyQt5.QtGui import (QBrush, QPainter,
                         QPalette, QPen, QPolygon)
from PyQt5.QtWidgets import (QApplication, QGridLayout, QGroupBox, QVBoxLayout,
                             QLabel, QWidget, QPushButton, QLineEdit, QMessageBox, QErrorMessage)


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

        self.array = [(x + self.width() / 2,
                       self.height() / 2 + round(f_circle(x), 5))
                      for x in range(2, 51)]

        self.array.extend([(x + self.width() / 2,
                            self.height() / 2 + round(f_hep(x), 5))
                           for x in range(50, 1, -1)])

        self.pen = QPen()
        self.brush = QBrush(Qt.green, Qt.BDiagPattern)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    def sizeHint(self):
        return QSize(800, 600)

    def carry_picture(self, dx, dy):
        self.array = [(item[0] + dx, item[1] + dy) for item in self.array]
        self.update()

    def scale_picture(self, xm, ym, kx, ky):
        self.array = [(kx * item[0] + (1 - kx) * xm,
                       ky * item[1] + (1 - ky) * ym)
                      for item in self.array]
        self.update()

    def rotate_picture(self, xc, yc, fi):

        self.array = [(xc - (item[0] - xc)*cos(radians(fi)) + (item[1] - yc)*sin(radians(fi)),
                       yc - (item[0] - xc)*sin(radians(fi)) + (item[1] - yc)*cos(radians(fi)))
                      for item in self.array]
        self.update()

    def paintEvent(self, event):

        p = QPolygon([QPoint(item[0], self.height() - item[1]) for item in self.array])

        painter = QPainter(self)
        painter.setPen(self.pen)
        painter.setBrush(self.brush)

        painter.drawPolygon(p)
        painter.restore()

        painter.setPen(self.palette().dark().color())
        painter.setBrush(Qt.NoBrush)


class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()

        self.renderArea = RenderArea()

        # Labels

        carryLabel = QLabel("Перенос")
        carryLabel.setAlignment(Qt.AlignHCenter)

        scalingLabel = QLabel("Маштабирование")
        scalingLabel.setAlignment(Qt.AlignHCenter)
        scalingPointLabel = QLabel("Центр масштабирования.")
        scalingPointLabel.setAlignment(Qt.AlignHCenter)
        scalingCoefLabel = QLabel("Коэф - ты масштабирования.")
        scalingCoefLabel.setAlignment(Qt.AlignHCenter)

        rotationLabel = QLabel("Поворот")
        rotationLabel.setAlignment(Qt.AlignHCenter)
        rotationPointLabel = QLabel("Центр поворота.")
        rotationPointLabel.setAlignment(Qt.AlignHCenter)
        rotationAngleLabel = QLabel("Угол поворота")
        rotationAngleLabel.setAlignment(Qt.AlignHCenter)

        # Edit

        self.dxEdit = QLineEdit()
        self.dxEdit.setFixedWidth(30)
        self.dyEdit = QLineEdit()
        self.dyEdit.setFixedWidth(30)

        self.xmEdit = QLineEdit()
        self.xmEdit.setFixedWidth(30)
        self.ymEdit = QLineEdit()
        self.ymEdit.setFixedWidth(30)
        self.kxEdit = QLineEdit()
        self.kxEdit.setFixedWidth(30)
        self.kyEdit = QLineEdit()
        self.kyEdit.setFixedWidth(30)

        self.xcEdit = QLineEdit()
        self.xcEdit.setFixedWidth(30)
        self.ycEdit = QLineEdit()
        self.ycEdit.setFixedWidth(30)
        self.fiEdit = QLineEdit()
        self.fiEdit.setFixedWidth(30)

        # Buttons

        carryButton = QPushButton("Переместить")
        scalingButton = QPushButton("Масштабировать")
        rotationBut = QPushButton("Повернуть")

        # Connection

        carryButton.clicked.connect(self.carryButtonClicked)
        scalingButton.clicked.connect(self.scalingButtonClicked)
        rotationBut.clicked.connect(self.rotationButtonClicked)

        # layout

        mainLayout = QGridLayout()

        # Carry Layout

        carryLayout = QGridLayout()

        carryLayout.addWidget(carryLabel, 0, 0, 1, 4)
        carryLayout.addWidget(QLabel("dx = "), 1, 0, Qt.AlignRight)
        carryLayout.addWidget(self.dxEdit, 1, 1) # , Qt.AlignRight)
        carryLayout.addWidget(QLabel("dy = "), 1, 2, Qt.AlignRight)
        carryLayout.addWidget(self.dyEdit, 1, 3) # , Qt.AlignRight)
        carryLayout.addWidget(carryButton, 2, 0, 1, 4)

        # Scaling Layout

        scalingLayout = QGridLayout()

        scalingLayout.addWidget(scalingLabel, 0, 0, 1, 4)
        scalingLayout.addWidget(scalingPointLabel, 1, 0, 1, 4)
        scalingLayout.addWidget(QLabel("x = "), 2, 0, Qt.AlignRight)
        scalingLayout.addWidget(self.xmEdit, 2, 1)  # , Qt.AlignRight)
        scalingLayout.addWidget(QLabel("y = "), 2, 2, Qt.AlignRight)
        scalingLayout.addWidget(self.ymEdit, 2, 3)  # , Qt.AlignRight)
        scalingLayout.addWidget(scalingCoefLabel, 3, 0, 1, 4)
        scalingLayout.addWidget(QLabel("kx = "), 4, 0, Qt.AlignRight)
        scalingLayout.addWidget(self.kxEdit, 4, 1)  # , Qt.AlignRight)
        scalingLayout.addWidget(QLabel("ky = "), 4, 2, Qt.AlignRight)
        scalingLayout.addWidget(self.kyEdit, 4, 3)  # , Qt.AlignRight)
        scalingLayout.addWidget(scalingButton, 5, 0, 1, 4)

        # Rotation Layout

        rotationLayout = QGridLayout()

        rotationLayout.addWidget(rotationLabel, 0, 0, 1, 4)

        rotationLayout.addWidget(rotationPointLabel, 1, 0, 1, 4)

        rotationLayout.addWidget(QLabel("x = "), 2, 0, Qt.AlignRight)
        rotationLayout.addWidget(self.xcEdit, 2, 1)  # , Qt.AlignRight)
        rotationLayout.addWidget(QLabel("y = "), 2, 2, Qt.AlignRight)
        rotationLayout.addWidget(self.ycEdit, 2, 3)  # , Qt.AlignRight)

        rotationLayout.addWidget(rotationAngleLabel, 3, 0, 1, 4)

        rotationLayout.addWidget(QLabel("Угол = "), 4, 0, 1, 2, Qt.AlignRight)
        rotationLayout.addWidget(self.fiEdit, 4, 2)  # , Qt.AlignRight)

        rotationLayout.addWidget(rotationBut, 5, 0, 1, 4)

        # Group Box

        carryGB = QGroupBox()
        carryGB.setLayout(carryLayout)
        scalingGB = QGroupBox()
        scalingGB.setLayout(scalingLayout)
        rotationGB = QGroupBox()
        rotationGB.setLayout(rotationLayout)

        rightGB = QGroupBox()
        rightLayout = QVBoxLayout()

        rightLayout.addWidget(carryGB)
        rightLayout.addWidget(scalingGB)
        rightLayout.addWidget(rotationGB)

        rightGB.setLayout(rightLayout)

        # Main Window

        mainLayout.setColumnStretch(0, 3)
        # mainLayout.setColumnStretch(3, 1)
        mainLayout.addWidget(self.renderArea, 0, 0, 4, 4)
        # mainLayout.setRowMinimumHeight(1, 6)

        mainLayout.addWidget(rightGB, 0, 4)

        self.setLayout(mainLayout)

        self.setGeometry(500, 300, 800, 600)
        self.setWindowTitle("Lab_02")

    def carryButtonClicked(self):
        try:
            dx = float(self.dxEdit.text())
            dy = float(self.dyEdit.text())

            self.renderArea.carry_picture(dx, dy)

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    def scalingButtonClicked(self):
        try:
            x = float(self.xmEdit.text())
            y = float(self.ymEdit.text())

            kx = float(self.kxEdit.text())
            ky = float(self.kyEdit.text())

            self.renderArea.scale_picture(x, y, kx, ky)

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    def rotationButtonClicked(self):
        try:
            x = float(self.xcEdit.text())
            y = float(self.ycEdit.text())
            fi = float(self.fiEdit.text())

            self.renderArea.rotate_picture(x, y, fi)

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
