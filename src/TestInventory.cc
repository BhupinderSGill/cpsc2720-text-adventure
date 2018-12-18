/**
* @file TestInventory.cc
* @brief Test Fixture for inventory class
* tests the inventory functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "TestInventory.h"
//Exceptions?

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestInventory);

void TestInventory::testSaveLoad() {
    Inventory a{}, b{};
    a.add("socks");
    a.add("couch");
    a.add("pooch");
    a.forget("socks");
    std::ostringstream out;
    a.save(out);
    std::istringstream in{out.str()};
    b.load(in);
    std::ostringstream out2{};
    b.save(out2);
    CPPUNIT_ASSERT(out.str() == out2.str());
}

void TestInventory::emptycheck() {
    Inventory a{};
    CPPUNIT_ASSERT(!a.check("apple"));
}

void TestInventory::addcheck() {
    Inventory a{};
    a.add("apple");
    CPPUNIT_ASSERT(a.check("apple"));
}

void TestInventory::forget() {
    Inventory a{};
    a.add("apple");
    a.forget("apple");
    CPPUNIT_ASSERT(!a.check("apple"));
}

void TestInventory::testInventory() {
    CPPUNIT_ASSERT_NO_THROW(Inventory{});
}
