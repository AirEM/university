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
        MainWindow.resize(798, 600)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy)
        self.widget.setObjectName("widget")
        self.gridLayout = QtWidgets.QGridLayout(self.widget)
        self.gridLayout.setObjectName("gridLayout")
        self.label_4 = QtWidgets.QLabel(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 2, 0, 1, 1)
        self.colorBox = QtWidgets.QComboBox(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.colorBox.sizePolicy().hasHeightForWidth())
        self.colorBox.setSizePolicy(sizePolicy)
        self.colorBox.setObjectName("colorBox")
        self.gridLayout.addWidget(self.colorBox, 2, 1, 1, 1)
        self.tabWidget = QtWidgets.QTabWidget(self.widget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        self.tabWidget.setObjectName("tabWidget")
        self.circleTab = QtWidgets.QWidget()
        self.circleTab.setObjectName("circleTab")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.circleTab)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label = QtWidgets.QLabel(self.circleTab)
        self.label.setObjectName("label")
        self.gridLayout_2.addWidget(self.label, 0, 0, 1, 1)
        self.radiusEdit = QtWidgets.QLineEdit(self.circleTab)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(15)
        sizePolicy.setVerticalStretch(15)
        sizePolicy.setHeightForWidth(self.radiusEdit.sizePolicy().hasHeightForWidth())
        self.radiusEdit.setSizePolicy(sizePolicy)
        self.radiusEdit.setObjectName("radiusEdit")
        self.gridLayout_2.addWidget(self.radiusEdit, 0, 1, 1, 1)
        self.tabWidget.addTab(self.circleTab, "")
        self.elipseTab = QtWidgets.QWidget()
        self.elipseTab.setObjectName("elipseTab")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.elipseTab)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.label_2 = QtWidgets.QLabel(self.elipseTab)
        self.label_2.setObjectName("label_2")
        self.gridLayout_3.addWidget(self.label_2, 0, 0, 1, 1)
        self.xEdit = QtWidgets.QLineEdit(self.elipseTab)
        self.xEdit.setMaximumSize(QtCore.QSize(100, 16777215))
        self.xEdit.setObjectName("xEdit")
        self.gridLayout_3.addWidget(self.xEdit, 0, 1, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.elipseTab)
        self.label_3.setObjectName("label_3")
        self.gridLayout_3.addWidget(self.label_3, 1, 0, 1, 1)
        self.yEdit = QtWidgets.QLineEdit(self.elipseTab)
        self.yEdit.setMaximumSize(QtCore.QSize(100, 16777215))
        self.yEdit.setObjectName("yEdit")
        self.gridLayout_3.addWidget(self.yEdit, 1, 1, 1, 1)
        self.tabWidget.addTab(self.elipseTab, "")
        self.gridLayout.addWidget(self.tabWidget, 0, 0, 1, 2)
        self.drawButton = QtWidgets.QPushButton(self.widget)
        self.drawButton.setObjectName("drawButton")
        self.gridLayout.addWidget(self.drawButton, 3, 0, 1, 2)
        self.testButton = QtWidgets.QPushButton(self.widget)
        self.testButton.setObjectName("testButton")
        self.gridLayout.addWidget(self.testButton, 5, 0, 1, 2)
        self.cleanButton = QtWidgets.QPushButton(self.widget)
        self.cleanButton.setObjectName("cleanButton")
        self.gridLayout.addWidget(self.cleanButton, 6, 0, 1, 2)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 7, 0, 1, 1)
        self.groupBox = QtWidgets.QGroupBox(self.widget)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.groupBox)
        self.verticalLayout.setObjectName("verticalLayout")
        self.rb_0 = QtWidgets.QRadioButton(self.groupBox)
        self.rb_0.setObjectName("rb_0")
        self.verticalLayout.addWidget(self.rb_0)
        self.rb_1 = QtWidgets.QRadioButton(self.groupBox)
        self.rb_1.setObjectName("rb_1")
        self.verticalLayout.addWidget(self.rb_1)
        self.rb_2 = QtWidgets.QRadioButton(self.groupBox)
        self.rb_2.setObjectName("rb_2")
        self.verticalLayout.addWidget(self.rb_2)
        self.rb_3 = QtWidgets.QRadioButton(self.groupBox)
        self.rb_3.setObjectName("rb_3")
        self.verticalLayout.addWidget(self.rb_3)
        self.rb_4 = QtWidgets.QRadioButton(self.groupBox)
        self.rb_4.setObjectName("rb_4")
        self.verticalLayout.addWidget(self.rb_4)
        self.gridLayout.addWidget(self.groupBox, 1, 0, 1, 2)
        self.horizontalLayout.addWidget(self.widget)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 798, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_4.setText(_translate("MainWindow", "Цвет"))
        self.label.setText(_translate("MainWindow", "Радиус"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.circleTab), _translate("MainWindow", "Окружность"))
        self.label_2.setText(_translate("MainWindow", "Полуось X"))
        self.label_3.setText(_translate("MainWindow", "Полуось Y"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.elipseTab), _translate("MainWindow", "Эллипс"))
        self.drawButton.setText(_translate("MainWindow", "Отрисовать"))
        self.testButton.setText(_translate("MainWindow", "Тест"))
        self.cleanButton.setText(_translate("MainWindow", "Очистить"))
        self.groupBox.setTitle(_translate("MainWindow", "Алгоритм"))
        self.rb_0.setText(_translate("MainWindow", "Алгоритм Брезенхейма"))
        self.rb_1.setText(_translate("MainWindow", "Алгоритм средней точки"))
        self.rb_2.setText(_translate("MainWindow", "Параметрическое уравнение"))
        self.rb_3.setText(_translate("MainWindow", "Каноническое уравнение"))
        self.rb_4.setText(_translate("MainWindow", "Библиотечный алгоритм"))

