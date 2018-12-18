/**
* @file Parse.h
* @brief Header file for game parse functions
* responsible for parsing text and carrying out necessary functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef PARSE_H
#define PARSE_H

#include "Other.h"
#include "Inventory.h"
#include <fstream>

/**
* Will parse the textfile tags and add all items when encountering
* #addItem#itemName#
*
* @param inventory The player's current inventory
* @param s The screen buffer display string that will eventually be displayed
*/
void parseAddItems(Inventory &inventory, string &s);
/**
* Will parse the textfile tags and conditionally display text
* #ifHaveItem#itemName#Print this text#
*
* @param inventory The player's current inventory
* @param s The screen buffer display string that will eventually be displayed
*/
void parseIfHaveItem(Inventory &inventory, string &s);
/**
* Will parse the textfile tags and add movement options to the player's choices
* #Area.txt# is the area that will be the next loaded area
* #Print this text# will be printed out to the screen
* #movement#Area#Print this text#
*
* @param inventory The player's current inventory
* @param options A reference to the options structure (player choices are added here)
* @param s The screen buffer display string that will eventually be displayed
*/
void parseMovement(Inventory &inventory, optionsStruct &options, string &s);
/**
* Will parse the textfile tags and add action options to the player's choice menu
* these actions can only be done once and will never be displayed again for the player
* #ActionName# is the name of the action that will be printed out to the screen
* #Print this text# will be printed out to the screen
* #takeAction#ActionName#Print this text#
*
* @param inventory The player's current inventory
* @param options A reference to the options structure (player choices are added here)
* @param s The screen buffer display string that will eventually be displayed
*/
void parseTakeAction(Inventory &inventory, optionsStruct &options, string &s);
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
* @param s The screen buffer display string that will eventually be displayed
*/
void parseConditionalMove(Inventory &inventory, optionsStruct &options, string &s);

#endif // PARSE_H_INCLUDED
