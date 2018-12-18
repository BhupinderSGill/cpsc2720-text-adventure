/**
* @file TestSaveLoad.h
* @brief Test Suite to be added to the test runner
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#ifndef TESTSAVELOAD_H_INCLUDED
#define TESTSAVELOAD_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>
#include "../include/saveLoad.h"

class TestSaveLoad : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSaveLoad);
    CPPUNIT_TEST(testSave);
    CPPUNIT_TEST(testLoad);
    CPPUNIT_TEST_SUITE_END();

    public:
        /**
        * Method for testing
        */
        void testSave();
        void testLoad();
    private:
};

#endif // TESTSAVELOAD_H_INCLUDED
