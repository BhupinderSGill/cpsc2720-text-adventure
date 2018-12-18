/**
* @file Menu.cc
* @brief Implementation file for InGameMenu and MainMenu
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/Menu.h"
#include "../include/Other.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char ask() {
    string in;
    char command;
    getline(cin,in);
    command=in[0];
    if (in.size() != 1 || command == '~')
        command = '-';
    return command;
}

void pause1() {
   string q = "";
   cout << "Press enter to continue";
   getline(cin, q);
   return;
}

/// this function will display the main menu at the start of the game
void mainMenu(Inventory &inventory, string &startingArea, int &time)
{
   char command;
   bool tryAgain=1;
   SaveLoad a;
   cout << endl;
   cout << "--------------------------------------------------------" << endl;
   cout << "  ___   _   _  _ _____   ____   _____ _    _    ___ 	 " << endl;
   cout << " |   \\ /_\\ | \\| |   \\ \\ / /\\ \\ / /_ _| |  | |  | __|	 " << endl;
   cout << " | |) / _ \\| .` | |) \\ \\ /  \\ V / | || |__| |__| _| 	 " << endl;
   cout << " |___/_/ \\_\\_|\\_|___/ |_|    \\_/ |___|____|____|___|	 " << endl;
   cout << "                                                        " << endl;
   cout << "--------------------------------------------------------" << endl;
   cout << " The Main Menu " << endl;
   cout << "--------------------------------------------------------" << endl;
   cout << "Choices" << endl << endl;
   cout << "[0] New Game" << endl;
   cout << "[1] Load Game" << endl;
   cout << "[2] Quit" << endl << endl;
   cout << "--------------------------------------------------------" << endl;

   /// force player to enter '0' or '1' or '2'
   /// if they do not enter the necessary input ask again
   while(!(command=='0'||command=='1'||command=='2'))
   {
      command = ask();
   }
   system("clear");

   while(tryAgain)
   {
      system("clear");
      switch(command)
      {
	 /// case 0 shall be the main menu
	 case '0':
	    inventory.clear();
	    tryAgain=false;
	    break;
	    /// later case 1 will enter the Load Game Menu
	 case '1':
	    inventory.clear();
	    startingArea= "Day1/HouseEntranceDay1.txt"; /// the filename of the very first area
	    if(a.load(inventory,startingArea,time))
	       tryAgain=false;
	    else
	       cout << "Cannot Load File" << endl;
	    break;
	    /// Quit the game
	 case '2':
	    exit(0);
	    break;
	    /// default handles ... not sure if default case would ever happen
	 default:
	    break;
      }
   }
}

// eg. string currentLocation="Area1.txt"
void inGameMenu(Inventory &inventory, const string& currentLocation, int &time)
{
    SaveLoad a;
   char command;
   //enum timeOfDay{Morning,Afternoon,Evening,Night};
   //timeOfDay tod=0;

   cout << "--------------------------------------------------------" << endl;
   cout << " In Game Menu " << endl;
   cout << "--------------------------------------------------------" << endl;
   cout << "Choices" << endl << endl;
   cout << "[0] Save Game" << endl;
   cout << "[1] Resume Game" << endl;
   cout << "[2] Check Journal" << endl;
   cout << "[3] Help" << endl;
   cout << "[4] Quit Game" << endl << endl;
   cout << "--------------------------------------------------------" << endl;

   /// force player to enter '0' or '1' or '2'
   /// if they do not enter the necessary input ask again
   while(!(command=='0'||command=='1'||command=='2'||command=='3'||command=='4'))
   {
      command=ask();
   }
   system("clear");

   switch(command)
   {
      /// case 0 shall be save to save/save1.txt
      case '0':
	 a.save(inventory, currentLocation, time);
	 break;
	 /// resume game so just break from the function
      case '1':
	 break;
	 /// check the inventory
      case '2':
	 system("clear");
	 cout << "Current Journal" << endl;
	 inventory.print();
	 pause1();
	 system("clear");
	 break;
	 /// check the time
      case '3':
	 /*system("clear");
	 cout << "Current Time: ";
	 cout << "Day: " << time/4 << " ";
	 if((time%4)==0) cout << "Morning" << endl;
	 if((time%4)==1) cout << "Afternoon" << endl;
	 if((time%4)==2) cout << "Evening" << endl;
	 if((time%4)==3) cout << "Night" << endl;*/
	 cout << "Help:\n"
	      << "The game is quite simple, just follow the on-screen prompts of your choice.\n"
	      << "It's essentially a choose-your-own-adventure type game.\n"
	      << "The Journal will keep track of any action you take, and depending on what action you have taken, different things could happen.\n"
	      << "Have fun!\n";
	 pause1();
	 system("clear");
	 break;
	 /// Quit the game
      case '4':
	 exit(0);
	 break;
	 /// default handles ... not sure if default case would ever happen
      default:
	 break;
   }
}
