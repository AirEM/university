# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'gui.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(905, 671)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.centralwidget.sizePolicy().hasHeightForWidth())
        self.centralwidget.setSizePolicy(sizePolicy)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.leftFrame = QtWidgets.QFrame(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.leftFrame.sizePolicy().hasHeightForWidth())
        self.leftFrame.setSizePolicy(sizePolicy)
        self.leftFrame.setMinimumSize(QtCore.QSize(180, 0))
        self.leftFrame.setMaximumSize(QtCore.QSize(180, 16777215))
        self.leftFrame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.leftFrame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.leftFrame.setObjectName("leftFrame")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.leftFrame)
        self.verticalLayout.setObjectName("verticalLayout")
        self.pointsListWidget = QtWidgets.QListWidget(self.leftFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pointsListWidget.sizePolicy().hasHeightForWidth())
        self.pointsListWidget.setSizePolicy(sizePolicy)
        self.pointsListWidget.setObjectName("pointsListWidget")
        self.verticalLayout.addWidget(self.pointsListWidget)
        self.z_groupBox = QtWidgets.QGroupBox(self.leftFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.z_groupBox.sizePolicy().hasHeightForWidth())
        self.z_groupBox.setSizePolicy(sizePolicy)
        self.z_groupBox.setMinimumSize(QtCore.QSize(0, 10))
        self.z_groupBox.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.z_groupBox.setObjectName("z_groupBox")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.z_groupBox)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label = QtWidgets.QLabel(self.z_groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setMaximumSize(QtCore.QSize(15, 16777215))
        self.label.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.label.setObjectName("label")
        self.horizontalLayout_3.addWidget(self.label)
        self.zx_lineEdit = QtWidgets.QLineEdit(self.z_groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(15)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.zx_lineEdit.sizePolicy().hasHeightForWidth())
        self.zx_lineEdit.setSizePolicy(sizePolicy)
        self.zx_lineEdit.setMinimumSize(QtCore.QSize(30, 0))
        self.zx_lineEdit.setMaximumSize(QtCore.QSize(45, 16777215))
        self.zx_lineEdit.setObjectName("zx_lineEdit")
        self.horizontalLayout_3.addWidget(self.zx_lineEdit)
        self.label_2 = QtWidgets.QLabel(self.z_groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy)
        self.label_2.setMaximumSize(QtCore.QSize(15, 16777215))
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_3.addWidget(self.label_2)
        self.zy_lineEdit = QtWidgets.QLineEdit(self.z_groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(15)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.zy_lineEdit.sizePolicy().hasHeightForWidth())
        self.zy_lineEdit.setSizePolicy(sizePolicy)
        self.zy_lineEdit.setMinimumSize(QtCore.QSize(30, 0))
        self.zy_lineEdit.setMaximumSize(QtCore.QSize(45, 16777215))
        self.zy_lineEdit.setObjectName("zy_lineEdit")
        self.horizontalLayout_3.addWidget(self.zy_lineEdit)
        self.verticalLayout.addWidget(self.z_groupBox)
        self.slowCheckBox = QtWidgets.QCheckBox(self.leftFrame)
        self.slowCheckBox.setObjectName("slowCheckBox")
        self.verticalLayout.addWidget(self.slowCheckBox)
        self.colorBox = QtWidgets.QComboBox(self.leftFrame)
        self.colorBox.setObjectName("colorBox")
        self.verticalLayout.addWidget(self.colorBox)
        self.drawButton = QtWidgets.QPushButton(self.leftFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.drawButton.sizePolicy().hasHeightForWidth())
        self.drawButton.setSizePolicy(sizePolicy)
        self.drawButton.setObjectName("drawButton")
        self.verticalLayout.addWidget(self.drawButton)
        self.closeButton = QtWidgets.QPushButton(self.leftFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.closeButton.sizePolicy().hasHeightForWidth())
        self.closeButton.setSizePolicy(sizePolicy)
        self.closeButton.setObjectName("closeButton")
        self.verticalLayout.addWidget(self.closeButton)
        self.cleanButton = QtWidgets.QPushButton(self.leftFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.cleanButton.sizePolicy().hasHeightForWidth())
        self.cleanButton.setSizePolicy(sizePolicy)
        self.cleanButton.setObjectName("cleanButton")
        self.verticalLayout.addWidget(self.cleanButton)
        self.horizontalLayout.addWidget(self.leftFrame)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 905, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.z_groupBox.setTitle(_translate("MainWindow", "Затравочный Пиксель"))
        self.label.setText(_translate("MainWindow", "X : "))
        self.label_2.setText(_translate("MainWindow", "Y : "))
        self.slowCheckBox.setText(_translate("MainWindow", "Задержка"))
        self.drawButton.setText(_translate("MainWindow", "Закрасить"))
        self.closeButton.setText(_translate("MainWindow", "Замкнуть"))
        self.cleanButton.setText(_translate("MainWindow", "Очистить"))


