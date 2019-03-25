from PyQt5.QtWidgets import QLabel
from PyQt5.QtGui import QPixmap, QPalette, QPainter, QPen
from PyQt5.QtCore import Qt, QSize, QPoint


class RenderArea(QLabel):

    def __init__(self):
        super().__init__()

        self.points = None

        '''
        self.algorithm = alg_b_real_numb
        self.algorithms = {0: alg_b_real_numb,
                           1: alg_b_whole_numb,
                           2: alg_b_modified,
                           3: alg_cda,
                           4: alg_lib}
        '''

        self.color = Qt.black
        self.colors = {0: Qt.black,
                       1: Qt.red,
                       2: Qt.green,
                       3: Qt.blue,
                       4: Qt.yellow}

        self.pixmap = QPixmap()  # self.size()).scaled(800, 600, Qt.IgnoreAspectRatio)
        self.pixmap.fill() # Qt.transparent)

        self.setBackgroundRole(QPalette.Base)
        self.setAutoFillBackground(True)

    def minimumSizeHint(self):
        return QSize(800, 600)

    def resizeEvent(self, *args, **kwargs):
        self.pixmap.scaled(self.width(), self.height(), Qt.IgnoreAspectRatio)
        # pixmap.fill();
        # draw();
        # this->update();

    def sizeHint(self):
        return QSize(800, 600)

    def clean_all(self):
        self.pixmap = QPixmap(self.size())
        self.pixmap.fill(Qt.transparent)

        self.update()

    def createLine(self, xb, yb, xe, ye, color, alg):
        self.color = self.colors[color]
        self.points = [(xb, yb,), (xe, ye)]
        # self.algorithm = self.algorithms[alg]

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
        painter.drawPixmap(QPoint(0, 0), self.pixmap)
