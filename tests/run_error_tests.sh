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

# Make sure we're in the tests directory
cd "$(dirname "$0")"

# Run all error tests
echo -e "${YELLOW}Running error tests${NC}"

for test_file in errors/*.peb; do
    test_name=$(basename "$test_file" .peb)
    echo -n "Running test: $test_name... "
    
    # Run the test and capture output and exit code
    ../run "$test_file" > /dev/null 2>&1
    exit_code=$?
    
    # For error tests, we expect a non-zero exit code
    if [ $exit_code -ne 0 ]; then
        echo -e "${GREEN}PASSED${NC} (expected error occurred)"
        ((PASSED++))
    else
        echo -e "${RED}FAILED${NC} (expected error didn't occur)"
        ((FAILED++))
    fi
    
    ((TOTAL++))
done

# Print summary
echo -e "${YELLOW}Error Test Summary:${NC}"
echo "Total: $TOTAL"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

# Return non-zero exit code if any tests failed
[ $FAILED -eq 0 ]
