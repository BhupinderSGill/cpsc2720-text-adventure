/**
* @file Other.cc
* @brief Implementation file for miscellaneous game functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/Other.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool checkSuccessfulGame(Inventory &inventory)
{
    int winner=0;
    int cutoff;
    if(inventory.check("Petition") == false) return false;
    if(inventory.check("Documents")) cutoff = 2;
    else cutoff = 4;
    if(inventory.check("BhupinderSignature")) winner++;
    if(inventory.check("JuliusSignature")) winner++;
    if(inventory.check("ParanoiaSignature")) winner++;
    if(inventory.check("KolodySignature")) winner++;
    if(inventory.check("CramerSignature")) winner++;
    if(inventory.check("HippySignature")) winner++;
    if(inventory.check("ParanoiaMotherSignature")) winner++;
    if(inventory.check("ConvinceConstructionWorker")) winner++;

    if(winner>=cutoff) return 1;
    else return 0;
}

void handleChoices(const int index, Inventory &inventory, string &current, ifstream &CurrentArea, Options &options)
{
   if(options.choice[index]==takeAction)
   {
      CurrentArea.open(current.c_str());
      inventory.add(options.nextArea[index]);
   }
   /// move to nextArea
   if(options.choice[index]==movement)
   {
      CurrentArea.open(options.nextArea[index].c_str());
      current= options.nextArea[index];
   }
   /// reload current event
   if(options.choice[index]==nothing) CurrentArea.open(current.c_str());
}
