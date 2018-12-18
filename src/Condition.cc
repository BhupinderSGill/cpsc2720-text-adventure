#include "Condition.h"
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

Condition::Condition()
   : condition{}
{
   condition["!"] = false;
   condition[""] = true;
}

bool Condition::pass (string a) {
   if (condition["!"])
      return false;
   if (condition[""])
      return true;
   for (auto i = condtion.begin(); i != condition.end(); ++i) {
      if (i->at(0) == '!') {
	 if (inventory.exists(i->sub_str(1, i->size() - 1))) //BE CERTAIN THE EVENT/ITEM/MENUITEM IS NOT IN THE INVENTORY
	    return false;
      } else {
	 if (!inventory.exists(*i)) //BE CERTAIN THE EVENT/ITEM/MENU ITEM IS IN THE INVENTORY
	    return false;
      }
   }
   return true;
}

void Condition::addCondition(string a) {
   condition[a] = true;
}

void Condition::removeCondition(string a) {
   condition[a] = false;
   if (find(condition.begin(), condition.end(), true) == condition.end())
      condition[""] = true;
}

bool Condition::hasCondition(string a) {
   return condition[a];
}
