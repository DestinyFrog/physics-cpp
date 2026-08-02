CXX = g++
CXXFLAGS = -Iinclude -I/usr/local/include -Wall -std=c++20
LDFLAGS = -L/usr/local/lib
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

BUILD_DIR = build
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))
TARGET = output.o

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)
