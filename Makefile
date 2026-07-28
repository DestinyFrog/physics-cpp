CXX = g++
CXXFLAGS = -Iinclude -I/usr/local/include -Wall -std=c++20
LDFLAGS = -L/usr/local/lib
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = output.o

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)