#include <iostream>

#include "ZorkUL.h"

struct St2 {
    unsigned int theDate : 5;
};

template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}


ZorkUL::ZorkUL(){
    St2 myObj;
    myObj.theDate = 31;
    cout << "Date using bit structer " << myObj.theDate << " Size " << sizeof(myObj) << endl;

    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
}

int main(int argc, char *argv[]) {
    ZorkUL temp;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

//////////////////////////////////////////////
///           Constructs Used              ///
//////////////////////////////////////////////
// Virtual Functions
// Operator Overloading
// Initialiser List
// References
// Pointers
// Inheritance
// Destructors
// Memory Management
// Header files with inclusion guards
// Friendship
// Private & Public variables
// Global variables
// Bit Structures - Shoehorn
// Templates - Shoehorn
