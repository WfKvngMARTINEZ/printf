#ifndef MAIN_H
#define MAIN_H

/* Include necessary standard libraries*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Define macros for unused variables and buffer size*/
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Define macros for format flags*/
#define F_MINUS 1
#define F_PLUS  2
#define F_ZERO  4
#define F_HASH  8
#define F_SPACE 16

/* Define macros for size specifiers*/
#define S_LONG  2
#define S_SHORT 1

/**
 * struct FormatSpecifier - A structure to associate format character
 *  with handling functions
 * @format: The format character (e.g., 'd', 's', 'x', etc.)
 * @handler: A function pointer to the associated handling function
 */
struct FormatSpecifier
{
	char format;
	int (*handler)(va_list, char[], int, int, int, int);
}

/* Create a typedef for the struct*/
typedef struct FormatSpecifier FormatSpecifier;

/* Function prototypes*/
int custom_printf(const char *format, ...);
int handle_format_specifier(const char *format, int *index, va_list args,
		 char buffer[], int flags, int width, int precision, int size);

/* Functions for printing characters and strings*/
int print_char(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width,
		 int precision, int size);

/* Functions for printing numbers*/
int print_int(va_list args, char buffer[], int flags,
		 int width, int precision, int size);
int print_binary(va_list args, char buffer[], int flags,
		 int width, int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags,
		int width, int precision, int size);
int print_octal(va_list args, char buffer[], int flags,
		 int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[], int flags,
		 int width, int precision, int size);
int print_hexadecimal_upper(va_list args, char buffer[],
		int flags, int width, int precision, int size);

/* Function to handle other specifiers*/
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);

/* Function to print a string in reverse*/
int print_reverse(va_list args, char buffer[], int flags,
		int width, int precision, int size);

/* Function to print a string in ROT13 encoding*/
int print_rot13_string(va_list args, char buffer[],
		int flags, int width, int precision, int size);

/* Function to handle width and padding*/
int handle_write_char(char c, char buffer[], int flags,
		 int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags,
		 int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width,
		 int precision, int length, char padding, char extra_char);
int write_pointer(char buffer[], int index, int length, int width,
		 int flags, char padding, char extra_char, int padding_start);
int write_unsigned(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size);

/* Utility functions*/
int is_printable(char c);
int append_hex_code(char c, char buffer[], int index);
int is_digit(char c);
long int convert_number_with_size(long int num, int size);
long int convert_unsigned_with_size(unsigned long int num, int size);

#endif /* MAIN_H */

