/**
* @file TestParse.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTPARSE_H_INCLUDED
#define TESTPARSE_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/Parse.h"

class TestParse : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestParse);
    CPPUNIT_TEST(testParseAddItems);
    CPPUNIT_TEST(testParseIfHaveItem);
    CPPUNIT_TEST(testParseMovement);
    CPPUNIT_TEST(testParseTakeAction);
    CPPUNIT_TEST(testParseConditionalMove);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing parseAddItems
        */
        void testParseAddItems();
        /**
        * Method for testing parseIfHaveItem
        */
        void testParseIfHaveItem();
        /**
        * Method for testing parseMovement
        */
        void testParseMovement();
        /**
        * Method for testing parseTakeAction
        */
        void testParseTakeAction();
        /**
        * Method for testing parseConditionalMove
        */
        void testParseConditionalMove();
    private:
};

#endif // TESTPARSE_H_INCLUDED
