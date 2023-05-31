#ifndef KEY_H
#define KEY_H

#include "Item.h"

class Key : public Item
{
public:
    Key(string description);
    bool canRemove() override;
};

#endif // KEY_H
