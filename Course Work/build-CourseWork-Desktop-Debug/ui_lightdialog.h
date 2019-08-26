/********************************************************************************
** Form generated from reading UI file 'lightdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTDIALOG_H
#define UI_LIGHTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LightDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *positionGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *xLabel;
    QLineEdit *xLineEdit;
    QLabel *yLabel;
    QLineEdit *yLineEdit;
    QLabel *zLabel;
    QLineEdit *zLineEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *intensityLabel;
    QLineEdit *intensityLineEdit;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *pushButton;

    void setupUi(QDialog *LightDialog)
    {
        if (LightDialog->objectName().isEmpty())
            LightDialog->setObjectName(QStringLiteral("LightDialog"));
        LightDialog->resize(285, 290);
        LightDialog->setMinimumSize(QSize(285, 233));
        LightDialog->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(LightDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LightDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        positionGroupBox = new QGroupBox(LightDialog);
        positionGroupBox->setObjectName(QStringLiteral("positionGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(positionGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        xLabel = new QLabel(positionGroupBox);
        xLabel->setObjectName(QStringLiteral("xLabel"));

        horizontalLayout_2->addWidget(xLabel);

        xLineEdit = new QLineEdit(positionGroupBox);
        xLineEdit->setObjectName(QStringLiteral("xLineEdit"));

        horizontalLayout_2->addWidget(xLineEdit);

        yLabel = new QLabel(positionGroupBox);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        horizontalLayout_2->addWidget(yLabel);

        yLineEdit = new QLineEdit(positionGroupBox);
        yLineEdit->setObjectName(QStringLiteral("yLineEdit"));

        horizontalLayout_2->addWidget(yLineEdit);

        zLabel = new QLabel(positionGroupBox);
        zLabel->setObjectName(QStringLiteral("zLabel"));

        horizontalLayout_2->addWidget(zLabel);

        zLineEdit = new QLineEdit(positionGroupBox);
        zLineEdit->setObjectName(QStringLiteral("zLineEdit"));

        horizontalLayout_2->addWidget(zLineEdit);


        verticalLayout->addWidget(positionGroupBox);

        groupBox = new QGroupBox(LightDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        intensityLabel = new QLabel(groupBox);
        intensityLabel->setObjectName(QStringLiteral("intensityLabel"));

        horizontalLayout_3->addWidget(intensityLabel);

        intensityLineEdit = new QLineEdit(groupBox);
        intensityLineEdit->setObjectName(QStringLiteral("intensityLineEdit"));

        horizontalLayout_3->addWidget(intensityLineEdit);


        verticalLayout->addWidget(groupBox);

        frame = new QFrame(LightDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addPushButton = new QPushButton(frame);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(frame);


        retranslateUi(LightDialog);

        QMetaObject::connectSlotsByName(LightDialog);
    } // setupUi

    void retranslateUi(QDialog *LightDialog)
    {
        LightDialog->setWindowTitle(QApplication::translate("LightDialog", "Light", nullptr));
        label->setText(QApplication::translate("LightDialog", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        positionGroupBox->setTitle(QApplication::translate("LightDialog", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        xLabel->setText(QApplication::translate("LightDialog", "X =", nullptr));
        yLabel->setText(QApplication::translate("LightDialog", "Y =", nullptr));
        zLabel->setText(QApplication::translate("LightDialog", "Z =", nullptr));
        groupBox->setTitle(QApplication::translate("LightDialog", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214", nullptr));
        intensityLabel->setText(QApplication::translate("LightDialog", "I =", nullptr));
        addPushButton->setText(QApplication::translate("LightDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("LightDialog", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LightDialog: public Ui_LightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTDIALOG_H
