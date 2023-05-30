#include <iostream>

#include "ZorkUL.h"


int main(int argc, char *argv[]) {
    ZorkUL temp;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
