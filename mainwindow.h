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
    void goNorth();
    void goSouth();
    void goWest();
    void goEast();
    void setOutputText(QString str);
    void submitLine();
    QString inputTxt;
    QLabel* outputLbl;
    QLineEdit* inputLbl;
    Parser parser;
    CommandProcessor cp;

private:
    Ui::MainWindow *ui;
    QString str;
};
#endif // MAINWINDOW_H
