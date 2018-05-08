CXX=g++
CXXFLAGS= -O3 -lmetis
TARGET=main

SRC=$(shell ls *.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $+ -o $@ $(CXXFLAGS)

clean:
	$(RM) *.o *.d $(TARGET)

.PHONY: all clean
