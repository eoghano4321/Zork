#include <iostream>

//using namespace std;
#include "ZorkUL.h"


int main(int argc, char *argv[]) {
    ZorkUL temp;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    temp.play();
    Inventory* invent = new Inventory();

    return a.exec();
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

    /////////////////////////////////////////////////////////
    /// Refer to the comments made at getLine in parser for what I should do with this
    /////////////////////////////////////////////////////////

    bool finished = false;
//    while (!finished) {
//        // Create pointer to command and give it a command.
//        Command* command = parser.getCommand();
//        // Pass dereferenced command and check for end of game.
//        finished = processCommand(*command);
//        // Free the memory allocated by "parser.getCommand()"
//        //   with ("return new Command(...)")
//        delete command;
//    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}
