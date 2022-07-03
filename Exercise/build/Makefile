SRC=../src
TARGET=../bin/release
DEBUG_LINK= ../bin/debug
DEBUG= -g -o $(DEBUG_LINK)/db_main.exe
GCC = g++
CFLAGS = -o $(TARGET)/main.exe
# ARGS = 101
MODULE = ../module/src
RM = rm -rf

all: clean module main db clean_object

db: main.o
	$(GCC) $(DEBUG) *.o

main: main.o
	$(GCC) $(CFLAGS) *.o

main.o: 
	$(GCC) -c $(SRC)/main.cpp

module:
	$(GCC) -c $(MODULE)/*.cpp

debug:
	gdb $(DEBUG_LINK)/db_main.exe

run:
	$(TARGET)/main.exe

clean:
	$(RM) $(TARGET)/*.exe *.o

clean_object:
	$(RM) *.o