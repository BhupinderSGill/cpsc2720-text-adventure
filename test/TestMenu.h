/**
* @file TestMenu.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTMENU_H_INCLUDED
#define TESTMENU_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Menu.h"

class TestMenu : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestMenu);
    CPPUNIT_TEST(testMainMenu);
    CPPUNIT_TEST(testIngameMenu);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing
        */
        void testMainMenu();
        void testIngameMenu();
    private:
};

#endif // TESTMENU_H_INCLUDED
