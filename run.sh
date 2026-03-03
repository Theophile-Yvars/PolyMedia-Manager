#!/bin/bash

# Exit on error
set -e

# Path to the build folder
BUILD_DIR=build

# Check if executable exists
EXEC="$BUILD_DIR/PolyMediaMain"

if [ ! -f "$EXEC" ]; then
    echo "Executable not found. Please build first!"
    exit 1
fi

# Run the executable
echo "Running PolyMediaMain..."
"$EXEC"