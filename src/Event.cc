#include "Event.h"
#incdlue "Text.h"
#include "Condition.h"
#include <string>
#include <vector>
#include <cassert>
using namespace Event;
using namespace std;

Event() : file{"0-0-0"}, activity{}
{
   
}

/*
  Syntax:
  At the begining of the file, text is unconditional.
  unconditional text <condition> text to dump <condition> more text
  <> unconditional text <!> unconditional menu <>! unconditional menu just because
  <!>! unconditional menu with a ! in the question <!cat> a menu which needs a cat in the inventory
  <> ! not a menu, just text including a space followed by a !
  <>\! not a menu, just text with a ! at the beginning
  <>\\ text with a \ at the beginning
  <>> text with a > at the beginning
  <!0-1-2> a menu which needs the event 0-1-2 to have run to run
  <c-t> This is illegal because the condition has a dash in it, and it is not an event.

  Notes:
  Special characters depend on context.
  Special characters: < > \ !
  Travelling characters: ! (Gets interpreted both now and elsewhere)
  Special characters inside tags: ! >
  Special characters outside tags: \ < !

  Less Certain
  *****************
  The syntax within menus themselves gets interpreted inside of the Text objects' run function.
  The presence of a ! at the beginnning tells the Text::run function that it is a menu, and it better
  be formatted as a menu.
  Menu format:
  !question text#
  #0# Display #0-1-2#
  #useroption# narrativechoice #hiddenfile/eventname#

  The newline isn't necessary.
  Reserved characters within menus:
  Has a special meaning, in code at the beginning but not always in story: !
  Used to parse the menu: #
  \ is still the escape character

  Note: handling \< is already implemented :D
 */

void open() {
   ifstream in;
   in.open(file);
   bool menu = false;
   bool command false;
   char c;
   string blind = "";
   Condition condition{}; //there are no breakout characters within tags
   while (c = in.get() && !in.eof()) {
      switch (c) {
	 case '<': //We are inside of a tag
	    string tag;
	    getline(in, tag, '>'); //Could be replaced with getTag to handle \ in tags
	    if (tag.empty() || tag[0] != '/')
	       condition.addCondition(tag);
	    else
	       condition.removeCondition(tag.sub_str(1, tag.size() - 1));
	    break;
	 case '\\': //bug: cannot handle a backslash at the end of the file.
	    c = in.get();
	    blind += '\\';
	 default:
	    blind += c;
      }
   }
   in.close();
}

/* Could potentially be used to handle a desire to have > characters being in the inventory.
string getTag(istream& in) {
   string temp;
   //if (in.eof())
   //   throw error("The storyfile ended inside of a tag.");
   getline(in, temp, '>');
   if (!temp.empty() && temp[temp.size()-1] == '\\') {
      temp[temp.size()-1] = '>';
      return temp + getTag(in);
   }   
   else
      return temp;
}
*/

string run() {
   string a;
   for (int i = 0; i < activity.size(); ++i) {
      a = activity[i].run();
      //interpret a
   }
}
