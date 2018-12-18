/**
* @file newParse.cc
* @brief Implementation file for parse class functions
* These functions modify the output string which acts like a
* frame buffer for our text based adventure game
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/newParse.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

newParse::newParse()
{
    textDisplay="";
}

newParse::newParse(string textDis)
{
    textDisplay=textDis;
}


void newParse::loadArea(string filename)
{
    string tempString="";
    textDisplay=""; // reset story string short for screen
    ifstream loadingArea;
    loadingArea.open(filename.c_str());

    // loads textfile into the string "textDisplay" to be manipulated later
    while(!loadingArea.eof())
    {
        getline(loadingArea,tempString);
        textDisplay=textDisplay+tempString+"\n";
    }

    loadingArea.close();
    loadingArea.clear();
}

void newParse::addTime(int &time)
{
    string temp; /// temporary string for use
   int i1=0,i2=0; /// indexes
   bool finish=0;

   while(!finish)
   {
      /// find the index of (#)addTime#
      i1=textDisplay.find("#addTime#",i1);
      if(i1==-1) {finish = true;} /// no more checks to find - stop searching
      else
      {
	 /// find the index of (#)addTime#
	 i2=textDisplay.find("#",i1+1);

	 /// add time
	 time++;

	 /// remove (#addTime) from the display
	 /// Players don't need to see the tag
	 textDisplay.erase(i1,i2-i1+1);
      }
   }
}

void newParse::parseAddItems(Inventory &inventory)
{
   string temp; /// temporary string for use
   // entire textfile as a string variable
   int i1=0, i2=0, i3=0; /// indexes

   /// finished searching the textfile for items?
   /// 0 - initially searching for items
   /// 1 - all items were found -> set to "true" finished searching
   bool finish=0;

   /// while loop to store text file in 's' string variable
   /*ifstream in; // the file being read for items
   in.open(filename.c_str());
   while(!in.eof())
   {
      getline(in,temp);
      s=s+temp+"\n";
   }
   in.close();
   in.clear();
   */

   // find multiple items and add them to the "inventory" vector
   while(!finish)
   {
      i1=textDisplay.find("#addItem#",i1); /// find the index of (#)addItem#itemName#
      if(i1==-1) {finish = true;} /// no more items to find - stop searching
      else
      {
	 /// find the index of #addItem#itemName(#)
	 i2=textDisplay.find("#",i1+1);
	 i3=textDisplay.find("#",i1+9);
	 /// get substring #addItem#(itemName)#
	 temp=textDisplay.substr(i1+9,i3-(i1+9));

	 /// check if the item is already in the inventory
	 /// if the item isn't already in inventory then add it
	 inventory.add(temp);

	 /// since you just found and added an item at index 'i1'
	 /// continue searching the textfile for more items after index 'i2'
	 textDisplay.erase(i1,i3-i1+1);
	 i1=i3;
      }
   }
}

void newParse::parseIfHaveItem(Inventory &inventory)
{
   string temp; /// temporary string for use
   int i1=0,i2=0,i3=0; /// indexes

   /// finished searching the textfile for items?
   /// 0 - initially searching for items
   /// 1 - all items were found -> set to "true" finished searching
   bool finish=0;

   /// finds all the #ifHaveItem#itemName#Print this# conditionals
   /// and modifies the display string 's' for the game screen
   while(!finish)
   {
      /// find the index of (#)ifHaveItem#itemName#Print this#
      i1=textDisplay.find("#ifHaveItem#",i1);
      if(i1==-1) {finish = true;} /// no more checks to find - stop searching
      else
      {
	 /// find the index of #ifHaveItem#itemName(#)Print this#
	 i2=textDisplay.find("#",i1+12);
	 /// get substring #ifHaveItem#(itemName)#Print this#
	 temp=textDisplay.substr(i1+12,i2-(i1+12));

	 /// find the index of #ifHaveItem#itemName#Print this(#)
	 i3=textDisplay.find("#",i2+1);

	 /// check if the item is already in the inventory
	 /// if the item is in inventory #Print this#
	 /// and remove #ifHaveItem#itemName#
	 //
	 /// else remove everything #ifHaveItem#itemName#Print this#
	 if(inventory.check(temp))
	 {
	    textDisplay.erase(i3,1); /// erases #ifHaveItem#itemName#Print this(#)
	    textDisplay.erase(i1,i2-i1+1); /// erases (#ifHaveItem#itemName#)Print this
	 }
	 else
	 {
	    /// completely remove #ifHaveItem#itemName#Print this#
	    textDisplay.erase(i1,i3-i1+1);
	 }
      }
   }
}

void newParse::parseMovement(Inventory &inventory, Options &options)
{

   string temp; /// temporary string for use
   string insertNumber="";
   int i1=0,i2=0,i3=0; /// indexes

   /// finished searching the textfile for items?
   /// 0 - initially searching for items
   /// 1 - all items were found -> set to "true" finished searching
   bool finish=0;

   while(!finish)
   {
      /// find the index of (#)movement#Area#Print this#
      i1=textDisplay.find("#movement#",i1);
      if(i1==-1) {finish = true;} /// no more checks to find - stop searching
      else
      {
	 /// find the index of #movement#Area(#)Print this#
	 i2=textDisplay.find("#",i1+10);
	 /// get substring #movement#(Area)#Print this#
	 temp=textDisplay.substr(i1+10,i2-(i1+10));
	 temp=temp+".txt";
	 options.addChoice(movement,temp);

	 /// find the index of #movement#Area#Print this(#)
	 i3=textDisplay.find("#",i2+1);

	 /// erase (#movement#Area#)Print this(#)
	 textDisplay.erase(i3,1); // erases #movement#Area#Print this(#)
	 textDisplay.erase(i1,i2-i1+1); // erases (#movement#Area#)Print this#

	 ///using a string stream to convert an integer to string
	 stringstream ss;

	 ss << options.numOfChoices;
	 insertNumber= ss.str();
	 insertNumber="["+insertNumber+"] ";
	 textDisplay.insert(i1,insertNumber);
      }
   }
}

