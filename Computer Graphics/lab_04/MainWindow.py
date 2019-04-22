from gui import Ui_MainWindow
from RenderArea import RenderArea

from PyQt5.QtWidgets import (QApplication, QMainWindow, QMessageBox,
                             QGroupBox, QLabel, QGridLayout, QLineEdit)
from PyQt5.QtCore import Qt


class Window(QMainWindow):

    def __init__(self):
        super(Window, self).__init__()

        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.alg = 0

        self.ui.renderArea = RenderArea()

        self.ui.horizontalLayout.addWidget(self.ui.renderArea)

        self.ui.colorBox.addItem("Черный", 0)
        self.ui.colorBox.addItem("Красный", 1)
        self.ui.colorBox.addItem("Зеленый", 2)
        self.ui.colorBox.addItem("Синий", 3)
        self.ui.colorBox.addItem("Желтый", 4)
        self.ui.colorBox.addItem("Белый", 5)

        self.ui.rb_0.setChecked(True)
        self.ui.rb_0.toggled.connect(lambda: self.set_alg(0))
        self.ui.rb_1.toggled.connect(lambda: self.set_alg(1))
        self.ui.rb_2.toggled.connect(lambda: self.set_alg(2))
        self.ui.rb_3.toggled.connect(lambda: self.set_alg(3))
        self.ui.rb_4.toggled.connect(lambda: self.set_alg(4))

        GroupBox = QGroupBox("Тест")
        rightLayout = QGridLayout()

        self.ui.minREdit = QLineEdit()
        self.ui.minREdit.setFixedWidth(30)

        self.ui.maxREdit = QLineEdit()
        self.ui.maxREdit.setFixedWidth(30)

        self.ui.countREdit = QLineEdit()
        self.ui.countREdit.setFixedWidth(30)

        rightLayout.addWidget(QLabel("Мин R : "), 0, 0, 1, 2, Qt.AlignRight)
        rightLayout.addWidget(self.ui.minREdit, 0, 2, 1, 2)

        rightLayout.addWidget(QLabel("Макс R : "), 1, 0, 1, 2, Qt.AlignRight)
        rightLayout.addWidget(self.ui.maxREdit, 1, 2, 1, 2)

        rightLayout.addWidget(QLabel("Кол-во : "), 2, 0, 1, 2, Qt.AlignRight)
        rightLayout.addWidget(self.ui.countREdit, 2, 2, 1, 2)

        GroupBox.setLayout(rightLayout)

        self.ui.gridLayout.addWidget(GroupBox, 1, 0, 1, 2)

        self.ui.drawButton.clicked.connect(self.drawButtonClicked)
        self.ui.testButton.clicked.connect(self.testButtonClicked)
        self.ui.cleanButton.clicked.connect(self.cleanButtonClicked)

    def drawButtonClicked(self):

        try:
            color = self.ui.colorBox.itemData(self.ui.colorBox.currentIndex())
            figure = self.ui.tabWidget.currentIndex()

            if figure:
                a = float(self.ui.xEdit.text())
                b = float(self.ui.yEdit.text())
                self.ui.renderArea.createFigure(figure, color, self.alg, a=round(a), b=round(b))
            else:
                r = float(self.ui.radiusEdit.text())
                self.ui.renderArea.createFigure(figure, color, self.alg, r=round(r))

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    def testButtonClicked(self):

        try:
            minR = float(self.ui.minREdit.text())
            maxR = float(self.ui.maxREdit.text())
            countR = int(self.ui.countREdit.text())

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

        color = self.ui.colorBox.itemData(self.ui.colorBox.currentIndex())
        figure = self.ui.tabWidget.currentIndex()

        self.ui.renderArea.test(figure, color, self.alg, minR, maxR, countR)

    def cleanButtonClicked(self):
        self.ui.renderArea.clean_all()

    def set_alg(self, alg):
        self.alg = alg


if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
