#include "Inventory.h"

Inventory::Inventory(){
    currWeight = 0;
    maxWeight = 50;
}

void Inventory::printInv() {
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
    tempString = tempString + "Weight : " + to_string(currWeight) + " / " + to_string(maxWeight) + "\n";
    cout << tempString;
}

void Inventory::setWeight(int weight){
    currWeight = weight;
}

int Inventory::getWeight(){
    return currWeight;
}

void Inventory::addItem(Item *inItem){
    int weight = inItem->getWeight();
    setWeight(currWeight + weight);
    itemsInInv.push_back(*inItem);
}

int Inventory::isItemInInv(string inString)
{
    int sizeItems = (itemsInInv.size());
    if (itemsInInv.size() < 1) {
        return 0;
        }
    else if (itemsInInv.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            int tempFlag = inString.compare( itemsInInv[x].getShortDescription());
            if (tempFlag == 0) {
                return 1;
            }
            x++;
            }
        }
    return 0;
}

void Inventory::describe(string inString){
    string descript;
    int x = (0);
    for (int n = itemsInInv.size(); n > 0; n--) {
            int tempFlag = inString.compare( itemsInInv[x].getShortDescription());
            if (tempFlag == 0) {
            descript = itemsInInv[x].getLongDescription();
            }
            x++;
    }

    cout << "Item: " << descript << "\n";
}
