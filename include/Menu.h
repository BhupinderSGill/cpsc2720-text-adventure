/**
* @file Menu.h
* @brief Header file for the game's menu functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Inventory.h"
#include <iostream>

/**
* The main menu of the Dandyville Game that runs at the beginning of the game
*
* @param inventory A reference to the player's ingame inventory
* @param startingArea A reference to the starting area (important for loading)
* @param time A reference to the players "InGame Playtime"
*/
void mainMenu(Inventory &inventory, string &startingArea, int &time);
/**
* The main menu of the Dandyville Game that runs at the beginning of the game
*
* @param inventory A reference to the player's ingame inventory
* @param currentLocation A reference to the player's current location in game (important for saving)
* @param time A reference to the players "InGame Playtime"
*/
void inGameMenu(Inventory &inventory, const string& currentLocation, int &time);

char ask();

void pause1();

#endif // MENU_H_INCLUDED
