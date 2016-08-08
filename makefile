#Objects needed to build the test file
OBJS = TestList.o TestStack.o libeggTest.o libeggInfo.o

#will be using c++11 standard
CXXFLAGS = -std=c++11 -Wfatal-errors

all : libeggInfo libeggTest

#exucutiable in ./bin
libeggInfo : 
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/libeggInfo libeggInfo.cpp
		@echo "Build - [OK]"

#exucutiable in ./bin
eggInfo : libeggInfo.o
		@./bin/libeggInfo


TestList : TestList.o
TestStack : TestStack.o

#exucutiable in ./bin
libeggTest : TestList.o TestStack.o libeggTest.o
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/libeggTest TestList.o TestStack.o libeggTest.o
		@echo "Build - [OK]"

#exucutiable in ./bin
eggTest : libeggTest
		@./bin/libeggTest

.PHONY : clean
clean:
		@rm -f $(OBJS)
		@rm -f ./bin/*
		@rmdir bin
		@echo "clean - [OK]"
