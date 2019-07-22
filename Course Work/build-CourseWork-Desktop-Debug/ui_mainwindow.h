/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *rightFrame;
    QVBoxLayout *verticalLayout;
    QFrame *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadPushButton;
    QPushButton *savePushButton;
    QGroupBox *moveGroupBox;
    QGridLayout *gridLayout;
    QLabel *dyLabel;
    QLineEdit *dyLineEdit;
    QLabel *dxLabel;
    QLineEdit *dxLineEdit;
    QLabel *dzLabel;
    QLineEdit *dzLineEdit;
    QPushButton *movePushButton;
    QGroupBox *scalingGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *kxLabel;
    QLineEdit *kzLineEdit;
    QLineEdit *kyLineEdit;
    QLabel *kyLabel;
    QLineEdit *kxLineEdit;
    QLabel *kzLabel;
    QPushButton *scalingPushButton;
    QGroupBox *rotationGroupBox;
    QGridLayout *gridLayout_3;
    QLineEdit *fixLineEdit;
    QLabel *fizLabel;
    QLineEdit *fizLineEdit;
    QLabel *fixLabel;
    QLabel *fiyLabel;
    QLineEdit *fiyLineEdit;
    QPushButton *rotationPushButton;
    QPushButton *cleanPushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1069, 680);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rightFrame = new QFrame(centralWidget);
        rightFrame->setObjectName(QStringLiteral("rightFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rightFrame->sizePolicy().hasHeightForWidth());
        rightFrame->setSizePolicy(sizePolicy1);
        rightFrame->setFrameShape(QFrame::StyledPanel);
        rightFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(rightFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        buttonFrame = new QFrame(rightFrame);
        buttonFrame->setObjectName(QStringLiteral("buttonFrame"));
        buttonFrame->setFrameShape(QFrame::StyledPanel);
        buttonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadPushButton = new QPushButton(buttonFrame);
        loadPushButton->setObjectName(QStringLiteral("loadPushButton"));

        horizontalLayout_2->addWidget(loadPushButton);

        savePushButton = new QPushButton(buttonFrame);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));

        horizontalLayout_2->addWidget(savePushButton);


        verticalLayout->addWidget(buttonFrame);

        moveGroupBox = new QGroupBox(rightFrame);
        moveGroupBox->setObjectName(QStringLiteral("moveGroupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(moveGroupBox->sizePolicy().hasHeightForWidth());
        moveGroupBox->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(moveGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dyLabel = new QLabel(moveGroupBox);
        dyLabel->setObjectName(QStringLiteral("dyLabel"));
        dyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dyLabel, 0, 2, 1, 1);

        dyLineEdit = new QLineEdit(moveGroupBox);
        dyLineEdit->setObjectName(QStringLiteral("dyLineEdit"));
        dyLineEdit->setMinimumSize(QSize(35, 0));
        dyLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout->addWidget(dyLineEdit, 0, 3, 1, 1);

        dxLabel = new QLabel(moveGroupBox);
        dxLabel->setObjectName(QStringLiteral("dxLabel"));
        dxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dxLabel, 0, 0, 1, 1);

        dxLineEdit = new QLineEdit(moveGroupBox);
        dxLineEdit->setObjectName(QStringLiteral("dxLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dxLineEdit->sizePolicy().hasHeightForWidth());
        dxLineEdit->setSizePolicy(sizePolicy3);
        dxLineEdit->setMinimumSize(QSize(35, 0));
        dxLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout->addWidget(dxLineEdit, 0, 1, 1, 1);

        dzLabel = new QLabel(moveGroupBox);
        dzLabel->setObjectName(QStringLiteral("dzLabel"));
        dzLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dzLabel, 0, 4, 1, 1);

        dzLineEdit = new QLineEdit(moveGroupBox);
        dzLineEdit->setObjectName(QStringLiteral("dzLineEdit"));
        dzLineEdit->setMinimumSize(QSize(35, 0));
        dzLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout->addWidget(dzLineEdit, 0, 5, 1, 1);

        movePushButton = new QPushButton(moveGroupBox);
        movePushButton->setObjectName(QStringLiteral("movePushButton"));

        gridLayout->addWidget(movePushButton, 1, 0, 1, 3);


        verticalLayout->addWidget(moveGroupBox);

        scalingGroupBox = new QGroupBox(rightFrame);
        scalingGroupBox->setObjectName(QStringLiteral("scalingGroupBox"));
        sizePolicy2.setHeightForWidth(scalingGroupBox->sizePolicy().hasHeightForWidth());
        scalingGroupBox->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(scalingGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        kxLabel = new QLabel(scalingGroupBox);
        kxLabel->setObjectName(QStringLiteral("kxLabel"));
        kxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(kxLabel, 0, 0, 1, 1);

        kzLineEdit = new QLineEdit(scalingGroupBox);
        kzLineEdit->setObjectName(QStringLiteral("kzLineEdit"));
        sizePolicy3.setHeightForWidth(kzLineEdit->sizePolicy().hasHeightForWidth());
        kzLineEdit->setSizePolicy(sizePolicy3);
        kzLineEdit->setMinimumSize(QSize(35, 0));
        kzLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(kzLineEdit, 0, 7, 1, 1);

        kyLineEdit = new QLineEdit(scalingGroupBox);
        kyLineEdit->setObjectName(QStringLiteral("kyLineEdit"));
        sizePolicy3.setHeightForWidth(kyLineEdit->sizePolicy().hasHeightForWidth());
        kyLineEdit->setSizePolicy(sizePolicy3);
        kyLineEdit->setMinimumSize(QSize(35, 0));
        kyLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(kyLineEdit, 0, 4, 1, 1);

        kyLabel = new QLabel(scalingGroupBox);
        kyLabel->setObjectName(QStringLiteral("kyLabel"));
        kyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(kyLabel, 0, 2, 1, 1);

        kxLineEdit = new QLineEdit(scalingGroupBox);
        kxLineEdit->setObjectName(QStringLiteral("kxLineEdit"));
        sizePolicy3.setHeightForWidth(kxLineEdit->sizePolicy().hasHeightForWidth());
        kxLineEdit->setSizePolicy(sizePolicy3);
        kxLineEdit->setMinimumSize(QSize(35, 0));
        kxLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(kxLineEdit, 0, 1, 1, 1);

        kzLabel = new QLabel(scalingGroupBox);
        kzLabel->setObjectName(QStringLiteral("kzLabel"));
        kzLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(kzLabel, 0, 5, 1, 1);

        scalingPushButton = new QPushButton(scalingGroupBox);
        scalingPushButton->setObjectName(QStringLiteral("scalingPushButton"));

        gridLayout_2->addWidget(scalingPushButton, 1, 0, 1, 3);


        verticalLayout->addWidget(scalingGroupBox);

        rotationGroupBox = new QGroupBox(rightFrame);
        rotationGroupBox->setObjectName(QStringLiteral("rotationGroupBox"));
        sizePolicy2.setHeightForWidth(rotationGroupBox->sizePolicy().hasHeightForWidth());
        rotationGroupBox->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(rotationGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        fixLineEdit = new QLineEdit(rotationGroupBox);
        fixLineEdit->setObjectName(QStringLiteral("fixLineEdit"));
        sizePolicy3.setHeightForWidth(fixLineEdit->sizePolicy().hasHeightForWidth());
        fixLineEdit->setSizePolicy(sizePolicy3);
        fixLineEdit->setMinimumSize(QSize(35, 0));
        fixLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_3->addWidget(fixLineEdit, 0, 1, 1, 1);

        fizLabel = new QLabel(rotationGroupBox);
        fizLabel->setObjectName(QStringLiteral("fizLabel"));
        fizLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(fizLabel, 2, 0, 1, 1);

        fizLineEdit = new QLineEdit(rotationGroupBox);
        fizLineEdit->setObjectName(QStringLiteral("fizLineEdit"));
        sizePolicy3.setHeightForWidth(fizLineEdit->sizePolicy().hasHeightForWidth());
        fizLineEdit->setSizePolicy(sizePolicy3);
        fizLineEdit->setMinimumSize(QSize(35, 0));
        fizLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_3->addWidget(fizLineEdit, 2, 1, 1, 1);

        fixLabel = new QLabel(rotationGroupBox);
        fixLabel->setObjectName(QStringLiteral("fixLabel"));
        fixLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(fixLabel, 0, 0, 1, 1);

        fiyLabel = new QLabel(rotationGroupBox);
        fiyLabel->setObjectName(QStringLiteral("fiyLabel"));
        fiyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(fiyLabel, 0, 2, 1, 1);

        fiyLineEdit = new QLineEdit(rotationGroupBox);
        fiyLineEdit->setObjectName(QStringLiteral("fiyLineEdit"));
        sizePolicy3.setHeightForWidth(fiyLineEdit->sizePolicy().hasHeightForWidth());
        fiyLineEdit->setSizePolicy(sizePolicy3);
        fiyLineEdit->setMinimumSize(QSize(35, 0));
        fiyLineEdit->setMaximumSize(QSize(35, 16777215));

        gridLayout_3->addWidget(fiyLineEdit, 0, 4, 1, 1);

        rotationPushButton = new QPushButton(rotationGroupBox);
        rotationPushButton->setObjectName(QStringLiteral("rotationPushButton"));

        gridLayout_3->addWidget(rotationPushButton, 3, 0, 1, 2);


        verticalLayout->addWidget(rotationGroupBox);

        cleanPushButton = new QPushButton(rightFrame);
        cleanPushButton->setObjectName(QStringLiteral("cleanPushButton"));

        verticalLayout->addWidget(cleanPushButton);


        horizontalLayout->addWidget(rightFrame, 0, Qt::AlignTop);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1069, 20));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        loadPushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214(TEST)", nullptr));
        savePushButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        moveGroupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        dyLabel->setText(QApplication::translate("MainWindow", "dy = ", nullptr));
        dxLabel->setText(QApplication::translate("MainWindow", "dx = ", nullptr));
        dzLabel->setText(QApplication::translate("MainWindow", "dz = ", nullptr));
        movePushButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        scalingGroupBox->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        kxLabel->setText(QApplication::translate("MainWindow", "kx = ", nullptr));
        kyLabel->setText(QApplication::translate("MainWindow", "ky = ", nullptr));
        kzLabel->setText(QApplication::translate("MainWindow", "kz = ", nullptr));
        scalingPushButton->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        rotationGroupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        fizLabel->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273(0z) =", nullptr));
        fixLabel->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273(0x) =", nullptr));
        fiyLabel->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273(0y) =", nullptr));
        rotationPushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        cleanPushButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
