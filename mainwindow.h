#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#include "CommandProcessor.h"
#include "Command.h"
#include "Parser.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printWelcome();
    void updateCurr();
    void goNorth();
    void goSouth();
    void goWest();
    void goEast();
    void go(string dir);
    void setOutputText(QString str);
    void submitLine();

private:
    QString inputTxt;
    QLabel* outputLbl;
    QLabel* roomLbl;
    QLineEdit* inputLbl;

    Parser parser;
    CommandProcessor cp;

    Ui::MainWindow *ui;
    QString str;
};
#endif // MAINWINDOW_H
