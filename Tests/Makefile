CC= g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIB_DIR= Libs
LIBFLAGS= -I/usr/included/SDL2 -lSDL2_image -lSDL2_ttf -lSDL2

SRC_DIR=../Sources
SRC= $(wildcard $(SRC_DIR)/*/*.cpp)
OBJ= $(SRC:.cpp=.o)

TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cpp=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS) $^ -o $@  $(LIBFLAGS)  

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase
