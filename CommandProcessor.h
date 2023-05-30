#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <iostream>

#include "Command.h"
#include "Parser.h"
#include "Inventory.h"
#include "Room.h"

class CommandProcessor
{
private:
    friend class MainWindow;
    string outputStr;
    Parser parser;
    Inventory invent;
    void createRooms();
    Room *currentRoom;
    void printHelp();
    void goRoom(string dir);
    bool processCommand(Command command);
    void describeItem(Command command);
    void createItems();
    void displayItems();
    void printInv();
    void take(Command command);
    void put(Command command);
    void keyCheck();
    string setCurrRoom(Room* nextRoom);
    CommandProcessor();
    Room *p, *o, *w;
};

#endif // COMMANDPROCESSOR_H
