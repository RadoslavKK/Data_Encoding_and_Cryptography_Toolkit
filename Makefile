CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC = $(shell find src -name '*.cpp')
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
TARGET = bin/EncodingToolkit++

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CXX) $(OBJ) -o $@

# Create necessary directories and compile each source file
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET) keys/base64Key.txt

clean:
	rm -rf build bin/*