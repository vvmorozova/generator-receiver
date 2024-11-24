/********************************************************************************
** Form generated from reading UI file 'receiverui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVERUI_H
#define UI_RECEIVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiverUI
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *rangeTextEdit;
    QPlainTextEdit *beforeTextEdit;
    QPlainTextEdit *afterTextEdit;
    QPlainTextEdit *logsTextEdit;
    QSpinBox *spinBoxIDFrom;
    QSpinBox *spinBoxIDTo;
    QSpinBox *spinBoxTransposeID;
    QPushButton *showMatrixesRangeBtn;
    QPushButton *transposeBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReceiverUI)
    {
        if (ReceiverUI->objectName().isEmpty())
            ReceiverUI->setObjectName("ReceiverUI");
        ReceiverUI->resize(800, 471);
        centralwidget = new QWidget(ReceiverUI);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 141, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 10, 121, 18));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 10, 66, 18));
        rangeTextEdit = new QPlainTextEdit(centralwidget);
        rangeTextEdit->setObjectName("rangeTextEdit");
        rangeTextEdit->setGeometry(QRect(10, 120, 141, 291));
        beforeTextEdit = new QPlainTextEdit(centralwidget);
        beforeTextEdit->setObjectName("beforeTextEdit");
        beforeTextEdit->setGeometry(QRect(160, 120, 161, 291));
        afterTextEdit = new QPlainTextEdit(centralwidget);
        afterTextEdit->setObjectName("afterTextEdit");
        afterTextEdit->setGeometry(QRect(330, 120, 181, 291));
        logsTextEdit = new QPlainTextEdit(centralwidget);
        logsTextEdit->setObjectName("logsTextEdit");
        logsTextEdit->setGeometry(QRect(520, 40, 271, 371));
        spinBoxIDFrom = new QSpinBox(centralwidget);
        spinBoxIDFrom->setObjectName("spinBoxIDFrom");
        spinBoxIDFrom->setGeometry(QRect(10, 30, 141, 27));
        spinBoxIDTo = new QSpinBox(centralwidget);
        spinBoxIDTo->setObjectName("spinBoxIDTo");
        spinBoxIDTo->setGeometry(QRect(10, 60, 141, 27));
        spinBoxTransposeID = new QSpinBox(centralwidget);
        spinBoxTransposeID->setObjectName("spinBoxTransposeID");
        spinBoxTransposeID->setGeometry(QRect(160, 30, 111, 27));
        showMatrixesRangeBtn = new QPushButton(centralwidget);
        showMatrixesRangeBtn->setObjectName("showMatrixesRangeBtn");
        showMatrixesRangeBtn->setGeometry(QRect(10, 90, 141, 26));
        transposeBtn = new QPushButton(centralwidget);
        transposeBtn->setObjectName("transposeBtn");
        transposeBtn->setGeometry(QRect(160, 90, 161, 26));
        ReceiverUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReceiverUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ReceiverUI->setMenuBar(menubar);
        statusbar = new QStatusBar(ReceiverUI);
        statusbar->setObjectName("statusbar");
        ReceiverUI->setStatusBar(statusbar);

        retranslateUi(ReceiverUI);

        QMetaObject::connectSlotsByName(ReceiverUI);
    } // setupUi

    void retranslateUi(QMainWindow *ReceiverUI)
    {
        ReceiverUI->setWindowTitle(QCoreApplication::translate("ReceiverUI", "ReceiverUI", nullptr));
        label->setText(QCoreApplication::translate("ReceiverUI", "matrixes range by ID", nullptr));
        label_2->setText(QCoreApplication::translate("ReceiverUI", "transpose matrix", nullptr));
        label_3->setText(QCoreApplication::translate("ReceiverUI", "logs", nullptr));
        showMatrixesRangeBtn->setText(QCoreApplication::translate("ReceiverUI", "Show", nullptr));
        transposeBtn->setText(QCoreApplication::translate("ReceiverUI", "Transpose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiverUI: public Ui_ReceiverUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVERUI_H
