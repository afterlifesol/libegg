#Objects neede to build the text file

OBJS = eggList_Test.o

#will be using c++11 standard
CXXFLAGS = -std=c++11

#exucutiable in ./bin
eggList_Test : $(OBJS)
		@mkdir -p bin
		$(CXX) $(CXXFLAGS)   -o bin/eggList_Test eggList_Test.cpp 
		@echo "Build - [OK]"
		
.PHONY : clean
clean:
		@rm $(OBJS)
		@rm ./bin/*
		@rmdir bin
		@echo "clean - [OK]"
