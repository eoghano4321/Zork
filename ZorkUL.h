#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
#include <QApplication>


using namespace std;

class ZorkUL {
private:
    Parser parser;
    Inventory invent;
    Room *currentRoom;
    void createRooms();
    void printWelcome();


public:
    ZorkUL();
    void play();
};

#endif /*ZORKUL_H_*/
