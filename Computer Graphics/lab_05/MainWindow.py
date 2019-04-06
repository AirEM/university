import sys
from gui import Ui_MainWindow
from RenderArea import RenderArea

from PyQt5.QtWidgets import (QApplication, QMainWindow, QMessageBox)


class Window(QMainWindow):

    def __init__(self):
        super(Window, self).__init__()

        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.ui.renderArea = RenderArea(self.ui.pointsListWidget)

        self.ui.horizontalLayout.addWidget(self.ui.renderArea)

        self.ui.drawButton.clicked.connect(self.drawButtonClicked)
        self.ui.closeButton.clicked.connect(self.closeButtonClicked)
        self.ui.cleanButton.clicked.connect(self.cleanButtonClicked)


    def drawButtonClicked(self):

        try:
            slow = self.ui.slowCheckBox.isChecked()

            self.ui.renderArea.fill(slow)

        except ValueError:
            msg = QMessageBox(self)
            msg.setIcon(QMessageBox.Critical)
            msg.setText("Некорректное заполнение полей")
            msg.setWindowTitle("Ошибка заполнения полей")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.show()

    def closeButtonClicked(self):
        self.ui.renderArea.close_figure()

    def cleanButtonClicked(self):
        self.ui.renderArea.clean_all()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())
