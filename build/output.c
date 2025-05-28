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

int fn() {
    int a = 10;
    printf("%d\n", a);
    return 0;
}
int main() {
    char* num = malloc(256);
    printf("%s", "Enter a number");
    fgets(num, 256, stdin);
    // Remove newline if present
    int num_len = strlen(num);
    if (num_len > 0 && num[num_len-1] == '\n') num[num_len-1] = '\0';
    int n = to_int(num);
    for (int __i = 0; __i < n; __i++) {
    printf("%s\n", "Hello");
    }
    fn();    int a = 5;
    double b = 3.4;
    char* c = "hello";
    char d = 'a';
    int e = 1;
    printf("%d\n", a);
    printf("%.2f\n", b);
    printf("%s\n", c);
    printf("%c\n", d);
    printf("%d\n", e);
    return 0;
}
