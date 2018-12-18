/**
* @file TestOptions.cc
* @brief Test Fixture for Options
* tests the Options class functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestOptions.h"
#include "Inventory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestOptions);

void TestOptions::testOptions()
{
    Options o;
    // test the empty object
    CPPUNIT_ASSERT(o.numOfChoices==0);

    // test the choiceType and nextArea
    for(int i=0;i<10;i++)
    {
        CPPUNIT_ASSERT(o.nextArea[i]=="");
        CPPUNIT_ASSERT(o.choice[i]==nothing);
    }
    // test command
    CPPUNIT_ASSERT(o.command=='n');
}
void TestOptions::testReset()
{
    Options o;

    // reset it here
    o.reset("next.txt");

    // test the empty object
    CPPUNIT_ASSERT(o.numOfChoices==0);

    // test the choiceType and nextArea
    for(int i=0;i<10;i++)
    {
        CPPUNIT_ASSERT(o.nextArea[i]=="next.txt");
        CPPUNIT_ASSERT(o.choice[i]==nothing);
    }
    // test command
    CPPUNIT_ASSERT(o.command=='n');
}
void TestOptions::testAddChoice()
{
    Options o;
    o.reset("next.txt");

    o.addChoice(movement,"next1");
    o.addChoice(takeItem,"next2");
    o.addChoice(takeAction,"next3");
    o.addChoice(nothing,"next4");

    // test command
    CPPUNIT_ASSERT(o.command=='n');

     // test the numberOfChoices has increased
    CPPUNIT_ASSERT(o.numOfChoices==4);

    CPPUNIT_ASSERT(o.choice[1]==movement);
    CPPUNIT_ASSERT(o.choice[2]==takeItem);
    CPPUNIT_ASSERT(o.choice[3]==takeAction);
    CPPUNIT_ASSERT(o.choice[4]==nothing);

    CPPUNIT_ASSERT(o.nextArea[1]=="next1");
    CPPUNIT_ASSERT(o.nextArea[2]=="next2");
    CPPUNIT_ASSERT(o.nextArea[3]=="next3");
    CPPUNIT_ASSERT(o.nextArea[4]=="next4");
}
void TestOptions::testAskCommand()
{
}
void TestOptions::testSetCommand()
{
    Options o;
    o.reset("next.txt");
    o.setCommand('r');

    CPPUNIT_ASSERT(o.getCommand()!='n');
    CPPUNIT_ASSERT(o.getCommand()=='r');
}
void TestOptions::testGetCommand()
{
    Options o;
    o.reset("next.txt");
    o.setCommand('r');

    CPPUNIT_ASSERT(o.getCommand()!='n');
    CPPUNIT_ASSERT(o.getCommand()=='r');
}
void TestOptions::testHandleChoice()
{
    Inventory inventory;
    string current;
    ifstream CurrentArea;
}
