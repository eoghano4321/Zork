#include "CommandProcessor.h"

CommandProcessor::CommandProcessor()
{

}


void CommandProcessor::printWelcome() {
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
bool CommandProcessor::processCommand(Command command) {
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
void CommandProcessor::printHelp() {
    cout << "valid inputs are: " << endl;
    parser.showCommands();
    outputStr = "valid inputs are:\n" + parser.outputStr;
}


void CommandProcessor::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        outputStr = "incomplete input\n";
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL){
        outputStr = "underdefined input\n";
        cout << "underdefined input"<< endl;
    }
    else {
        //currentRoom = nextRoom;
        cout << CommandProcessor::setCurrRoom(nextRoom) << endl;
    }
}

void CommandProcessor::describeItem(Command command){
    if (!command.hasSecondWord()) {
        outputStr = "incomplete input\n";
        cout << "incomplete input"<< endl;
        return;
    }

    string item = command.getSecondWord();

    if(invent.isItemInInv(item) == 0){
        outputStr = "No item exists\n";
        cout << "No item exists" << "\n";
    }else{
        invent.describe(item);
    }
}

void CommandProcessor::printInv(){
    outputStr = invent.printInv();
    cout << invent.printInv();
}

string CommandProcessor::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        //currentRoom = nextRoom;
        return CommandProcessor::setCurrRoom(nextRoom);
    }
}


string CommandProcessor::setCurrRoom(Room* nextRoom){
    currentRoom = nextRoom;
    return currentRoom->longDescription();
}
