#include "Key.h"

Key::Key(string description):Item{description}
{
    cout << "key" << endl;
}

bool Key::canRemove() {
    return false;
}
