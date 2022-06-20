//
// Created by y on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Mainwindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::Mainwindow) {
    ui->setupUi(this);
    this->setStyleSheet("background-image:url(:/mainwindow/background.jpg)");
}

MainWindow::~MainWindow() {
    delete ui;
}
