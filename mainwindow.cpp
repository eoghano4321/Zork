#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    outputLbl = findChild<QLabel *>("Output");
    inputLbl = findChild<QLineEdit *>("Input");

    QObject::connect(ui->NorthButton, &QPushButton::pressed, this, &MainWindow::goNorth);
    QObject::connect(ui->SouthButton, &QPushButton::pressed, this, &MainWindow::goSouth);
    QObject::connect(ui->WestButton, &QPushButton::pressed, this, &MainWindow::goWest);
    QObject::connect(ui->EastButton, &QPushButton::pressed, this, &MainWindow::goEast);
    QObject::connect(ui->Submit, &QPushButton::pressed, this, &MainWindow::submitLine);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goNorth(){
    MainWindow::setOutputText("North");
    //outputLbl->setText("north");
}
void MainWindow::goSouth(){
    MainWindow::setOutputText("south");
}
void MainWindow::goEast(){
    MainWindow::setOutputText("east");
}
void MainWindow::goWest(){
    MainWindow::setOutputText("west");
}

void MainWindow::submitLine(){
    inputTxt = inputLbl->text();
    parser.inputStr = inputTxt.toStdString();
    cout << parser.inputStr << endl;
    Command* command = parser.getCommand();
    bool finished = false;
    finished = cp.processCommand(*command);
    inputTxt = QString::fromStdString(cp.outputStr);
    MainWindow::setOutputText(inputTxt);
    if(finished){
        exit(0);
    }
}


void MainWindow::setOutputText(QString str){
    outputLbl->setText(str);
}
