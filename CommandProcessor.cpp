#include "CommandProcessor.h"

CommandProcessor::CommandProcessor()
{
    createRooms();
}

void CommandProcessor::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n;
    Item *x;

    Item *key = new Key("Key");
    key->setWeight(42);
    key->setValue(42);

    x = new Item("x", 1, 11);
    x->setWeight(22);
    a = new Room("Start Room (a)");
    a->addItem(x);
    a->addItem(new Item("y", 2, 22));
    b = new Room("Corridor (b)");
    b->addItem(new Item("xx", 3, 33));
    b->addItem(new Item("yy", 4, 44));
    c = new Room("T Junction (c)");
    d = new Room("Cellar (d)");
    e = new Room("Corner (e)");
    f = new Room("T Junction (f)");
    g = new Room("Perpendicular (g)");
    h = new Room("Key Room (h)");
    h->addItem(key);
    i = new Room("Corner (i)");
    i->addItem(new Item("map", 1, 1));
    j = new Room("Atrium (j)");
    j->addItem(new Item("gun", 2, 10));
    k = new Room("Are you reading these (k)");
    l = new Room("Corner (l)");
    m = new Room("Another Corner (m)");
    n = new Room("Wow a corner (n)");
    o = new Room("Corridor (o)");
    p = new Room("The end? (p)");
    w = new Room("Win");

    //             (N, E, S, W)
    a->setExits(NULL, b, NULL, NULL);
    b->setExits(NULL, c, NULL, a);
    c->setExits(NULL, d, g, b);
    d->setExits(NULL, NULL, NULL, c);
    e->setExits(NULL, f, i, NULL);
    f->setExits(NULL, g, j, e);
    g->setExits(c, NULL, k, f);
    h->setExits(NULL, NULL, l, NULL);
    i->setExits(e, j, NULL, NULL);
    j->setExits(f, k, n, i);
    k->setExits(g, l, NULL, j);
    l->setExits(h, NULL, NULL, k);
    m->setExits(NULL, n, o, NULL);
    n->setExits(j, NULL, NULL, m);
    o->setExits(n, NULL, p, NULL);
    p->setExits(o, NULL, NULL, NULL);

    currentRoom = a;

}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool CommandProcessor::processCommand(Command command) {
    if (command.isUnknown()) {
        outputStr = "invalid input";
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
    {
        outputStr = "You really thought I'd give you a map in a maze game?";
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

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            outputStr = "incomplete input\n";
            cout << "incomplete input"<< endl;
        }
        else
            take(command);
    }

    else if (commandWord.compare("put") == 0)
    {
        if (!command.hasSecondWord()) {
            outputStr = "incomplete input\n";
            cout << "incomplete input"<< endl;
        }
        else
            put(command);
    }

    else if (commandWord.compare("inventory") == 0)
    {
        printInv();
    }

    else if (commandWord.compare("describe") == 0){
        describeItem(command);
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord()){
            outputStr = "overdefined input";
            cout << "overdefined input"<< endl;
        }
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void CommandProcessor::printHelp() {
    cout << "valid inputs are: " << endl;
    parser.showCommands();
    outputStr = "valid inputs are:\n" + parser.outputStr;
}


void CommandProcessor::goRoom(string dir) {
    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(dir);

    if (nextRoom == NULL){
        outputStr = "underdefined input\n";
        cout << "underdefined input"<< endl;
    }
    else {
        outputStr = "went " + dir;
        cout << setCurrRoom(nextRoom) << endl;
    }
}

void CommandProcessor::describeItem(Command command){
    if (!command.hasSecondWord()) {
        outputStr = "incomplete input\n";
        cout << "incomplete input"<< endl;
        return;
    }
    Item *inItem;
    if(command.getSecondWord().compare("Key") == 0)
        inItem = new Key("Key");
    else
        inItem = new Item(command.getSecondWord(), 1, 1);
    int loc = invent.isItemInInv(inItem);
    if(loc == -1){
        outputStr = "No item exists\n";
        cout << "No item exists" << "\n";
    }
    else {
        if(inItem->canRemove()){
            outputStr = invent.describe(loc);
            cout << invent.describe(loc) << endl;
        }
        else{
            outputStr = invent.describe(loc) + " Use this to open the exit in room p";
            cout << invent.describe(loc) << " Use this to open the exit in room p" << endl;
        }
    }
    delete inItem;
}

void CommandProcessor::printInv(){
    outputStr = invent.printInv();
    cout << invent.printInv();
}


string CommandProcessor::setCurrRoom(Room* nextRoom){
    currentRoom = nextRoom;
    return currentRoom->longDescription();
}

void CommandProcessor::take(Command command){
    outputStr = "you're trying to take " + command.getSecondWord() + "\n\n";
    cout << "you're trying to take " << command.getSecondWord() << endl;
    Item* inItem = new Item(command.getSecondWord());
    int location = currentRoom->isItemInRoom(inItem);
    if (location  < 0 ){
        outputStr += "item is not in room\n";
        cout << "item is not in room" << endl;
    }
    else{
        outputStr += "item is in room\n";
        cout << "item is in room" << endl;
        currentRoom->removeItemFromRoom(location);

        invent.addItem(new Item(command.getSecondWord(), currentRoom->getWeightofItem(), currentRoom->getValofItem()));
        outputStr += "\n" + currentRoom->longDescription();
        cout << currentRoom->longDescription() << endl;
    }
    if(command.getSecondWord().compare("Key") == 0){
        keyCheck();
    }
    delete inItem;
}

void CommandProcessor::put(Command command){
    outputStr = "you're trying to put " + command.getSecondWord() + "\n";
    cout << "you're trying to put " << command.getSecondWord() << endl;
    Item *inItem;
    if(command.getSecondWord().compare("Key") == 0)
        inItem = new Key("Key");
    else
        inItem = new Item(command.getSecondWord(), 1, 1);
    int location = invent.isItemInInv(inItem);
    cout << "Located at " << location << endl;
    if (location  == -1 ){
        outputStr = " item is not in inventory\n";
        cout << " item is not in inventory" << endl;
    }
    else if (location >= 0){
        if(inItem->canRemove()){
            outputStr = " item is in inventory\n";
            cout << " item is in inventory" << endl;

            invent.removeItemFromInv(location);
            inItem->setWeight(invent.getLastWeight());
            inItem->setValue(invent.getLastVal());

            currentRoom->addItem(inItem);
        }
        else{
            outputStr = " item is in inventory but cannot be removed\n";
            cout << " item is in inventory but cannot be removed" << endl;
        }
    }
    outputStr += "\n" + currentRoom->longDescription();
    cout << currentRoom->longDescription() << endl;
}

void CommandProcessor::keyCheck(){
    Item* key = new Key("Key");
    if(invent.isItemInInv(key) != -1){
        p->setExits(o, NULL, w, NULL);
    }
    delete key;
}
