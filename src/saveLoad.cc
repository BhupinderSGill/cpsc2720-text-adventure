/**
* @file saveLoad.cc
* @brief Implementation file for game saving and loading functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/saveLoad.h"
#include <iostream>
#include <fstream>
using namespace std;

SaveLoad::SaveLoad()
{
   saveFilePath = "save.txt";
}

//-----------------------------------------------------------------------------
void SaveLoad::save(Inventory &inventory, string currentArea, int &time)
{
    ofstream out;
    ///string saveFilePath="../save.txt";
    out.open(saveFilePath.c_str());
    out << "save.txt" << endl;
    out << currentArea << endl;
    out << time << endl;
    inventory.save(out);
    out.close();
}
//-----------------------------------------------------------------------------
bool SaveLoad::load(Inventory& inventory, string &current, int& time)
{
    ifstream in;
    ///string saveFilePath
    in.open(saveFilePath.c_str());
    string temp="";

    ///check for non empty file
    if (!getline(in, temp))
        return false;
    if (temp == saveFilePath)
    {
        ///get current are to load at start
        getline(in,temp);
        current = temp;
        in >> time; /// warning this might bug things cin.ignore() cin.clear() problems
        in.ignore();
        ///load the inventory
        inventory.load(in);
        return true;
    }
    else
        return false;
}
