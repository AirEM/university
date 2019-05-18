from Figure import Figure
from PyQt5.QtCore import QPoint, QSize, Qt, QEvent
from PyQt5.QtGui import QPainter, QPixmap, QPalette, QPen, QKeyEvent
from PyQt5.QtWidgets import QWidget
import time


class RenderArea(QWidget):

    def __init__(self, pListWidget):
        super().__init__()

        self.pointsListWidget = pListWidget

        self.colors = [Qt.black, Qt.blue, Qt.red]

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
        pen = QPen(Qt.black)
        p.setPen(pen)

        self.figure.draw(p)

        p.end()

        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(QPoint(), self.pixmap)

    def fill(self, color, slow=False):

        state = True
        current_color = self.colors[color]

        if not self.figure.is_close():
            return

        count = 0
        while state:
            # begin while
            count += 1

            p = QPainter(self.pixmap)
            pen = QPen(current_color)
            p.setPen(pen)

            state = self.figure.fill((300, 300), p, self.pixmap.toImage(), current_color)

            p.end()

            if slow:
                time.sleep(0.01)
                self.repaint()
            else:
                self.update()
            # end while

    def close_figure(self):
        self.figure.close()
        self.draw()
        self.figure.set_close(True)

    def clean_all(self):
        self.pixmap = QPixmap(self.size())
        self.pixmap.fill()

        self.figure.clean()

        self.pointsListWidget.clear()

        self.update()
