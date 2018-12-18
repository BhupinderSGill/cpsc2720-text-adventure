/**
* @file Options.h
* @brief Header file for game Options class
* responsible for handling options and choices the player may make
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/Options.h"

Options::Options()
{
    this->reset("");
}
void Options::reset(string current)
{
    this->command='n';
    this->numOfChoices=0;
    for(int j=0;j<10;j++)
    {
        choice[j]=nothing; // default choice: nothing - does nothing
        nextArea[j]=current;
    }
}
void Options::addChoice(choiceType type, string moveArea)
{
    numOfChoices++;
    nextArea[numOfChoices]=moveArea;
    choice[numOfChoices]=type;
}
void Options::askCommand()
{
    string input;
    char com;

    getline(cin,input);
    com=input[0];

    this->command=com;

    if (input.size() != 1 || com == '~')
        this->command = '-';
}

void Options::setCommand(char c) { command=c;}
char Options::getCommand() { return this->command;}

void Options::handleChoice(Inventory &inventory, string &current, ifstream &CurrentArea)
{
    int com=command;
    com=com-48; // makes com the integer equivalent of the ascii char '1' = 49 integer
    if((com>0)&&(com<10))
       {
            if(this->choice[com]==takeAction)
            {
            CurrentArea.open(current.c_str());
            inventory.add(this->nextArea[com]);
            }
            // move to nextArea
            if(this->choice[com]==movement)
            {
            CurrentArea.open(this->nextArea[com].c_str());
            current= this->nextArea[com];
            }
       }
    // reload current event
    else if(this->choice[com]==nothing) CurrentArea.open(current.c_str());
}

