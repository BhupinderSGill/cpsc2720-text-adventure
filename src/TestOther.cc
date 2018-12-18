/**
* @file TestOther.cc
* @brief Test Fixture for Other
* tests the Other functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestOther.h"
#include "Inventory.h"
#include <string>
#include <iostream>
#include <fstream>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestOther);

void TestOther::testCheckSuccessfulGame()
{
    Inventory invent1,invent2,invent3,invent4,invent5;

    // cutoff 4 only 3 item fail
    invent1.add("Petition");
    invent1.add("BhupinderSignature");
    invent1.add("ParanoiaSignature");
    invent1.add("JuliusSignature");
    //CPPUNIT_ASSERT(checkSuccessfulGame(invent1)==0);

    // cutoff 4 have 5 items win
    invent2.add("Petition");
    invent2.add("BhupinderSignature");
    invent2.add("ParanoiaSignature");
    invent2.add("JuliusSignature");
    invent2.add("KolodySignature");
    invent2.add("CramerSignature");
    CPPUNIT_ASSERT(checkSuccessfulGame(invent2)==1);

    // cutoff 2 have 1 items fail
    invent3.add("Petition");
    invent3.add("Documents");
    invent3.add("BhupinderSignature");
    CPPUNIT_ASSERT(checkSuccessfulGame(invent3)==0);

    // cutoff 2 have 3 items win
    invent4.add("Petition");
    invent4.add("Documents");
    invent4.add("BhupinderSignature");
    invent4.add("ParanoiaSignature");
    invent4.add("JuliusSignature");
    CPPUNIT_ASSERT(checkSuccessfulGame(invent4)==1);

    // no petition BIG LOSE GAME
    invent5.add("BhupinderSignature");
    invent5.add("ParanoiaSignature");
    invent5.add("JuliusSignature");
    invent5.add("KolodySignature");
    invent5.add("CramerSignature");
    CPPUNIT_ASSERT(checkSuccessfulGame(invent4)==1);
    /*
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
    */
}

void TestOther::testHandleChoices()
{
    Inventory inventory;
    string current="Current Place";
    ifstream CurrentArea;
    // initialize options
    optionsStruct options;
    options.numOfChoices=0;
    for(int i=0;i<10;i++)
    {
        options.nextArea[i]=current;
        options.choice[i]=nothing;
    }

    /*
    // takeAction
    options.choice[1]=takeAction;
    options.nextArea[1]="Area1";
    handleChoices(1,inventory,current,CurrentArea,options);
    CPPUNIT_ASSERT(inventory.check("Area1"));
    CPPUNIT_ASSERT(options.choice[1]==takeAction);
    // movement
    options.choice[2]=movement;
    options.nextArea[2]="Area2";
    handleChoices(2,inventory,current,CurrentArea,options);
    CPPUNIT_ASSERT(!inventory.check(current));
    CPPUNIT_ASSERT(options.choice[2]==movement);

    // nothing
    options.choice[3]=nothing;
    options.nextArea[3]="Area3";
    handleChoices(3,inventory,current,CurrentArea,options);
    CPPUNIT_ASSERT(options.choice[3]==nothing);
    CPPUNIT_ASSERT(!inventory.check(current));
    */
}

