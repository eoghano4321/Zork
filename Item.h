#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string description;
    string longDescription;
    int weightGrams;
    float value;
    bool weaponCheck;

public:
    Item (string description, int inWeight, float inValue);
    Item (string description);
    ~Item();
    string getShortDescription();
    string getLongDescription();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue();
    void setValue(float value);
    bool operator==(const Item &other) const;
    virtual bool canRemove();



};

#endif /*ITEM_H_*/
