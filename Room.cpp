#include "Room.h"
#include "Command.h"

///////////////////////////////////////////////////////////////
///                      Room System                        ///
///////////////////////////////////////////////////////////////

/// Methods
/**
* Create a room object
* Set the room at each of north, east, south and west exits
* Return the name of the room
* Return the name of the room and the items in it
* Return a list of any available exits
* Set image to display
* Return the next room in any direction
* Add an item to the room
* Return the item in the room - used in the longDescription list
* Return the number of items in the room
* Check if an item is in the room
* Return the weight of the last item - IDK what this would be used for
* Return the value of the last item
*/

/// TODO
/**
* Allow users to put items from inventory into the room - This would likely be done in the main file though
* Create a gui for the room using the images I created
*     - Potentially create an image id by appending the directions to the end of the file name to instanciate in set Exits
*/

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
	return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
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
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
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

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                this->weightOfLastItem = itemsInRoom[x].getWeight();
                this->valOfLastItem = itemsInRoom[x].getValue();
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
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

