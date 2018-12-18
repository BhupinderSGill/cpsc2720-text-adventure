/**
* @file TestNewParse.cc
* @brief Test Fixture for newParse
* tests the newParse class functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestNewParse.h"
#include "newParse.h"
#include "Options.h"
#include "Inventory.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Exceptions?

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestNewParse);

void TestNewParse::testNewParse()
{
    newParse p;
    CPPUNIT_ASSERT(p.getTextDisplay()=="");
}
void TestNewParse::testNewParseInput()
{
    newParse p("this is text");
    CPPUNIT_ASSERT(p.getTextDisplay()=="this is text");
}
void TestNewParse::testLoadArea()
{
}
void TestNewParse::testAddTime()
{
    newParse p("#addTime#");
    int time=0;

    p.addTime(time);
    CPPUNIT_ASSERT(p.getTextDisplay()=="");
    CPPUNIT_ASSERT(time==1);
}
void TestNewParse::testParseAddItems()
{
    Inventory i;
    newParse p("#addItem#itemName#");

    p.parseAddItems(i);
    CPPUNIT_ASSERT(p.getTextDisplay()=="");
    CPPUNIT_ASSERT(i.check("itemName"));
}
void TestNewParse::testParseIfHaveItem()
{
    Inventory i;
    newParse p("#addItem#itemName##ifHaveItem#itemName#Print this#");

    p.parseAddItems(i);
    CPPUNIT_ASSERT(p.getTextDisplay()=="#ifHaveItem#itemName#Print this#");
    CPPUNIT_ASSERT(i.check("itemName"));

    p.parseIfHaveItem(i);

    CPPUNIT_ASSERT(p.getTextDisplay()=="Print this");
}
void TestNewParse::testParseMovement()
{
    Options o;
    Inventory i;
    newParse p("#movement#area1#Print this#");

    p.parseMovement(i,o);

    CPPUNIT_ASSERT(p.getTextDisplay()=="[1] Print this");
}
void TestNewParse::testParseTakeAction()
{
    Options o;
    Inventory i;
    newParse p("#takeAction#jump only once#Print this#");

    p.parseTakeAction(i,o);

    CPPUNIT_ASSERT(p.getTextDisplay()=="[1] Print this");
}
void TestNewParse::testParseConditionalMove()
{
    Options o;
    Inventory i;
    i.add("item1");
    newParse p("#movementIfItem#item1#Area#Print this text#");

    p.parseConditionalMove(i,o);

    CPPUNIT_ASSERT(p.getTextDisplay()=="[1] Print this text");
}
void TestNewParse::testPrint()
{
    newParse p("this");
    p.print();

}
void TestNewParse::testGetTextDisplay()
{
    newParse p("this is text");
    CPPUNIT_ASSERT(p.getTextDisplay()=="this is text");
}
