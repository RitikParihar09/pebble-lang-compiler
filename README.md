
# Pebble Language Compiler

A custom compiler for the **Pebble Programming Language**, built using **Flex** and **Bison**. Pebble is a C-like language designed for simplicity and ease of understanding. This project translates `.peb` source files into C code, compiles the output, and executes it.

## 🚀 Features

- ✅ Lexical analysis using **Flex**
- ✅ Parsing and syntax checking with **Bison**
- ✅ Support for:
  - Variable declarations and assignments
  - `if`, `else`, `while`, and `for` control structures
  - Functions and function calls
  - `try-catch` error handling
  - `display` statement for output
- ✅ C code generation from `.peb` source files
- ✅ Shell script to compile and run output code automatically

## 📁 Project Structure


Pebble/
├── compiler/           # Contains Flex and Bison source files
│   ├── pebble.l        # Lexer rules (Flex)
│   ├── pebble.y        # Parser rules (Bison)
│   └── ...
├── examples/           # Example `.peb` programs
├── output/             # Generated C files and executables
├── run.sh              # Script to compile and run Pebble code
└── README.md           # Project documentation

## ⚙️ How to Use

### 1. Clone the Repository
\`\`\`bash
git clone https://github.com/RitikParihar09/pebble-lang-compiler.git
cd pebble-lang-compiler
\`\`\`

### 2. Build the Compiler
\`\`\`bash
cd compiler
flex pebble.l
bison -d pebble.y
gcc lex.yy.c pebble.tab.c -o pebble_compiler
\`\`\`

### 3. Compile and Run Pebble Code
Use the provided script to compile and run a \`.peb\` file:
\`\`\`bash
./run.sh examples/hello.peb
\`\`\`

## 🧠 Motivation

This project is part of my academic work in compiler design. The goal is to understand and implement how programming languages work under the hood, from lexical analysis to code generation.

## 📌 To-Do / Future Work

- Add support for:
  - Lists and dictionaries
  - Enhanced error messages
  - More data types and operators
- Write a Pebble language manual
- Create a web-based Pebble playground

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## 📜 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Ritik Parihar**  
[GitHub: @RitikParihar09](https://github.com/RitikParihar09)

