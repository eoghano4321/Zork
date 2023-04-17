#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Inventory.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
	Parser parser;
    Inventory invent;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void describeItem(Command command);
    void createItems();
    void displayItems();
    void printInv();

public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
