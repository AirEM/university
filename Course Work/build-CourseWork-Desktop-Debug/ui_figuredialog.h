/********************************************************************************
** Form generated from reading UI file 'figuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGUREDIALOG_H
#define UI_FIGUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FigureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *figureTabWidget;
    QWidget *sphereTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *sphereCentreGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *xSphereLabel;
    QLineEdit *xSphereLineEdit;
    QLabel *ySphereLabel;
    QLineEdit *ySphereLineEdit;
    QLabel *zSphereLabel;
    QLineEdit *zSphereLineEdit;
    QGroupBox *sphereRadiusGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *radiusSphereLabel;
    QLineEdit *radiusSphereLineEdit;
    QGroupBox *sphereColorGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *redSphereLabel;
    QLineEdit *redSphereLineEdit;
    QLabel *greenSphereLabel;
    QLineEdit *greenSphereLineEdit;
    QLabel *blueSphereLabel;
    QLineEdit *blueSphereLineEdit;
    QWidget *cubeTab;
    QWidget *coneTab;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *canselPushButton;

    void setupUi(QDialog *FigureDialog)
    {
        if (FigureDialog->objectName().isEmpty())
            FigureDialog->setObjectName(QStringLiteral("FigureDialog"));
        FigureDialog->resize(311, 360);
        verticalLayout = new QVBoxLayout(FigureDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(FigureDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        figureTabWidget = new QTabWidget(FigureDialog);
        figureTabWidget->setObjectName(QStringLiteral("figureTabWidget"));
        sphereTab = new QWidget();
        sphereTab->setObjectName(QStringLiteral("sphereTab"));
        verticalLayout_2 = new QVBoxLayout(sphereTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sphereCentreGroupBox = new QGroupBox(sphereTab);
        sphereCentreGroupBox->setObjectName(QStringLiteral("sphereCentreGroupBox"));
        horizontalLayout_3 = new QHBoxLayout(sphereCentreGroupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        xSphereLabel = new QLabel(sphereCentreGroupBox);
        xSphereLabel->setObjectName(QStringLiteral("xSphereLabel"));

        horizontalLayout_3->addWidget(xSphereLabel);

        xSphereLineEdit = new QLineEdit(sphereCentreGroupBox);
        xSphereLineEdit->setObjectName(QStringLiteral("xSphereLineEdit"));

        horizontalLayout_3->addWidget(xSphereLineEdit);

        ySphereLabel = new QLabel(sphereCentreGroupBox);
        ySphereLabel->setObjectName(QStringLiteral("ySphereLabel"));

        horizontalLayout_3->addWidget(ySphereLabel);

        ySphereLineEdit = new QLineEdit(sphereCentreGroupBox);
        ySphereLineEdit->setObjectName(QStringLiteral("ySphereLineEdit"));

        horizontalLayout_3->addWidget(ySphereLineEdit);

        zSphereLabel = new QLabel(sphereCentreGroupBox);
        zSphereLabel->setObjectName(QStringLiteral("zSphereLabel"));

        horizontalLayout_3->addWidget(zSphereLabel);

        zSphereLineEdit = new QLineEdit(sphereCentreGroupBox);
        zSphereLineEdit->setObjectName(QStringLiteral("zSphereLineEdit"));

        horizontalLayout_3->addWidget(zSphereLineEdit);


        verticalLayout_2->addWidget(sphereCentreGroupBox);

        sphereRadiusGroupBox = new QGroupBox(sphereTab);
        sphereRadiusGroupBox->setObjectName(QStringLiteral("sphereRadiusGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(sphereRadiusGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radiusSphereLabel = new QLabel(sphereRadiusGroupBox);
        radiusSphereLabel->setObjectName(QStringLiteral("radiusSphereLabel"));

        horizontalLayout_2->addWidget(radiusSphereLabel);

        radiusSphereLineEdit = new QLineEdit(sphereRadiusGroupBox);
        radiusSphereLineEdit->setObjectName(QStringLiteral("radiusSphereLineEdit"));

        horizontalLayout_2->addWidget(radiusSphereLineEdit);


        verticalLayout_2->addWidget(sphereRadiusGroupBox);

        sphereColorGroupBox = new QGroupBox(sphereTab);
        sphereColorGroupBox->setObjectName(QStringLiteral("sphereColorGroupBox"));
        horizontalLayout_4 = new QHBoxLayout(sphereColorGroupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        redSphereLabel = new QLabel(sphereColorGroupBox);
        redSphereLabel->setObjectName(QStringLiteral("redSphereLabel"));

        horizontalLayout_4->addWidget(redSphereLabel);

        redSphereLineEdit = new QLineEdit(sphereColorGroupBox);
        redSphereLineEdit->setObjectName(QStringLiteral("redSphereLineEdit"));

        horizontalLayout_4->addWidget(redSphereLineEdit);

        greenSphereLabel = new QLabel(sphereColorGroupBox);
        greenSphereLabel->setObjectName(QStringLiteral("greenSphereLabel"));

        horizontalLayout_4->addWidget(greenSphereLabel);

        greenSphereLineEdit = new QLineEdit(sphereColorGroupBox);
        greenSphereLineEdit->setObjectName(QStringLiteral("greenSphereLineEdit"));

        horizontalLayout_4->addWidget(greenSphereLineEdit);

        blueSphereLabel = new QLabel(sphereColorGroupBox);
        blueSphereLabel->setObjectName(QStringLiteral("blueSphereLabel"));

        horizontalLayout_4->addWidget(blueSphereLabel);

        blueSphereLineEdit = new QLineEdit(sphereColorGroupBox);
        blueSphereLineEdit->setObjectName(QStringLiteral("blueSphereLineEdit"));

        horizontalLayout_4->addWidget(blueSphereLineEdit);


        verticalLayout_2->addWidget(sphereColorGroupBox);

        figureTabWidget->addTab(sphereTab, QString());
        cubeTab = new QWidget();
        cubeTab->setObjectName(QStringLiteral("cubeTab"));
        figureTabWidget->addTab(cubeTab, QString());
        coneTab = new QWidget();
        coneTab->setObjectName(QStringLiteral("coneTab"));
        figureTabWidget->addTab(coneTab, QString());

        verticalLayout->addWidget(figureTabWidget);

        widget = new QWidget(FigureDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addPushButton = new QPushButton(widget);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        canselPushButton = new QPushButton(widget);
        canselPushButton->setObjectName(QStringLiteral("canselPushButton"));

        horizontalLayout->addWidget(canselPushButton);


        verticalLayout->addWidget(widget);


        retranslateUi(FigureDialog);

        figureTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FigureDialog);
    } // setupUi

    void retranslateUi(QDialog *FigureDialog)
    {
        FigureDialog->setWindowTitle(QApplication::translate("FigureDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("FigureDialog", "\320\244\320\270\320\263\321\203\321\200\321\213", nullptr));
        sphereCentreGroupBox->setTitle(QApplication::translate("FigureDialog", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        xSphereLabel->setText(QApplication::translate("FigureDialog", "X =", nullptr));
        ySphereLabel->setText(QApplication::translate("FigureDialog", "Y =", nullptr));
        zSphereLabel->setText(QApplication::translate("FigureDialog", "Z =", nullptr));
        sphereRadiusGroupBox->setTitle(QApplication::translate("FigureDialog", "\320\240\320\260\320\264\320\270\321\203\321\201", nullptr));
        radiusSphereLabel->setText(QApplication::translate("FigureDialog", "R =", nullptr));
        sphereColorGroupBox->setTitle(QApplication::translate("FigureDialog", "\320\246\320\262\320\265\321\202", nullptr));
        redSphereLabel->setText(QApplication::translate("FigureDialog", "R =", nullptr));
        greenSphereLabel->setText(QApplication::translate("FigureDialog", "G =", nullptr));
        blueSphereLabel->setText(QApplication::translate("FigureDialog", "B =", nullptr));
        figureTabWidget->setTabText(figureTabWidget->indexOf(sphereTab), QApplication::translate("FigureDialog", "\320\241\321\204\320\265\321\200\320\260", nullptr));
        figureTabWidget->setTabText(figureTabWidget->indexOf(cubeTab), QApplication::translate("FigureDialog", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        figureTabWidget->setTabText(figureTabWidget->indexOf(coneTab), QApplication::translate("FigureDialog", "Tab 2", nullptr));
        addPushButton->setText(QApplication::translate("FigureDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        canselPushButton->setText(QApplication::translate("FigureDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FigureDialog: public Ui_FigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGUREDIALOG_H
