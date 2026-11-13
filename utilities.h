#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

/**
 * Prompt user and read a string input.
 *
 * @param prompt text shown to user
 * @return the string entered by user
 */
string read_string(string prompt);

/**
 * Prompt user and read an integer value.
 *
 * @param prompt text shown to user
 * @return integer input from user
 */
int read_integer(string prompt);

/**
 * Prompt user and read integer within min‑max inclusive bounds.
 *
 * @param prompt text shown to user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return valid integer in range min to max
 */
int read_integer(string prompt, int min, int max);

/**
 * Prompt user to read integer constrained to min‑max range.
 *
 * @param prompt text shown to user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return integer value inside given range
 */
int read_integer_range(string prompt, int min, int max);

/**
 * Prompt user and read boolean input.
 *
 * @param prompt text shown to user
 * @return true or false based on user input
 */
bool read_boolean(string prompt);

/**
 * Prompt user and read a floating‑point double value.
 *
 * @param prompt text shown to user
 * @return double value entered by user
 */
double read_double(string prompt);

/**
 * Prompt user and read double within min‑max inclusive bounds.
 *
 * @param prompt text shown to user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return valid double in range min to max
 */
double read_double_range(string prompt, double min, double max);

/**
 * Swap two integer variables by reference.
 *
 * @param a reference to first integer
 * @param b reference to second integer
 */
void swap(int& a, int& b);

#endif