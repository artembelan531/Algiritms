CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC_DIR = src
INCLUDE_DIR = include
FUNCTION_DIR = function
TEST_DIR = tests

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) \
            $(wildcard $(FUNCTION_DIR)/*.cpp)

OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Оставляем main.cpp только для сборки основного бинарника
NON_MAIN_SRC_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES))
NON_MAIN_OBJ_FILES = $(NON_MAIN_SRC_FILES:.cpp=.o)

TARGET = ascii85

GTEST_FLAGS = -lgtest -lgtest_main -pthread
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(TEST_FILES:.cpp=.o)
TEST_EXECUTABLE = test_ascii85

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# GoogleTest build без main.cpp
$(TEST_EXECUTABLE): $(NON_MAIN_OBJ_FILES) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(GTEST_FLAGS)

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

.PHONY: test clean run

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ_FILES) $(NON_MAIN_OBJ_FILES) $(TEST_OBJ) $(TARGET) $(TEST_EXECUTABLE)
