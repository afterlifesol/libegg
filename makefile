#Objects needed to build the test file
OBJS = eggList_Test.o eggStack_Test.o

#will be using c++11 standard
CXXFLAGS = -std=c++11 -Wfatal-errors

all : eggList eggStack

#exucutiable in ./bin
eggList : eggList_Test.o
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/eggList_Test eggList_Test.cpp
		@echo "Build - [OK]"

eggList_Test : eggList
		@./bin/eggList_Test

#exucutiable in ./bin
eggStack : eggStack_Test.o
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/eggStack_Test eggStack_Test.cpp
		@echo "Build - [OK]"

eggStack_Test : eggStack
		@./bin/eggStack_Test

#exucutiable in ./bin
Tests : eggList eggStack

.PHONY : clean
clean:
		@rm $(OBJS)
		@rm ./bin/*
		@rmdir bin
		@echo "clean - [OK]"
