#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
// Built-in conversion functions
int to_int(char* str);
double to_float(char* str);
int to_bool(char* str);
char to_char(char* str);

// Functions for display (with newline)
void print(int p) {
    printf("%d\n", p);
}

void print_string(char* p) {
    printf("%s\n", p);
}

void print_float(double p) {
    printf("%.2f\n", p);
}

void print_char(char p) {
    printf("%c\n", p);
}

// Functions for print (without newline)
void print_int_no_nl(int p) {
    printf("%d", p);
}

void print_string_no_nl(char* p) {
    printf("%s", p);
}

void print_float_no_nl(double p) {
    printf("%.2f", p);
}

void print_char_no_nl(char p) {
    printf("%c", p);
}

int fun(int x) {
    {
        int i = 0;
        for (; i < x; i = (i + 1)) {
    printf("%d\n", i);
        }
    }
    return 0;
}
int main() {
    fun(5);    return 0;
}
