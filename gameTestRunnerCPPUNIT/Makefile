# some settings...
# use the gnu C++ compiler
CCC= g++11
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lX11

# all is called a target, matrixTest is called a dependency
# ie. "the target all is dependent on the executable matrixTest

# the target matrixTest is dependent on matrix.o and matrixtest.o
# the following line is the required executable
mainTest : obj/Debug/gameTestRunnerCPPUNIT/mainTest.o obj/Debug/src/TestInventory.o obj/Debug/src/TestMenu.o obj/Debug/src/TestOther.o obj/Debug/src/TestParse.o obj/Debug/src/TestSaveLoad.o obj/Debug/src/Inventory.o obj/Debug/src/saveLoad.o obj/Debug/src/Menu.o obj/Debug/src/Other.o obj/Debug/src/Parse.o 
	$(CCC) $(CCCFLAGS) $^ -o $@
# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Don't need next two lines because of the above default rule
# But no harm including them
# In the following two lines make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line
obj/Debug/src/TestInventory.o : ../test/TestInventory.h ../include/Inventory.h
obj/Debug/src/Menu.o : ../test/TestMenu.h ../include/Menu.h ../include/Inventory.h ../include/Other.h
obj/Debug/src/Other.o : ../test/TestOther.h ../include/Other.h ../include/Inventory.h ../include/saveLoad.h
obj/Debug/src/Parse.o : ../test/TestParse.h ../include/Parse.h ../include/Other.h ../include/Inventory.h
obj/Debug/src/saveLoad.o : ../test/TestSaveLoad.h ../include/saveLoad.h ../include/Inventory.h
clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f mainTest
