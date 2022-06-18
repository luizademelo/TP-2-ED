CC = g++ 
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/wordcounter.o
HDRS = $(INC)/wordcounter.hpp 

TARGET = tp2

all: $(TARGET)

$(TARGET): $(SRC)/wordcounter.cpp $(SRC)/main.cpp 
	$(CC) $(SRC)/wordcounter.cpp $(SRC)/main.cpp -o $(TARGET)
