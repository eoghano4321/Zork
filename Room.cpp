#include "Room.h"
#include "Command.h"

///////////////////////////////////////////////////////////////
///                      Room System                        ///
///////////////////////////////////////////////////////////////

Room::Room(string description) {
    this->description = description;
    weightOfLastItem = 0;
    valOfLastItem = 0;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
    return "Room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
    string returnString = "\nExits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
        // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "Items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "No items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
        }
    }
    return tempString;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(Item* inItem)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        for (int x = 0; x < sizeItems; x++) {
            if (*inItem == itemsInRoom[x]) {
                return x;
            }
        }
    }
    return -1;
}

int Room::getWeightofItem()
{
    return weightOfLastItem;
}

float Room::getValofItem()
{
    return valOfLastItem;
}

void Room::removeItemFromRoom(int location){
    this->weightOfLastItem = itemsInRoom[location].getWeight();
    this->valOfLastItem = itemsInRoom[location].getValue();
    itemsInRoom.erase(itemsInRoom.begin()+location);
}

bool Room::operator==(const Room &other) const {
    return description == other.description;
}
