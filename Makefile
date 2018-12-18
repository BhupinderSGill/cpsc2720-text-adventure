CC = gcc
CXX=/opt/centos/devtoolset-1.1/root/usr/bin/g++ #do not change
AR = ar
CXXX = g++11

TESTS = ../tests
SRC = ../src

OBJ = $(SRC:.cpp=.o)
LINKFLAGS = -lcppunit

PROGRAM_TEST = tests

INCLUDES = -I include/
CXXFLAGS = -Wall -g -std=c++11 -lcppunit
CXXXFLAGS = -std=c++11 -g $(INCLUDES)  --coverage

GCOV = gcov11
LCOV = lcov
COVERAGE_RESULTS = coverage.results
COVERAGE_REPORT_DIR = coverage
LCOV_FLAGS = --gcov-tools=$(GCOV) --no-external -b $(SRC)


all: DandyVille

clean: 
	rm -rf *.o *.~
clean-all:
	rm -rf DandyVille

DandyVille :  Inventory.o Menu.o Options.o newParse.o saveLoad.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Inventory.o : src/Inventory.cc
	$(CXX) -c $(CXXFLAGS) $<

Inventory.o: include/Inventory.h

Menu.o : src/Menu.cc
	$(CXX) -c $(CXXFLAGS) $<
Menu.o : include/Menu.h

Options.o : src/Options.cc
	$(CXX) -c $(CXXFLAGS) $<
Options.o : include/Options.h

functions.o:  ../includes/function.h

newParse.o : src/newParse.cc
	$(CXX) -c $(CXXFLAGS) $<
newParse.o : include/newParse.h

saveLoad.o : src/saveLoad.cc
	$(CXX) -c $(CXXFLAGS) $<

saveLoad.o : include/saveLoad.h

main.o : main.cc
	$(CXX) -c $(CXXFLAGS) $<