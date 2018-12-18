/**
* @file Options.h
* @brief this header file will contain all required
* definitions and basic Options functions for Options class
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "Inventory.h"
using namespace std;

/**
* An enumerated type acting as a parameter object
* these are the different types of choices that a player
* can make during gameplay.
*/
enum choiceType{ takeItem, takeAction, movement, nothing};

class Options {
    public:
        /**
        * Constructor for an empty options object menu
        */
        Options();
        /**
        * Resets the options object by making the number of options 0
        * and making all options do nothing. New options can now be
        * loaded.
        */
        void reset(string current);
        /**
        * Adds an option to the Options object menu
        *
        * @param choiceType an enumerated type that describes the type of option
        * @param nextArea the filename of the next area to be loaded as a string
        */
        void addChoice(enum choiceType, string nextArea);
        /**
        * Requests for user input to set the command to do some option.
        */
        void askCommand();
        /**
        * Sets the command
        *
        * @param c The command to be set
        */
        void setCommand(char c);
        /**
        * Gets the current command
        *
        * @return Returns the Options object "command"
        */
        char getCommand();
        /**
        * Looks through the options object and performs the corrent action
        * based on the current command
        *
        * @param inventory The player's current ingame inventory
        * @param current The current area the player is in eg. area1.txt
        * @param currentArea The area that the player will next visit
        */
        void handleChoice(Inventory &inventory, string &current, ifstream &CurrentArea);

        /**
        * The number of choices currently in the Options object
        * that the player may select
        */
        int numOfChoices;
        /**
        * An array that stores the choice types for all the possible
        * options the player may select from
        */
        choiceType choice[10];
        /**
        * An array that stores the next area or action that will be loaded
        * based on the player's choice
        */
        string nextArea[10];
        /**
        * The most current command that was made. This selects the option
        * that will be performed.
        */
        char command;
};

#endif // OPTIONS_H_INCLUDED
