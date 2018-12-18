/**
* @file Inventory.h
* @brief this header file will contain all required
* definitions and basic Inventory functions for Inventory class
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef INVENTORY_H
#define INVENTORY_H
#include <map>
#include <string>
#include <iostream>
using namespace std;

/**
* The Inventory class that deals with storing and checking
* items/events/actions the player encounters during gameplay
*/
class Inventory
{
    public:
        /**
        * Constructor for an empty inventory object
        */
        Inventory();
        //checks to see if the file is an event

        /*
        bool isEvent(string filename);
        //check to see if the file is an item

        bool isItem(string filename);

        bool isMenu(string filename);
        */

        /**
        * Checks if the item/identifier is currently in the player's possession
        * @param identifier The name of the item/action/event to check for player's possession
        * @return returns 'True' if identifier is in players possession or 'False' if not
        */
        bool check(string identifier);
        /**
        * Removes the named item from the inventory by setting the boolean
        * which represents the player's current possession of the item to 'false'
        * @param identifier The name of the item to be removed from the player's possession
        */
        void add(string identifier);
        /**
        * Removes the named item from the inventory by setting the boolean
        * which represents the player's current possession of the item to 'false'
        * @param identifier The name of the item to be removed from the player's possession
        */
        void forget(string identifier);
        /**
        * Prints the players inventory
        */
        void print();
        /**
        * Saves the game information (inventory, current area, time) to a text file
        * @param ostream The output file stream to insert data to be saved
        */
        void save(ostream&);
        /**
        * Loads the game information (inventory, current area, time) from a text file
        * @param istream The input file stream to extract data to be loaded
        */
        void load(istream&);
        /**
        * Clears the sto member variable (clears the player's inventory)
        */
        void clear();
        /**
        * Checks to see if the player has indeed done enough to win the game or lose
        *
        * @return Returns a bool true for winning game false for loser
        */
        bool checkSuccessfulGame();

    private:
        /**
        * A map that stores the names of items in the inventory
        * and a bool to determine whether the player 'has' or
        * does 'not have' the item
        */
        map<string, bool> sto;
};

#endif // INVENTORY_H
