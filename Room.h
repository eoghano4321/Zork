#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    string description;
    int weightOfLastItem;
    float valOfLastItem;
    map<string, Room*> exits;
    string exitString();
    vector <Item> itemsInRoom;



public:
    int numberOfItems();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(Item *inItem);
    int getWeightofItem();
    float getValofItem();
    void removeItemFromRoom(int location);
    bool isWin();
    bool operator==(const Room &other) const;
};

#endif
