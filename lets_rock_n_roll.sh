#!/bin/bash

LIBFT_DIR="."
TESTS_DIR="tests"

# Compile each directory by running make
echo "Compiling libft..."
(cd "$LIBFT_DIR" && make) || { echo "Error: Failed to compile libft"; exit 1; }

echo "Compiling tests..."
(cd "$TESTS_DIR" && make) || { echo "Error: Failed to compile tests"; exit 1; }

echo "All components compiled successfully."
