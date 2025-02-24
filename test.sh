#!/bin/bash

# This script will compile the test code and run the tests

echo "Building the project..."
make

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Build failed. Aborting test execution."
    exit 1
fi

# Run the test executable
echo "Running tests..."
./test_runner

# Capture the test result
if [ $? -eq 0 ]; then
    echo "All tests passed!"
else
    echo "Some tests failed."
    exit 1
fi
