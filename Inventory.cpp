#include "Inventory.h"

///////////////////////////////////////////////////////////////
///                  Inventory System                       ///
///////////////////////////////////////////////////////////////

// Create the empty inventory with a current combined weight of 0
// Max weight is the weight until the user is unable to move - Can be augmented potentially through the collection of a backpack
Inventory::Inventory(){
    currWeight = 0;
    currVal = 0;
    maxWeight = 50;
    lastWeight = 0;
    lastVal = 0;
}


// Print the items in the inventory and the current weight over the max weight when the "inventory" command is entered
string Inventory::printInv() {
    string tempString = "items in inventory = ";
    int sizeItems = (itemsInInv.size());
    if (itemsInInv.size() < 1) {
        tempString = "no items in inventory";
    }
    else if (itemsInInv.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInInv[x].getShortDescription() + "  " ;
            x++;
        }
    }
    tempString = tempString + "\n";
    tempString = tempString + "Weight : " + to_string(currWeight) + "\n"; //+ to_string(maxWeight) + "\n";
    return tempString;
}

void Inventory::setWeight(int weight){
    currWeight = weight;
}

int Inventory::getWeight(){
    return currWeight;
}

void Inventory::setVal(int val){
    currVal = val;
}

int Inventory::getVal(){
    return currVal;
}

inline void Inventory::remWV(Item* inItem){
    lastWeight = inItem->getWeight();
    lastVal = inItem->getValue();
    setWeight(currWeight - lastWeight);
    setVal(currVal - lastVal);
}

inline void Inventory::addWV(Item* inItem){
    int weight = inItem->getWeight();
    int val = inItem->getValue();
    setWeight(currWeight + weight);
    setVal(currVal + val);
}

void Inventory::addItem(Item *inItem){
    // Could potentially make you have to leave an item down so you dont go too heavy
    addWV(inItem);
    itemsInInv.push_back(*inItem);
}

void Inventory::removeItemFromInv(int location){
    if (location >= 0 && location < itemsInInv.size()) {
        remWV(&itemsInInv[location]);
        itemsInInv.erase(itemsInInv.begin() + location);
    }
    else{
        cout << "invalid - Inventory::removeItemFromInv(int location)" << endl;
    }
}


int Inventory::isItemInInv(Item *inItem)
{
    int sizeItems = (itemsInInv.size());
    if (itemsInInv.size() < 1) {
        return -1;
    }
    else if (itemsInInv.size() > 0) {
        for (int x = 0; x < sizeItems; x++) {
            if (*inItem == itemsInInv[x]) {
                return x;
            }
        }
    }
    return -1;
}

string Inventory::describe(int location){
    string descript;
    descript = itemsInInv[location].getLongDescription();

    cout << "Item: " << descript << "\n";
    return descript;
}


int Inventory::getLastWeight(){
    return lastWeight;
}


int Inventory::getLastVal(){
    return lastVal;
}
