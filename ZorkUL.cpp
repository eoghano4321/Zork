#include <iostream>

#include "ZorkUL.h"

struct St2 {
    unsigned int theDate : 5;
};


ZorkUL::ZorkUL(){
    St2 myObj;
    myObj.theDate = 31;
    cout << "Date using bit structer " << myObj.theDate << " Size " << sizeof(myObj) << endl;
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
/// Virtual Functions
/// Operator Overloading
/// Bit Structures - Shoehorn
/// Initialiser List
/// References
/// Pointers
/// Inheritance
/// Destructors
/// Memory Management
/// Header files with inclusion guards
/// Friendship
/// Private & Public variables
