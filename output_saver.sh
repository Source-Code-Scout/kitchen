#!/bin/bash

# Check if a file name was provided
if [ $# -eq 0 ]; then
    echo "Please provide a C++ file name as an argument."
    echo "Usage: $0 <cpp_file_name>"
    exit 1
fi

# Get the C++ file name from the command line argument
cpp_file="$1"

# Check if the file exists
if [ ! -f "$cpp_file" ]; then
    echo "Error: File '$cpp_file' not found."
    exit 1
fi

# Extract the base name of the file (without extension)
base_name=$(basename "$cpp_file" .cpp)

# Compile and run the C++ program, saving the output
# g++ -o "$base_name" "$cpp_file" -fconcepts && "./$base_name" > output.txt
# g++ -o "$base_name" "$cpp_file" -fconcepts && "./$base_name" > output.txt
g++ -O0 -std=c++11 "$cpp_file" -o "$base_name" && "./$base_name" > output.txt


# Check if compilation and execution were successful
if [ $? -ne 0 ]; then
    echo "Error: Compilation or execution failed."
    rm -f output.txt
    exit 1
fi

# Create a new file with the C++ code and its output
{
    cat "$cpp_file"
    echo
    echo "/*"
    echo "Program Output:"
    echo $date
    echo "==============="
    cat output.txt
    echo "*/"
    echo "// ======================================================================================================================================================"

} >> "./outputs/${base_name}_result.cpp"

# Clean up
rm -f "$base_name" output.txt

echo "Results have been saved to ./outputs/${base_name}_result.txt"