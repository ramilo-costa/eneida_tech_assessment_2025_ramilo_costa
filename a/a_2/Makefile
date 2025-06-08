# Makefile for a Generic C Project

# --- Variables ---
# C compiler to use (standard variable for C compiler)
CC = gcc

# Compiler flags
# -Wall: Enable all standard warnings
# -Wextra: Enable extra warnings
# -g: Include debugging information (for GDB)
# -std=c11: Specify C standard (e.g., c99, c11, c17, c18)
# -Iinclude: Add the 'include' directory to the include search path
CFLAGS = -Wall -Wextra -g -std=c11 -Iinclude

# Output executable name
TARGET = output.exe

# Source files
# Automatically find all .c files in the current directory and src/ subdirectory
SRCS = $(wildcard *.c) $(wildcard src/*.c)

# Object files (automatically generated from source files)
# Substitutes .c with .o for each source file, maintaining directory structure
OBJS = $(patsubst %.c, %.o, $(SRCS))

# --- Targets ---

# Default target: builds the executable
all: $(TARGET)

# Rule to link the executable from object files
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CC) $(OBJS) -o $(TARGET)

# Generic rule to compile any .c file into its corresponding .o file.
# $< refers to the first prerequisite (the .c file)
# $@ refers to the target (the .o file)
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

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
