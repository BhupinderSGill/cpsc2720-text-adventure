/**
* @file TestParse.cc
* @brief Test Fixture for Parse
* tests the Parse functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestParse.h"
#include "Parse.h"
#include "Inventory.h"
#include "Other.h"
using namespace std;
//Exceptions?

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestParse);

void TestParse::testParseAddItems()
{
    Inventory invent; // create empty inventory
    string start="#addItem#item1#";
    string modified="";
    parseAddItems(invent,start);

    /*
    cout << "Modified: " << modified << endl;
    cout << "Modified Length: " << modified.length() << endl;
    cout << "Start: " << start << endl;
    cout << "Start Length: " << start.length() << endl;
    */

    CPPUNIT_ASSERT(invent.check("item1"));
    CPPUNIT_ASSERT(start==modified);
}
void TestParse::testParseIfHaveItem()
{
    Inventory invent; // create empty inventory
    invent.add("Mango"); // adds a mango to the inventory
    string start="#ifHaveItem#Mango#Hello#";
    string modified="Hello";

    parseIfHaveItem(invent,start);
    CPPUNIT_ASSERT(invent.check("Mango"));
    CPPUNIT_ASSERT(start==modified);
}
void TestParse::testParseMovement()
{
    Inventory invent; // create empty inventory
    invent.add("Mango"); // adds a mango to the inventory
    string start="#movement#Area#Print this#";
    string modified="[1] Print this";
    // initialize options
    optionsStruct options;
    options.numOfChoices=0;
    for(int i=0;i<10;i++)
    {
        options.nextArea[i]="";
        options.choice[i]=nothing;
    }

    parseMovement(invent,options,start);
    CPPUNIT_ASSERT(options.numOfChoices==1);
    CPPUNIT_ASSERT(options.nextArea[1]=="Area.txt");
    CPPUNIT_ASSERT(options.choice[1]==movement);
    CPPUNIT_ASSERT(start==modified);
}
void TestParse::testParseTakeAction()
{
    Inventory invent; // create empty inventory
    invent.add("Mango"); // adds a mango to the inventory
    string start="#takeAction#Action1#Print this#";
    string modified="[1] Print this";
    // initialize options
    optionsStruct options;
    options.numOfChoices=0;
    for(int i=0;i<10;i++)
    {
        options.nextArea[i]="";
        options.choice[i]=nothing;
    }

    parseTakeAction(invent,options,start);
    CPPUNIT_ASSERT(options.numOfChoices==1);
    CPPUNIT_ASSERT(options.choice[1]==takeAction);
    CPPUNIT_ASSERT(start==modified);
}

void TestParse::testParseConditionalMove()
{
    Inventory invent; // create empty inventory
    invent.add("Mango"); // adds a mango to the inventory
    string start="#takeAction#Action1#Print this#";
    string modified="[1] Print this";
    // initialize options
    optionsStruct options;
    options.numOfChoices=0;
    for(int i=0;i<10;i++)
    {
        options.nextArea[i]="";
        options.choice[i]=nothing;
    }

    parseTakeAction(invent,options,start);
    CPPUNIT_ASSERT(options.numOfChoices==1);
    CPPUNIT_ASSERT(options.choice[1]==takeAction);
    CPPUNIT_ASSERT(start==modified);
}
