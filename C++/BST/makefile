# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Source files
SOURCES = main.cpp bst.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
TARGET = main

# Build rule
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJECTS)

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Usage: make          (to build the program)
#        make clean    (to clean up object files and the executable)
