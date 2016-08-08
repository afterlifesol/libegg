#Objects needed to build the test file
OBJS = TestList.o TestStack.o egglibTest.o egglibInfo.o

#will be using c++11 standard
CXXFLAGS = -std=c++11 -Wfatal-errors

all : egglibInfo egglibTest

#exucutiable in ./bin
egglibInfo : 
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/egglibInfo egglibInfo.cpp
		@echo "Build - [OK]"

#exucutiable in ./bin
eggInfo : egglibInfo.o
		@./bin/egglibInfo


TestList : TestList.o
TestStack : TestStack.o

#exucutiable in ./bin
egglibTest : TestList.o TestStack.o egglibTest.o
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/egglibTest TestList.o TestStack.o egglibTest.o
		@echo "Build - [OK]"

#exucutiable in ./bin
eggTest : egglibTest
		@./bin/egglibTest

.PHONY : clean
clean:
		@rm -f $(OBJS)
		@rm -f ./bin/*
		@rmdir bin
		@echo "clean - [OK]"
