/**
* @file TestOther.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTOTHER_H_INCLUDED
#define TESTOTHER_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Other.h"

class TestOther : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestOther);
    CPPUNIT_TEST(testCheckSuccessfulGame);
    CPPUNIT_TEST(testHandleChoices);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing checkSuccessfulGame()
        */
        void testCheckSuccessfulGame();
        /**
        * Method for testing handleChoices()
        */
        void testHandleChoices();
    private:
};

#endif // TESTOTHER_H_INCLUDED
