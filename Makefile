#
# FOR DEBUG MODE: add DEBUN=ON to command line of make
# make libeggTest DEBUG=ON
#




#
# Compiler
#
CXX = g++

#
# Compiler flags
#
#add '-Werror' to make warrings into errors
#cpp flags
CXXFLAGS = -std=c++11 -Wall -Wextra -Wconversion -Wfatal-errors
#debug flags
DEBUGCXXFLAGS = -g3 -O0 -DDEBUG
#release flags
RELESECXXFLAGS = -O3 -DNDEBUG




#
# Directory Setttings
#
DEBUGDIR = debug
BUILDDIR = bin
#RELEXE = $(RELDIR)/$(EXE)


ifdef DEBUG
DIR = $(DEBUGDIR)
CXXFLAGS += $(DEBUGCXXFLAGS)
else
DIR = $(BUILDDIR)
CXXFLAGS += $(RELESECXXFLAGS)
endif

#programmer changes
RELESECXXFLAGS = -O2 -g -DDEBUG




#
# Project Files
#
#OBJS=libeggTest.o TestList.o TestStack.o





#
# Genreal Patter rules
#
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

%.hpp:
	make -t $@





#
# libegg TARGETS
#


#EXE
libeggEquIndex : libeggEquIndex.o
	$(CXX) $(CXXFLAGS) -o $(DIR)/$@ $(filter %.c %.cpp %.o %.a, $?)

TestStack : TestStack.o libeggStack.hpp
	$(CXX) -c $(CXXFLAGS) -o $(DIR)/$@ $<

TestList : TestList.o libeggList.hpp
	$(CXX) -c $(CXXFLAGS) -o $(DIR)/$@ $<

#EXE
libeggInfo : libeggInfo.cpp
	$(CXX) $(CXXFLAGS) -o $(DIR)/$@ $(filter %.c %.cpp %.o %.a, $?)

#EXE
libeggTest : libeggTest.cpp TestStack.o TestList.o libeggCheck.o libeggCheck.h libeggStack.hpp libeggList.hpp
	$(CXX) $(CXXFLAGS) -o $(DIR)/$@ $(filter %.c %.cpp %.o %.a, $?)





#
# meta TARGETS
#

.PHONY: all clean prep remake

all: prep release

clean:
	rm -f *.o ./$(DEBUGDIR)/* ./$(BUILDDIR)/*

prep:
	@mkdir -p $(DEBUGDIR) $(BUILDDIR)

remake: clean all








#
# Other Rules
#









#debug extras...  -pedantic -Wextra -

#
#for debugger: -O0 -g -Wall
#for development and internal release: -O2 -g -Wall
#for release outside the company: -O2 -Wall
#

#
#$@ name of the target
#$^ name of all prerequisites with duplicates removed
#$< name of the first prerequisite 
#



