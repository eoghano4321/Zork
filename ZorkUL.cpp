#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
    Inventory* invent = new Inventory();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;
    Item *x;


    x = new Item("x", 1, 11);
    x->setWeight(22);
    a = new Room("Start Room");
        a->addItem(x);
        a->addItem(new Item("y", 2, 22));
    b = new Room("Corridor");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("T Junction");
    d = new Room("Cellar");
    e = new Room("Corner");
    f = new Room("T Junction 2");
    g = new Room("Perpendicular");
    h = new Room("Key Room");
        h->addItem(new Item("Key", 1, 100));
    i = new Room("Corner 2");
        i->addItem(new Item("map", 1, 1));
    j = new Room("Atrium");
        j->addItem(new Item("gun", 2, 10));
    k = new Room("Are you reading these");
    l = new Room("Corner 3");
    m = new Room("Another Corner");
    n = new Room("Wow a corner");
    o = new Room("Corridor");
    p = new Room("The end?");

//             (N, E, S, W)
    a->setExits(NULL, b, NULL, NULL);
    b->setExits(NULL, c, NULL, a);
    c->setExits(NULL, e, g, d);
    d->setExits(NULL, c, NULL, NULL);
    e->setExits(NULL, NULL, i, f);
    f->setExits(NULL, e, j, g);
    g->setExits(c, f, k, NULL);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[a] -- [b] -- [c] -- [d]  " << endl;
        cout << "               |          " << endl;
        cout << "               |          " << endl;
        cout << "[e] -- [f] -- [g]    [key]" << endl;
        cout << " |      |      |      |   " << endl;
        cout << " |      |      |      |   " << endl;
        cout << "[i] -- [j] -- [k] -- [l]  " << endl;
        cout << "        |                 " << endl;
        cout << "        |                 " << endl;
        cout << "[m] -- [n]                " << endl;
        cout << " |                        " << endl;
        cout << " |                        " << endl;
        cout << "[o]                       " << endl;
        cout << " |                        " << endl;
        cout << " |                        " << endl;
        cout << "[p]                       " << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            invent.addItem(new Item(command.getSecondWord(), currentRoom->getWeightofItem(), currentRoom->getValofItem()));
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    else if (commandWord.compare("inventory") == 0)
    {
        printInv();
    }

    else if (commandWord.compare("describe") == 0){
        describeItem(command);
    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

void ZorkUL::describeItem(Command command){
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string item = command.getSecondWord();

    if(invent.isItemInInv(item) == 0){
        cout << "No item exists" << "\n";
    }else{
        invent.describe(item);
    }
}

void ZorkUL::printInv(){
    invent.printInv();
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
