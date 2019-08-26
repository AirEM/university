/********************************************************************************
** Form generated from reading UI file 'spheredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHEREDIALOG_H
#define UI_SPHEREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SphereDialog
{
public:
    QPushButton *addPushButton;

    void setupUi(QDialog *SphereDialog)
    {
        if (SphereDialog->objectName().isEmpty())
            SphereDialog->setObjectName(QStringLiteral("SphereDialog"));
        SphereDialog->resize(240, 320);
        addPushButton = new QPushButton(SphereDialog);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));
        addPushButton->setGeometry(QRect(70, 250, 80, 21));

        retranslateUi(SphereDialog);

        QMetaObject::connectSlotsByName(SphereDialog);
    } // setupUi

    void retranslateUi(QDialog *SphereDialog)
    {
        SphereDialog->setWindowTitle(QApplication::translate("SphereDialog", "Dialog", nullptr));
        addPushButton->setText(QApplication::translate("SphereDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SphereDialog: public Ui_SphereDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHEREDIALOG_H
