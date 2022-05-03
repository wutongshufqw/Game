/********************************************************************************
** Form generated from reading UI file 'a.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A_H
#define UI_A_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_A
{
public:

    void setupUi(QWidget *A)
    {
        if (A->objectName().isEmpty())
            A->setObjectName(QString::fromUtf8("A"));
        A->resize(400, 300);

        retranslateUi(A);

        QMetaObject::connectSlotsByName(A);
    } // setupUi

    void retranslateUi(QWidget *A)
    {
        A->setWindowTitle(QApplication::translate("A", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A: public Ui_A {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A_H
