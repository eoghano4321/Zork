TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Inventory.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        item.cpp \
        main.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Inventory.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h
