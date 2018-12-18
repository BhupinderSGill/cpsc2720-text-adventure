/**
* @file newParse.h
* @brief Header file for game parse class
* responsible for parsing text and carrying out necessary functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef NEWPARSE_H
#define NEWPARSE_H

#include "Options.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>

class newParse
{
    public:
        /**
        * Constructor for an empty newParse object
        */
        newParse();
        /**
        * Constructor for a newParse object
        * @param textDis is the parse object's string which will later be manipulated
        */
        newParse(string textDis);
        /**
        * To load the next area into the parse object
        * @param filename reads in the data from the file to later be manipulated
        */
        void loadArea(string filename);
        /**
        * Parses the area to see how much time needs to be added
        * @param time an integer that goes up by 1 when #addTime# tags are found
        */
        void addTime(int &time);
        /**
        * Will parse the textfile tags and add all items when encountering
        * #addItem#itemName#
        *
        * @param inventory The player's current inventory
        */
        void parseAddItems(Inventory &inventory);
        /**
        * Will parse the textfile tags and conditionally display text
        * #ifHaveItem#itemName#Print this text#
        *
        * @param inventory The player's current inventory
        */
        void parseIfHaveItem(Inventory &inventory);
        /**
        * Will parse the textfile tags and add movement options to the player's choices
        * #Area.txt# is the area that will be the next loaded area
        * #Print this text# will be printed out to the screen
        * #movement#Area#Print this text#
        *
        * @param inventory The player's current inventory
        * @param options A reference to the options object (player choices are added here)
        */
        void parseMovement(Inventory &inventory, Options &options);
        /**
        * Will parse the textfile tags and add action options to the player's choice menu
        * these actions can only be done once and will never be displayed again for the player
        * #ActionName# is the name of the action that will be printed out to the screen
        * #Print this text# will be printed out to the screen
        * #takeAction#ActionName#Print this text#
        *
        * @param inventory The player's current inventory
        * @param options A reference to the options (player choices are added here)
        */
        void parseTakeAction(Inventory &inventory, Options &options);
        /**
        * Will parse the textfile tags and add conditional movement options to the player's
        * choice menu. This option will only be available if the player has a certain item
        * in their inventory
        * #ItemName# is the name of the item to check for in the inventory
        * #Area.txt# is the area that will be the next loaded area
        * #Print this text# will be printed out to the screen
        * #movementIfItem#ItemName#Area#Print this text#
        *
        * @param inventory The player's current inventory
        * @param options A reference to the options structure (player choices are added here)
        */
        void parseConditionalMove(Inventory &inventory, Options &options);
        /**
        * Prints out the textDisplay to screen
        */
        void print();
        /**
        * @return returns the textDisplay string
        */
        string getTextDisplay();

    private:
        /**
        * A string that is manipulated and has information extracted from.
        * Later the string will be displayed to screen like a frame buffer.
        */
        string textDisplay;
};

#endif // NEWPARSE_H_INCLUDED
