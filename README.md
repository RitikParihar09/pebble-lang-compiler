# Pebble Programming Language

Pebble is a simple, educational programming language designed for learning compiler construction. It features a C-like syntax with static typing and built-in functions for common operations.

## Features

- Variable declarations and assignments
- Basic data types: integers, floats, strings, characters, and booleans
- Arithmetic and logical operations
- Conditional statements (if-else)
- Repeat loops
- Functions with parameters
- User input with type conversion
- Display output

## Project Structure

```
pebble/
├── bin/                  # Compiled binaries
├── build/                # Build artifacts
├── docs/                 # Documentation
├── examples/             # Example Pebble programs
├── include/              # Header files
│   ├── compiler/
│   └── error_handler/
├── src/                  # Source code
│   ├── compiler/         # Compiler source files
│   ├── error_handler/    # Error handling source files
│   └── builtins/         # Built-in functions
├── tests/                # Test files
├── Makefile
├── README.md
└── run                   # Run script
```

## Getting Started

### Prerequisites

- GCC compiler
- Flex (lexical analyzer generator)
- Bison (parser generator)

### Installation

On macOS:
```bash
brew install flex bison
```

On Ubuntu:
```bash
sudo apt install flex bison gcc
```

### Building

```bash
make
```

### Running a Pebble Program

```bash
./run examples/input_test.peb
```

## Syntax Examples

### Variable Declaration

```
var x = 5
var name = "John"
var pi = 3.14
var isActive = true
var letter = 'A'
```

### User Input

```
// Method 1
ask "What is your name? " and save as name

// Method 2
var age = input("How old are you? ")

// Converting input to other types
var num_str = input("Enter a number: ")
var num = to_int(num_str)
```

### Conditional Statements

```
if (x > 5) {
    display("x is greater than 5")
} else {
    display("x is not greater than 5")
}
```

### Loops

```
repeat(5) {
    display("Hello")
}
```

### Functions

```
function add(a, b) {
    display(a + b)
}

add(5, 10)
```

## License

This project is open source and available under the MIT License.
