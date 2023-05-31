
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Item.h"

using namespace std;
using std::vector;

class Inventory{
private:
    vector <Item> itemsInInv;
    int maxWeight;
    int currWeight;
    int currVal;
    int lastWeight;
    int lastVal;
    inline void remWV(Item *inItem);
    inline void addWV(Item *inItem);

public:
    int numberOfItems();
    Inventory();
    void addItem(Item *inItem);
    string displayItem();
    int isItemInInv(Item *inItem);
    void removeItemFromInv(int location);
    string printInv();
    int getWeight();
    int getVal();
    int getLastWeight();
    int getLastVal();
    void setWeight(int weight);
    void setVal(int val);
    string describe(int location);

};

#endif // INVENTORY_H
