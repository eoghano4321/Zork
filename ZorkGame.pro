TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += C:/Qt/6.5.0/mingw_64/include/QtWidgets

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Inventory.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        item.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Inventory.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h \
    mainwindow.h

DISTFILES += \
    README.md \
    ZorkGame.pro.user \
    ZorkGame.pro.user.a47f6c0 \
    screen.ui.qml

FORMS += \
    mainwindow.ui \
    mainwindow.ui.autosave

