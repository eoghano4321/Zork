#include "Item.h"
#include <cmath>


Item::Item (string inDescription, int inWeightGrams, float inValue) {
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
}

Item::Item(string inDescription) {
    description = inDescription;
}

Item::~Item(){
    cout << "Item deleted" << endl;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
        cout << "weight invalid, must be 0<weight<9999" ;
    else
        weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
        cout << "value invalid, must be 0<value<9999" ;
    else
        value = inValue;
}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    int integerValue = static_cast<int>(value);
    return description + ", weight: " + to_string(weightGrams) + ", value: " + to_string(integerValue) + "\n";
}

int Item::getWeight(){
    return weightGrams;
}

float Item::getValue(){
    return value;
}

bool Item::canRemove(){
    return true;
}

////////////////////////////////////////////////
///             Operator Overloading         ///
////////////////////////////////////////////////

bool Item::operator==(const Item &other) const {
    return description == other.description;
}
