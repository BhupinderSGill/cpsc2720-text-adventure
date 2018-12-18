/**
* @file TestNewParse.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTNEWPARSE_H_INCLUDED
#define TESTNEWPARSE_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/newParse.h"

class TestNewParse : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestNewParse);
    CPPUNIT_TEST(testNewParse);
    CPPUNIT_TEST(testNewParseInput);
    CPPUNIT_TEST(testLoadArea);
    CPPUNIT_TEST(testAddTime);
    CPPUNIT_TEST(testParseAddItems);
    CPPUNIT_TEST(testParseIfHaveItem);
    CPPUNIT_TEST(testParseMovement);
    CPPUNIT_TEST(testParseTakeAction);
    CPPUNIT_TEST(testParseConditionalMove);
    CPPUNIT_TEST(testPrint);
    CPPUNIT_TEST(testGetTextDisplay);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing newParse
        */
        void testNewParse();
        /**
        * Method for testing newParse(string textDis)
        */
        void testNewParseInput();
        /**
        * Method for testing loadArea
        */
        void testLoadArea();
        /**
        * Method for testing addTime
        */
        void testAddTime();
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
        /**
        * Method for testing print
        */
        void testPrint();
        /**
        * Method for testing getTextDisplay()
        */
        void testGetTextDisplay();

    private:
};

#endif // TESTNEWPARSE_H_INCLUDED
