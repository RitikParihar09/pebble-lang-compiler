# Pebble Language Test Suite

This directory contains tests for the Pebble programming language. The tests are organized into categories and can be run individually or as a group.

## Test Directory Structure

- `syntax/` - Tests for syntax features of the language
- `errors/` - Tests for error handling and error messages
- `features/` - Tests for specific language features
- `integration/` - More complex tests combining multiple features

## Running Tests

### Run all tests

```bash
./run_tests.sh
```

### Run tests in a specific category

```bash
./run_tests.sh syntax
./run_tests.sh errors
./run_tests.sh features
./run_tests.sh integration
```

### Run a specific test

```bash
./run_tests.sh path/to/test.peb
```

### Run only error tests

```bash
./run_error_tests.sh
```

## Adding New Tests

1. Create a new `.peb` file in the appropriate directory
2. For tests with expected output, create a `.expected` file with the same base name
3. For error tests, no `.expected` file is needed (the test passes if the compiler returns an error)

## Test File Format

### Regular Test

```
// Test: Description of what is being tested
// Any additional comments

// Pebble code goes here
var x = 5
display(x)
```

### Expected Output File

Create a file with the same name as your test but with the `.expected` extension. This file should contain the exact output you expect from running the test.

## Automated Testing

The test runner compares the actual output of each test with the expected output in the corresponding `.expected` file. For error tests, it checks that the compiler returns a non-zero exit code.

## Interactive Tests

Some tests (like those involving user input) are meant to be run interactively and cannot be automatically verified. These tests should be clearly marked with a comment at the top of the file.
