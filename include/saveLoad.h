/**
* @file saveLoad.h
* @brief this header file will contain all required
* definitions and basic SaveLoad functions.
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef SAVELOAD_H
#define SAVELOAD_H
#include "Inventory.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
* The SaveLoad class that deals with saving and loading a player's
* inventory (items/events/actions), current location, and game time
*/
class SaveLoad
{

public:
    /**
    * The file path for the current area to be loaded
    * if this filepath is changed then it becomes the
    * the filepath of the next area/textfile to be loaded
    */
   string saveFilePath; //"save.txt";
   SaveLoad();
    /**
    * Saves the inventory, currentArea (text file), and time
    * @param inventory A reference to the inventory.
    * @param currentArea A string for the next area/textfile to be loaded
    * @param time The time elapsed in the game
    */
    void save(Inventory &inventory, string currentArea, int &time);
    /**
    * Loads the inventory, saved area the player was in (text file), and time
    * @param inventory A reference to the inventory.
    * @param currentArea A string for the next area/textfile to be loaded
    * @param time The time elapsed in the game
    */
    bool load(Inventory &inventory, string &current, int& time);

};
#endif //SAVELOAD_H
