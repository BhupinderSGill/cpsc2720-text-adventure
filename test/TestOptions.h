/**
* @file TestOptions.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTOPTIONS_H_INCLUDED
#define TESTOPTIONS_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Options.h"

class TestOptions : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestOptions);
    CPPUNIT_TEST(testOptions);
    CPPUNIT_TEST(testReset);
    CPPUNIT_TEST(testAddChoice);
    CPPUNIT_TEST(testAskCommand);
    CPPUNIT_TEST(testSetCommand);
    CPPUNIT_TEST(testGetCommand);
    CPPUNIT_TEST(testHandleChoice);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing options()
        */
        void testOptions();
        /**
        * Method for testing reset()
        */
        void testReset();
        /**
        * Method for testing addChoice()
        */
        void testAddChoice();
        /**
        * Method for testing askCommand()
        */
        void testAskCommand();
        /**
        * Method for testing setCommand()
        */
        void testSetCommand();
        /**
        * Method for testing getCommand()
        */
        void testGetCommand();
        /**
        * Method for testing handleChoice()
        */
        void testHandleChoice();

    private:
};

#endif // TESTOPTIONS_H_INCLUDED

