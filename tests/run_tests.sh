#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test results counters
PASSED=0
FAILED=0
TOTAL=0

# Function to run a single test
run_test() {
    local test_file=$1
    local test_name=$(basename "$test_file" .peb)
    local expected_file="${test_file%.peb}.expected"
    local output_file="${test_file%.peb}.output"
    
    echo -n "Running test: $test_name... "
    
    # Run the test and capture output
    ../run "$test_file" > "$output_file" 2>&1
    local exit_code=$?
    
    # Check if expected file exists
    if [ -f "$expected_file" ]; then
        # Compare output with expected
        if diff -q "$output_file" "$expected_file" > /dev/null; then
            echo -e "${GREEN}PASSED${NC}"
            ((PASSED++))
        else
            echo -e "${RED}FAILED${NC} (output doesn't match expected)"
            echo -e "${YELLOW}Expected:${NC}"
            cat "$expected_file"
            echo -e "${YELLOW}Actual:${NC}"
            cat "$output_file"
            ((FAILED++))
        fi
    else
        # For error tests, we might just check the exit code
        if [[ "$test_file" == *"errors"* ]]; then
            if [ $exit_code -ne 0 ]; then
                echo -e "${GREEN}PASSED${NC} (expected error occurred)"
                ((PASSED++))
            else
                echo -e "${RED}FAILED${NC} (expected error didn't occur)"
                ((FAILED++))
            fi
        else
            echo -e "${YELLOW}SKIPPED${NC} (no expected output file)"
        fi
    fi
    
    ((TOTAL++))
}

# Function to run all tests in a directory
run_tests_in_dir() {
    local dir=$1
    echo -e "${YELLOW}Running tests in $dir${NC}"
    
    # Check if directory exists and has .peb files
    if [ -d "$dir" ] && [ "$(find "$dir" -name "*.peb" | wc -l)" -gt 0 ]; then
        for test_file in "$dir"/*.peb; do
            run_test "$test_file"
        done
    else
        echo "No tests found in $dir"
    fi
    echo ""
}

# Main script

# Make sure we're in the tests directory
cd "$(dirname "$0")"

# Process command line arguments
if [ $# -eq 0 ]; then
    # Run all tests
    run_tests_in_dir "syntax"
    run_tests_in_dir "errors"
    run_tests_in_dir "features"
    run_tests_in_dir "integration"
elif [ "$1" = "syntax" ] || [ "$1" = "errors" ] || [ "$1" = "features" ] || [ "$1" = "integration" ]; then
    # Run tests in specific category
    run_tests_in_dir "$1"
elif [ -f "$1" ]; then
    # Run a specific test file
    run_test "$1"
else
    echo "Unknown argument: $1"
    echo "Usage: $0 [syntax|errors|features|integration|test_file.peb]"
    exit 1
fi

# Print summary
echo -e "${YELLOW}Test Summary:${NC}"
echo "Total: $TOTAL"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

# Return non-zero exit code if any tests failed
[ $FAILED -eq 0 ]
