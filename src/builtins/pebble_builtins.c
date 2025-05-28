#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Built-in functions for Pebble language

// Convert string to integer
int to_int(char* str) {
    // Skip leading whitespace
    while (isspace(*str)) str++;
    
    // Check if the string is empty
    if (*str == '\0') return 0;
    
    // Convert to integer
    return atoi(str);
}

// Convert string to float
double to_float(char* str) {
    // Skip leading whitespace
    while (isspace(*str)) str++;
    
    // Check if the string is empty
    if (*str == '\0') return 0.0;
    
    // Convert to float
    return atof(str);
}

// Convert string to boolean (1 for "true", 0 for anything else)
int to_bool(char* str) {
    // Skip leading whitespace
    while (isspace(*str)) str++;
    
    // Check if the string is "true" (case insensitive)
    if (strcasecmp(str, "true") == 0 || 
        strcasecmp(str, "yes") == 0 || 
        strcasecmp(str, "1") == 0) {
        return 1;
    }
    
    return 0;
}

// Get first character of a string
char to_char(char* str) {
    // Skip leading whitespace
    while (isspace(*str)) str++;
    
    // Return first character or null if empty
    return *str ? *str : '\0';
}
