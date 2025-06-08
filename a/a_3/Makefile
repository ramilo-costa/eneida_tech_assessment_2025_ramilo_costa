# Makefile for a Generic C++ Project

# --- Variables ---
# C++ compiler to use
CXX = g++

# Compiler flags
# -Wall: Enable all standard warnings
# -Wextra: Enable extra warnings
# -g: Include debugging information (for GDB)
# -std=c++11: Specify C++ standard (or c++14, c++17, c++20)
# -Iinclude: Add the 'include' directory to the include search path
CXXFLAGS = -Wall -Wextra -g -std=c++11 -Iinclude

# Output executable name
TARGET = output.exe

# Source files
# Automatically find all .cpp files in the current directory and src/ subdirectory
SRCS = $(wildcard *.cpp) $(wildcard src/*.cpp)

# Object files (automatically generated from source files)
# Substitutes .cpp with .o for each source file, maintaining directory structure
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

# --- Targets ---

# Default target: builds the executable
all: $(TARGET)

# Rule to link the executable from object files
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJS) -o $(TARGET)

# Generic rule to compile any .cpp file into its corresponding .o file.
# This rule will handle both 'main.cpp' and 'src/message_receiver.cpp' by
# creating 'main.o' and 'src/message_receiver.o' respectively.
# $< refers to the first prerequisite (the .cpp file)
# $@ refers to the target (the .o file)
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony targets: these are not actual files, but commands
.PHONY: all clean run

# Clean target: removes generated files
clean:
	@echo "Cleaning up..."
	@rm -f $(TARGET) $(OBJS)

# Run target: executes the compiled program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)
