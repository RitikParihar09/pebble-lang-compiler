CC = gcc
CFLAGS = -Iinclude
FLEX = flex
BISON = bison

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
COMPILER_SRC = $(SRC_DIR)/compiler
ERROR_SRC = $(SRC_DIR)/error_handler
BUILTINS_SRC = $(SRC_DIR)/builtins

# Build files
PARSER_C = $(BUILD_DIR)/parser.c
PARSER_H = $(INCLUDE_DIR)/compiler/parser.h
LEXER_C = $(BUILD_DIR)/lex.yy.c

# Output files
OUTPUT_C = $(BUILD_DIR)/output.c
PROGRAM = $(BUILD_DIR)/program
PEBBLEC = $(BIN_DIR)/pebblec

all: $(PEBBLEC)

$(PEBBLEC): $(PARSER_C) $(LEXER_C) $(ERROR_SRC)/error.c $(BUILTINS_SRC)/pebble_builtins.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(PARSER_C) $(LEXER_C) $(ERROR_SRC)/error.c $(BUILTINS_SRC)/pebble_builtins.c -o $(PEBBLEC) -lm

$(LEXER_C): $(COMPILER_SRC)/pebble.l
	@mkdir -p $(BUILD_DIR)
	$(FLEX) -o $(LEXER_C) $(COMPILER_SRC)/pebble.l

$(PARSER_C) $(PARSER_H): $(COMPILER_SRC)/pebble.y
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(INCLUDE_DIR)/compiler
	$(BISON) -d -o $(PARSER_C) $(COMPILER_SRC)/pebble.y
	@cp $(BUILD_DIR)/parser.h $(PARSER_H)

clean:
	rm -f $(PEBBLEC) $(LEXER_C) $(PARSER_C) $(PARSER_H) $(OUTPUT_C) $(PROGRAM)

# Additional targets for convenience
cleanall: clean
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*