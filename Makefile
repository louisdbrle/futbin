CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g

LIB_DIR=Libs
LIBFLAGS=

SRC_DIR=Sources
SRC= $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard main.cpp)

OBJ= $(SRC:.cpp=.o)

TST_DIR=Tests/
TST= $(wildcard $(TST_DIR)/*.cpp)

OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= main


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

test : testcase
	cd $(TST_DIR); ./testcase

$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) $(LIBFLAGS) $^ -o $@  

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ)

mrclean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest
