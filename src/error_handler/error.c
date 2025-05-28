#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_handler/error.h"

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

// Global error tracking
int error_count = 0;
int warning_count = 0;

// Reset error counts
void reset_error_counts() {
    error_count = 0;
    warning_count = 0;
}

// Check if errors occurred
int has_errors() {
    return error_count > 0;
}

// Get error category name as string
const char* get_error_category_name(ErrorCategory category) {
    switch (category) {
        case SYNTAX_ERROR:      return "SyntaxError";
        case TYPE_ERROR:        return "TypeError";
        case NAME_ERROR:        return "NameError";
        case REFERENCE_ERROR:   return "ReferenceError";
        case DECLARATION_ERROR: return "DeclarationError";
        case IO_ERROR:          return "IOError";
        case RUNTIME_ERROR:     return "RuntimeError";
        case INTERNAL_ERROR:    return "InternalError";
        default:                return "UnknownError";
    }
}

// Legacy error function for backward compatibility
void pebble_error(const char* type, int lineno, const char* msg, const char* detail) {
    if (detail)
        fprintf(stderr, ANSI_COLOR_RED ANSI_BOLD "[%s]" ANSI_COLOR_RESET " at line %d: %s: %s\n",
                type, lineno, msg, detail);
    else
        fprintf(stderr, ANSI_COLOR_RED ANSI_BOLD "[%s]" ANSI_COLOR_RESET " at line %d: %s\n",
                type, lineno, msg);
    error_count++;
    exit(1);
}

// Enhanced error reporting function
void pebble_report_error(
    ErrorCategory category,
    ErrorSeverity severity,
    int lineno,
    int column,
    const char* msg,
    const char* detail,
    const char* suggestion
) {
    const char* category_name = get_error_category_name(category);
    const char* severity_color = "";

    // Choose color based on severity
    switch (severity) {
        case WARNING:
            severity_color = ANSI_COLOR_YELLOW;
            warning_count++;
            break;
        case ERROR:
            severity_color = ANSI_COLOR_RED;
            error_count++;
            break;
        case FATAL:
            severity_color = ANSI_COLOR_RED ANSI_BOLD;
            error_count++;
            break;
    }

    // Print error header with location
    fprintf(stderr, "%s[%s]%s at line %d",
            severity_color, category_name, ANSI_COLOR_RESET, lineno);

    // Add column information if available
    if (column > 0) {
        fprintf(stderr, ", column %d", column);
    }

    // Print error message
    fprintf(stderr, ": %s", msg);

    // Add detail if available
    if (detail && strlen(detail) > 0) {
        fprintf(stderr, ": '%s'", detail);
    }

    fprintf(stderr, "\n");

    // Add suggestion if available
    if (suggestion && strlen(suggestion) > 0) {
        fprintf(stderr, "  %s%s%s\n",
                ANSI_COLOR_GREEN, suggestion, ANSI_COLOR_RESET);
    }

    // Exit immediately for fatal errors
    if (severity == FATAL) {
        exit(1);
    }
}

// Helper functions for common errors
void syntax_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(SYNTAX_ERROR, ERROR, lineno, column, msg, detail, suggestion);
}

void type_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(TYPE_ERROR, ERROR, lineno, column, msg, detail, suggestion);
}

void name_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(NAME_ERROR, ERROR, lineno, column, msg, detail, suggestion);
}

void reference_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(REFERENCE_ERROR, ERROR, lineno, column, msg, detail, suggestion);
}

void declaration_error(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(DECLARATION_ERROR, ERROR, lineno, column, msg, detail, suggestion);
}

// Warning function (non-fatal)
void pebble_warning(int lineno, int column, const char* msg, const char* detail, const char* suggestion) {
    pebble_report_error(SYNTAX_ERROR, WARNING, lineno, column, msg, detail, suggestion);
}