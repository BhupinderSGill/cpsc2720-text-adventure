//-----------------------------------------------------------------------------
/**
* @file main.cpp
* @brief Main game file that runs the game
*
* @author Legendary Council
*
* @date 3/11/2017
*/
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "include/Inventory.h"
#include "include/saveLoad.h"
#include "include/newParse.h"
#include "include/Menu.h"
#include "include/Options.h"
using namespace std;

int main()
{
    // VARIABLE DECLARATIONS
    newParse p; // game object that handles string parsing
    Inventory inventory; // player's ingame inventory
    Options options; // options object

    string startingArea = "Day1/HouseEntranceDay1.txt"; // game starting area
    string current;
    current=startingArea;
    ifstream CurrentArea;

    int time=0; // if time=24 player runs out of time and court scene begins
    char command;

    mainMenu(inventory, startingArea, time);

    // BEGIN MAIN GAME LOOP
    while(true)
    {
        // Initialize and reset to default current area's option menu
        options.reset(current);
        //-----------------------------------------------------------
        // New Load Area
        p.loadArea(current);
        //-----------------------------------------------------------
        p.addTime(time);
        //-----------------------------------------------------------
        p.parseAddItems(inventory);
        //-----------------------------------------------------------
        p.parseIfHaveItem(inventory);
        //-----------------------------------------------------------
        p.parseTakeAction(inventory, options);
        //-----------------------------------------------------------
        p.parseConditionalMove(inventory, options);
        //-----------------------------------------------------------
        p.parseMovement(inventory, options);
        //-----------------------------------------------------------
        p.print();
        //-----------------------------------------------------------
        // Player makes a choice
        options.askCommand();
        if (options.getCommand() != 0) {
            if (time == 25) return 0;
            if (time == 24) options.setCommand('~');
        }

        options.handleChoice(inventory,current,CurrentArea);
        system("clear"); // clear the screen, prepare to load next frame

        switch(options.getCommand())
        {
        case '0':
            inGameMenu(inventory, current,time);
            //CurrentArea.open(current.c_str());
            break;

        case '~': // HACK - go straight to endgame - player ran out of time
            if(inventory.checkSuccessfulGame()) current="Day6/EndGameWin.txt";
            else current="Day6/EndGameFail.txt";
            CurrentArea.open(current.c_str());
            time=0;
            break;

        default: CurrentArea.open(current.c_str()); break;
        } // END PLAYER SPECIAL CHOICE SWITCH STRUCTURE
    } // END MAIN GAME LOOP

    return 0; // NEVER RETURNS UNLESS ERROR
}
