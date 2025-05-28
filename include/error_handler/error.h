#ifndef ERROR_H
#define ERROR_H

// ANSI color codes for terminal output
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD          "\x1b[1m"
#define ANSI_UNDERLINE     "\x1b[4m"

// Error severity levels
typedef enum {
    WARNING,    // Non-fatal warning
    ERROR,      // Fatal error
    FATAL       // Fatal error with immediate exit
} ErrorSeverity;

// Error categories
typedef enum {
    SYNTAX_ERROR,       // Syntax errors (parsing)
    TYPE_ERROR,         // Type mismatch errors
    NAME_ERROR,         // Variable/function name errors
    REFERENCE_ERROR,    // Reference to undefined variables
    DECLARATION_ERROR,  // Declaration errors (redeclaration, etc.)
    IO_ERROR,           // Input/output errors
    RUNTIME_ERROR,      // Runtime errors
    INTERNAL_ERROR      // Internal compiler errors
} ErrorCategory;

// Main error reporting function
void pebble_error(const char* type, int lineno, const char* msg, const char* detail);

// Enhanced error reporting function
void pebble_report_error(
    ErrorCategory category,
    ErrorSeverity severity,
    int lineno,
    int column,
    const char* msg,
    const char* detail,
    const char* suggestion
);

// Helper functions for common errors
void syntax_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion);
void type_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion);
void name_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion);
void reference_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion);
void declaration_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion);

// Warning function (non-fatal)
void pebble_warning(int lineno, int column, const char* msg, const char* detail, const char* suggestion);

// Get error category name as string
const char* get_error_category_name(ErrorCategory category);

// Global error tracking
extern int error_count;
extern int warning_count;

// Reset error counts
void reset_error_counts();

// Check if errors occurred
int has_errors();

#endif