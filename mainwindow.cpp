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

    roomLbl = findChild<QLabel *>("Room");

    MainWindow::printWelcome();
    MainWindow::updateCurr();
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

void MainWindow::printWelcome() {
    MainWindow::setOutputText("start\n info for help");
}

void MainWindow::goNorth(){
    cp.goRoom("north");
    MainWindow::setOutputText(QString::fromStdString(cp.outputStr));
    MainWindow::updateCurr();
}
void MainWindow::goSouth(){
    cp.goRoom("south");
    MainWindow::setOutputText(QString::fromStdString(cp.outputStr));
    MainWindow::updateCurr();
}
void MainWindow::goEast(){
    cp.goRoom("east");
    MainWindow::setOutputText(QString::fromStdString(cp.outputStr));
    MainWindow::updateCurr();
}
void MainWindow::goWest(){
    cp.goRoom("west");
    MainWindow::setOutputText(QString::fromStdString(cp.outputStr));
    MainWindow::updateCurr();
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
    MainWindow::updateCurr();
    if(finished){
        exit(0);
    }
}


void MainWindow::updateCurr(){
    if(cp.currentRoom->shortDescription().compare("Win") == 0){
        roomLbl->setText("Freedom");
        MainWindow::setOutputText("You've won\n\nEnter quit to close");
    }
    else
        roomLbl->setText("Current room:\n"+ QString::fromStdString(cp.currentRoom->longDescription()));
}

void MainWindow::setOutputText(QString str){
    outputLbl->setText(str);
}
