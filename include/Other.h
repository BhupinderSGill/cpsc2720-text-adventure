/**
* @file Other.h
* @brief Contains miscellaneous functions and structures
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef OTHER_H
#define OTHER_H
#include <map>
#include <string>
#include <iostream>
#include "Options.h"
#include "Inventory.h"
#include "saveLoad.h"

/**
* A structure to store the options that a player will have available to them
* upon entering an area the structure of options chanages
*/
struct optionsStruct
{
   /**
   * the total number of choices detected in an area
   */
   int numOfChoices;
   /**
   * the stored type of choice
   */
   choiceType choice[10];
   /**
   * determines the next area that will be loaded
   */
   string nextArea[10];
};

/**
* A pause function replacement for windows - system("pause")
*/
//void pause1();
/**
* A final function that checks the player's inventory to determine
* if the player won or lost the game
*
* @param inventory The player's inventory
*/
bool checkSuccessfulGame(Inventory &inventory);

/**
* Determines how to handle the players choice based on their input
*
* @param index The option number that the player selected
* @param inventory A reference to the player's current inventory in game
* @param current A reference to the player's current area
* @param CurrentArea A reference to input filestream reference to the last loaded area
* @param options A reference to the options structure that contains all possible choices a player could have made in the area
*/
void handleChoices(const int index, Inventory &inventory, string &current, ifstream &CurrentArea, Options &options);

#endif // OTHER_H
