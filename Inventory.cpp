#include "Inventory.h"

///////////////////////////////////////////////////////////////
///                  Inventory System                       ///
///////////////////////////////////////////////////////////////

/// Methods
/**
* Create empty inventory
* Print items in inventory
* Add items to inventory
* Remove items from inventory
* Get and Set current combined weight of inventory
* Set max weight of inventory
* Tell the character controller when the current weight has exceeded the max weight
*     -> Could (and maybe should) make the inventory a friend of the character - Could then simply store items in an array in inventory as
*        opposed to having to loop through it itself every time I want to add or remove an item
*/

/// TODO
/**
* Make sure print inventory is clean and follows c++ design principles
* Add inventory items as a friend of character
* Add a set max weight function
* Add functionality to remove an item from the inventory and remove its weight from currWeight
*/


// Create the empty inventory with a current combined weight of 0
// Max weight is the weight until the user is unable to move - Can be augmented potentially through the collection of a backpack
Inventory::Inventory(){
    currWeight = 0;
    maxWeight = 50;
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
    tempString = tempString + "Weight : " + to_string(currWeight) + " / " + to_string(maxWeight) + "\n";
    return tempString;
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

void Inventory::removeItemFromInv(string inString){
    if(isItemInInv(inString) == 1){
        int weight = 2; // Need to get the weight of the item that has been removed from the inventory
        // Could do this by instead of returning true/false for in inventory check return the items weight instead
        // Need to find way of doing this in a C++ design style
    }
    else{
        cout << "Item isnt in inventory. Enter inventory to view your inventory" << endl;
    }

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
