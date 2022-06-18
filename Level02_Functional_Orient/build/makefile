SRC=../src
TARGET=../bin/debug
GCC = g++
CFLAGS = -o $(TARGET)/main.exe
# ARGS = 101
MODULE = ../module/src
RM = rm -rf

all: clean module main

main: main.o
	$(GCC) $(CFLAGS) *.o

main.o: 
	$(GCC) -c $(SRC)/main.cpp

module:
	$(GCC) -c $(MODULE)/*.cpp

run:
	$(TARGET)/main.exe # $(ARGS)

clean:
	$(RM) $(TARGET)/*.exe *.o