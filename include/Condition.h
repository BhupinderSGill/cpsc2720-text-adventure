#ifndef CONDITION_H
#define CONDITION_H

#include <map>
#include <string>
#include <stack>
using namespace std;

class Condition {
private:
   map<string, bool> condition;
public:
    ///Conditions start off as unconditional
    Condition();
    ///Adds the condition. If the condition already exists, does not change anything.
    void addCondition(string);
    ///Removes the condition. If the condition already exists, does not change anything.
    void removeCondition(string);
    ///Checks if a condition exists within this condition.
    bool hasCondition(string);
    ///Checks the conditions stores against the inventory, and returns whether this condition passes TIE BREAKER: FAIL OVERRIDES PASS
    bool pass(string);
};

#endif // CONDITION_H
