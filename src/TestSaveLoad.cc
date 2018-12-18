/**
* @file TestSaveLoad.cc
* @brief Test Fixture for SaveLoad class
* tests the SaveLoad functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestSaveLoad.h"
#include <fstream>
//#include "../include/saveLoad.h"
//Exceptions?

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestSaveLoad);

void TestSaveLoad::testSave()
{
    ifstream in;
    string area = "blah.txt", s = "43";
    int time, d;
    bool blah= 0;
    Inventory inv;
    SaveLoad sav;
    in.open(sav.saveFilePath.c_str());
    sav.save(inv, area, time);
    getline(in, s);
    CPPUNIT_ASSERT(s == "save.txt");
    in>>s;
    CPPUNIT_ASSERT(s == area);
    in>>d;
    CPPUNIT_ASSERT(d == time);
}
void TestSaveLoad::testLoad()
{
    ifstream in;
    string area = "blah.txt", s = "43";
    int time;
    bool blah= 0;
    Inventory inv;
    SaveLoad sav;
    in.open(sav.saveFilePath.c_str());
    sav.save(inv, area, time);
    //cout<<blah;
    blah = sav.load(inv, area, time);
    CPPUNIT_ASSERT(blah = 1);
    //cout<<blah;
}
