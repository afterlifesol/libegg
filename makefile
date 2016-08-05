#Objects needed to build the text file
OBJS = eggList_Test.o

#will be using c++11 standard
CXXFLAGS = -std=c++11 -Wfatal-errors

#exucutiable in ./bin
eggList : $(OBJS)
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/eggList_Test eggList_Test.cpp
		@echo "Build - [OK]"


#exucutiable in ./bin
Test : $(OBJS)
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/eggList_Test eggList_Test.cpp
		@echo "Build - [OK]"
		@./bin/eggList_Test
	
.PHONY : clean
clean:
		@rm $(OBJS)
		@rm ./bin/*
		@rmdir bin
		@echo "clean - [OK]"
