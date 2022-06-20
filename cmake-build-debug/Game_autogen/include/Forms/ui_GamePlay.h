/********************************************************************************
** Form generated from reading UI file 'gameplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPLAY_H
#define UI_GAMEPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePlay
{
public:

    void setupUi(QWidget *GamePlay)
    {
        if (GamePlay->objectName().isEmpty())
            GamePlay->setObjectName(QString::fromUtf8("GamePlay"));
        GamePlay->resize(1280, 800);

        retranslateUi(GamePlay);

        QMetaObject::connectSlotsByName(GamePlay);
    } // setupUi

    void retranslateUi(QWidget *GamePlay)
    {
        GamePlay->setWindowTitle(QCoreApplication::translate("GamePlay", "GamePlay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePlay: public Ui_GamePlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPLAY_H
