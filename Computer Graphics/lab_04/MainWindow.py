from gui import Ui_MainWindow
from RenderArea import RenderArea
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox


class Window(QMainWindow):

    def __init__(self):
        super(Window, self).__init__()

        self.alg = 0

        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.renderArea = RenderArea()

        self.ui.horizontalLayout.addWidget(self.renderArea)

        self.ui.colorBox.addItem("Черный", 0)
        self.ui.colorBox.addItem("Красный", 1)
        self.ui.colorBox.addItem("Зеленый", 2)
        self.ui.colorBox.addItem("Синий", 3)
        self.ui.colorBox.addItem("Желтый", 4)

        self.ui.rb_0.toggled.connect(lambda: self.set_alg(0))
        self.ui.rb_1.toggled.connect(lambda: self.set_alg(1))
        self.ui.rb_2.toggled.connect(lambda: self.set_alg(2))
        self.ui.rb_3.toggled.connect(lambda: self.set_alg(3))
        self.ui.rb_4.toggled.connect(lambda: self.set_alg(4))

        # self.ui.testButton.clicked.connect(self.tab_test)

    def drawButtonClicked(self):

        try:
            # xb = float(self.xbEdit.text())
            # yb = self.renderArea.height() - float(self.ybEdit.text())
            # xe = float(self.xeEdit.text())
            # ye = self.renderArea.height() - float(self.yeEdit.text())

            color = self.ui.colorBox.itemData(self.ui.colorBox.currentIndex())
            figure = self.ui.tabWidget.currentIndex()

            # self.renderArea.createLine(round(xb), round(yb),
                                       # round(xe), round(ye), color, self.alg)

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    '''
    def testButtonClicked(self):
        color = self.colorComboBox.itemData(self.colorComboBox.currentIndex())
        self.renderArea.createSun(color, self.alg)

    def cleanButtonClicked(self):
        self.renderArea.clean_all()
    '''

    def set_alg(self, alg):
        self.alg = alg


if __name__ == '__main__':
    import sys

    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
