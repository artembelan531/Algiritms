CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRC_DIR = src
FUNCTION_DIR = function
TEST_DIR = tests

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
FUNCTION_FILES = $(wildcard $(FUNCTION_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o) $(FUNCTION_FILES:.cpp=.o)

EXECUTABLE = main

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJ_FILES)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(FUNCTION_DIR)/%.o: $(FUNCTION_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
