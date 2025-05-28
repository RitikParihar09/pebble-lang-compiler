# Pebble Programming Language

Welcome to **Pebble**! Pebble is a simple, C-like, educational programming language designed for learning compiler construction. This guide will help you get started, understand the syntax, and use all the features Pebble supports.

---

## 🚀 Installation & Running

1. **Install dependencies:**
   - You need `bison`, `flex`, and `gcc` installed.
   - On macOS: `brew install bison flex`
   - On Linux: `sudo apt install bison flex gcc`

2. **Build the compiler:**
   ```sh
   make clean
   make
   ```

3. **Run a Pebble program:**
   ```sh
   ./run sample.peb
   ```
   This will compile and run your Pebble code.

---

## 📚 Syntax & Features

### 1. **Variable Declaration**
```pebble
var x = 5
var y = 3.14
var s = "hello"
var c = 'A'
```

### 2. **Constants**
```pebble
const pi = 3.14
```

### 3. **Assignment**
```pebble
x = 10
```

### 4. **Output Functions**
```pebble
// display() - prints with a newline at the end
display(x)
display("Hello, world!")
display(3.14)
display('A')

// print() - prints without a newline at the end
print(x)
print("Hello, world!")
print(3.14)
print('A')

// You can combine print() calls to create a single line
print("Hello, ")
print("World!")  // Outputs: Hello, World!
```

### 5. **Comments**
```pebble
// This is a comment
# This is also a comment
```

### 6. **Arithmetic & Expressions**
```pebble
var sum = x + 5
display(sum)
```

### 7. **If-Else Statements**
```pebble
if (x == 5) {
    display("x is five")
} else {
    display("x is not five")
}
```

### 8. **Loops**

#### Repeat Loops
```pebble
repeat(3) {
    display("Hello")
}
```

#### For Loops
```pebble
for (var i = 0; i < 10; i = i + 1) {
    display(i)
}
```

#### While Loops
```pebble
var x = 0
while (x < 5) {
    display(x)
    x = x + 1
}
```

### 9. **Assignment with Type Checking**
```pebble
var z = 42
z = 100      // OK
z = "hello"  // Error: cannot assign string to int
```

### 10. **Multiple Statements per Line**
```pebble
var a = 1; display(a)
```

### 11. **Semicolons and Newlines**
- You can end statements with either a newline or a semicolon.
- Both are valid:
  ```pebble
  var a = 1
  display(a)
  var b = 2; display(b)
  ```

### 12. **Functions**
```pebble
function add(a, b) {
    return a + b
}

var result = add(2, 3)
display(result)
```

---

## ❗ Error Handling
Pebble provides clear error messages for common mistakes:

| Error Type                | Example Code                | Error Message Example                       |
|--------------------------|-----------------------------|---------------------------------------------|
| Undefined variable       | `display(foo)`              | `[UndefinedVariableError] at line 1: ...`   |
| Redeclaration            | `var x = 1\nvar x = 2`      | `[RedeclarationError] at line 2: ...`       |
| Const assignment         | `const y = 5\ny = 6`        | `[ConstAssignmentError] at line 2: ...`     |
| Type error               | `var z = 1\nz = "hi"`       | `[TypeError] at line 2: ...`                |
| Parse error (syntax)     | `var a =`                   | `[ParseError] at line 1: syntax error`      |

---

## 📝 Example Pebble Program
```pebble
// Variable and output
var a = 10
display(a)

// If-else
if (a == 10) {
    display("Ten")
} else {
    display("Not ten")
}

// Repeat loop
repeat(3) {
    display("Loop!")
}

// Multiple statements per line
var b = 2; display(b)

// Using print without newlines
print("Hello, ")
print("World")
display("!")

// Function call
var result = add(2, 3)
display(result)
```

---

## 🛠️ Advanced Notes
- **No semicolon required** at the end of a line, but you can use one to put multiple statements on a line.
- **Type checking** is enforced: you cannot assign a string to an int, etc.
- **Constants** cannot be reassigned.
- **Comments** can use `//` or `#`.

---

## 💡 Contributing & Extending
- To add new features, edit `compiler/pebble.l` (lexer) and `compiler/pebble.y` (parser).
- Error handling is in `error_handler/error.c` and `error_handler/error.h`.

---

## 📞 Need Help?
If you have questions or want to extend Pebble, read the code in the `compiler/` and `error_handler/` folders, or ask your instructor/mentor!

---

Enjoy learning with Pebble! 🚀