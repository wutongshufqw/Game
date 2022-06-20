//
// Created by y on 2022/6/20.
//

#ifndef GAME_MAINWINDOW_H
#define GAME_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Mainwindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::Mainwindow *ui;
};


#endif //GAME_MAINWINDOW_H
