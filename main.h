#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct FormatHandler - Struct for format handlers
 *
 * @formatSpecifier: The format specifier character.
 * @Func: The associated function pointer for handling the format.
 */
struct FormatHandler {
    char formatSpecifier;
    int (*Func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct FormatHandler FormatHandler_t - Typedef for FormatHandler
 */
typedef struct FormatHandler FormatHandler_t;

int _printf(const char *format, ...);
int handle_print(const char *formatSpecifier, int *index,
    va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size);

int print_hexa(va_list types, char mapTo[],
    char buffer[], int flags, char flagChar, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list types);
int get_precision(const char *format, int *index, va_list types);
int get_size(const char *format, int *index);

/* Function to print a string in reverse */
int print_reverse(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
    int flags, int width, int precision, int size);
int write_number(int isPositive, int index, char buffer[],
    int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
    int length, char paddingChar, char extraChar);
int write_pointer(char buffer[], int index, int length,
    int width, int flags, char paddingChar, char extraChar, int paddingStart);

int write_unsgnd(int isNegative, int index, char buffer[],
    int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char c);
int append_hexa_code(char c, char hexa[], int index);
int is_digit(char c);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
