
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"

using namespace std;
using std::vector;

class Inventory{
private:
    vector <Item> itemsInInv;
    int maxWeight;
    int currWeight;
    friend class Character;

public:
    int numberOfItems();
    Inventory();
    void addItem(Item *inItem);
    string displayItem();
    int isItemInInv(string inString);
    void removeItemFromInv(string inString); //Item itemToRem);
    string printInv();
    int getWeight();
    void setWeight(int weight);
    void describe(string inString);

};

#endif // INVENTORY_H
