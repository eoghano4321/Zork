#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <iostream>

#include "Command.h"
#include "Parser.h"
#include "Inventory.h"
#include "Room.h"

class CommandProcessor
{
public:
    string outputStr;
    Parser parser;
    Inventory invent;
    Room *currentRoom;
    void printWelcome();
    void printHelp();
    void goRoom(Command command);
    bool processCommand(Command command);
    void describeItem(Command command);
    void createItems();
    void displayItems();
    void printInv();
    string go(string direction);
    string setCurrRoom(Room* nextRoom);
    CommandProcessor();
};

#endif // COMMANDPROCESSOR_H
