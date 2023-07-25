#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
int _putchar(char c);
void process_format_specifier(va_list arg, char specifier, int *printCounter);
int _printf(const char *format, ...);
int print_string(const char *str);
int print_number(int n);
int  print_binary(unsigned int num);

#endif