/// #takeAction#actionName#Print this#
/// this also goes into the inventory
/// its a bit strange that actions like 'jumping' can go into the inventory
void newParse::parseTakeAction(Inventory &inventory, Options &options)
{
   string temp; // temporary string for use
   string insertNumber="";
   int i1=0,i2=0,i3=0; // indexes

   bool finish=0;

   /// finds all the #takeAction#actionName#Print this# conditionals
   while(!finish)
   {
      /// find the index of (#)takeAction#actionName#Print this#
      i1=textDisplay.find("#takeAction#",i1);
      if(i1==-1) {finish = true;} /// no more checks to find - stop searching
      else
      {
	 /// find the index of #takeAction#actionName(#)Print this#
	 i2=textDisplay.find("#",i1+12);
	 /// get substring #takeAction#(actionName)#Print this#
	 temp=textDisplay.substr(i1+12,i2-(i1+12));

	 /// find the index of #takeAction#actionName#Print this(#)
	 i3=textDisplay.find("#",i2+1);

	 /// check if the item is already in the inventory
	 /// if the item is in inventory #Print this#
	 /// and remove #takeAction#actionName#
	 //
	 /// else remove everything #takeAction#actionName#Print this#
	 if(inventory.check(temp))
	 {
	    /// completely remove #takeAction#actionName#Print this#
	    textDisplay.erase(i1,i3-i1+1);
	 }
	 else
	 {
	    /// find the index of #takeAction#actionName(#)Print this#
	    i2=textDisplay.find("#",i1+12);
	    options.addChoice(takeAction,temp);

	    /// find the index of #takeAction#actionName#Print this(#)
	    i3=textDisplay.find("#",i2+1);

	    /// erase (#movement#Area#)Print this(#)
	    textDisplay.erase(i3,1); /// erases #takeAction#actionName#Print this(#)
	    textDisplay.erase(i1,i2-i1+1); /// erases (#takeAction#actionName#)Print this#


	    stringstream ss;
	    ss << options.numOfChoices;
	    insertNumber= ss.str();
	    insertNumber="["+insertNumber+"] ";
	    textDisplay.insert(i1,insertNumber);
	 }
      }
   }
}

/// if have "ItemName" in inventory this is a movement option
/// else there will be no movement option
/// #movementIfItem#ItemName#Area#Print this text#
void newParse::parseConditionalMove(Inventory &inventory, Options &options)
{
   string area,itemName; /// temporary string for use
   string insertNumber="";
   int i1=0,i2=0,i3=0,i4=0,i5=0; /// indexes

   /// finished searching the textfile for items?
   /// 0 - initially searching for items
   /// 1 - all items were found -> set to "true" finished searching
   bool finish=0;

   while(!finish)
   {
      /// find index of (#)movementIfItem#ItemName#Area#Print this text#
      i1=textDisplay.find("#movementIfItem#",i1);
      /// find index of #movementIfItem(#)ItemName#Area#Print this text#
      i2=textDisplay.find("#",i1+1);
      /// find index of #movementIfItem#ItemName(#)Area#Print this text#
      i3=textDisplay.find("#",i2+1);
      /// find index of #movementIfItem#ItemName#Area(#)Print this text#
      i4=textDisplay.find("#",i3+1);
      /// find index of #movementIfItem#ItemName#Area#Print this text(#)
      i5=textDisplay.find("#",i4+1);

      if(i1==-1) {finish = true;} /// no more checks to find - stop searching
      else
      {
          ///get itemName substring
          string test1=textDisplay.substr(i1,20);
          string test2=textDisplay.substr(i2,20);
          string test3=textDisplay.substr(i3,20);
          string test4=textDisplay.substr(i4,20);
          string test5=textDisplay.substr(i5,20);
          itemName=textDisplay.substr(i2+1,i3-i2-1);
          ///get area name substring
          area=textDisplay.substr(i3+1,i4-i3-1);
          /*
          cout << "PROBE: TEST1: " << test1 << endl;
          cout << "PROBE: TEST2: " << test2 << endl;
          cout << "PROBE: TEST3: " << test3 << endl;
          cout << "PROBE: TEST4: " << test4 << endl;
          cout << "PROBE: TEST5: " << test5 << endl;
          cout << "PROBE: i1: " <<i1 << endl;
          cout << "PROBE: i2: " <<i2 << endl;
          cout << "PROBE: i3: " <<i3 << endl;
          cout << "PROBE: i4: " <<i4 << endl;
          cout << "PROBE: i5: " <<i5 << endl;
          cout << "PROBE: ITEMNAME:" << itemName << endl;
          cout << "PROBE: ITEMNAME LENGTH: " << itemName.length() << endl;
          cout << "PROBE: AREA: " << area << endl;
          */

          if(inventory.check(itemName))
          {
              textDisplay.erase(i5,1); /// delete last #
              textDisplay.erase(i1,i4-i1+1);
              /// make it an option
              area=area+".txt";
              options.addChoice(movement,area);
              stringstream ss;
              ss << options.numOfChoices;
              insertNumber= ss.str();
              insertNumber="["+insertNumber+"] ";
              textDisplay.insert(i1,insertNumber);
          }
          else
          {
              /// delete the option and text completely
              textDisplay.erase(i1,i5-i1+1);
          }
      }
   }
}

void newParse::print()
{
    cout << textDisplay << endl << endl;
}

string newParse::getTextDisplay()
{
    return textDisplay;
}
