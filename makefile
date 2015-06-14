#
# Makefile build 'Hell_in_the_sky' using Make
#

SOURCES = $(wildcard src/*.cpp)

CC      = g++
CFLAGS  = -c -g -Wall -std=c++11

INC_DIR = ./include
BIN_DIR = ./bin
APP     = $(BIN_DIR)/hell
LIB_DIR = 
LIBS = \
	-lsfml-graphics         \
	-lsfml-window           \
	-lsfml-system

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(APP)
    
$(APP): $(OBJECTS) 
	$(CC) -o $@ $(OBJECTS) $(LIBS)

.cpp.o:
	$(CC) $< -o $@ $(CFLAGS) -I$(INC_DIR)