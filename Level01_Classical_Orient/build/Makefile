SRC=../src
TARGET=../bin/debug/
GCC = g++
CFLAGS = -o $(TARGET)/main.exe
# ARGS = 101
RM = rm -rf

all: clean default

default: main.cpp

main.cpp:
	$(GCC) $(CFLAGS) $(SRC)/main.cpp

run:
	$(TARGET)/main.exe # $(ARGS)

clean:
	$(RM) $(TARGET)/*.exe