#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"
//#include "mainwindow.h"

class Parser {
private:

public:
    CommandWords *commands;
    string inputStr;
    string outputStr;
    Parser();
    Command* getCommand();
    void showCommands();
};

#endif /*PARSER_H_*/
