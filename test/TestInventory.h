/**
* @file TestInventory.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTINVENTORY_H_INCLUDED
#define TESTINVENTORY_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Inventory.h"
#include <string>
#include <sstream>

class TestInventory : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestInventory);
    CPPUNIT_TEST(testInventory);
//    CPPUNIT_TEST(addcheck);
//    CPPUNIT_TEST(forget);
//    CPPUNIT_TEST(testSaveLoad);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing
        */
        ///Tests that constructing an inventory doesn't crash anything
        void testInventory();
        ///This tests add and check
        ///Since add cannot be tested without check
        void addcheck();
        ///This checks what happens when an item does not exist.
        void emptycheck();
        ///This tests if we can forget things.
        void forget();
        ///This cannot be tested through a true or false unit test
        ///since we deliberately did not define the kind of whitespace
        ///that we wanted.
        void print();
        ///This function tests if the save and load functions
        ///work with each other.
        void testSaveLoad();
    private:
};

#endif // TESTINVENTORY_H_INCLUDED
