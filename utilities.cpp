#include "utilities.h"
#include "splashkit.h"

/**
 * Show prompt and read a line of string input from user.
 *
 * @param prompt text to show the user
 * @return the input string
 */
string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

/**
 * Read and validate an integer from user input.
 * Re‑prompts if input is not a whole number.
 *
 * @param prompt text to show the user
 * @return valid integer value
 */
int read_integer(string prompt)
{
  string line = read_string(prompt);
  while (!is_integer(line))
  {
    write_line("Please enter a whole number.");
    line = read_string(prompt);
  }
  return to_integer(line);
}

/**
 * Read integer within min‑max inclusive range.
 * Re‑prompts when value is out of bounds.
 *
 * @param prompt text to show the user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return integer inside min‑max range
 */
int read_integer(string prompt, int min, int max)
{
  int num = read_integer(prompt);
  while (num < min || num > max)
  {
    write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
    num = read_integer(prompt);
  }
  return num;
}

/**
 * Read integer constrained between min and max.
 * Re‑prompts for out‑of‑range input.
 *
 * @param prompt text to show the user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return valid integer in given range
 */
int read_integer_range(string prompt, int min, int max)
{
  int num = read_integer(prompt);
  while (num < min || num > max)
  {
    write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
    num = read_integer(prompt);
  }
  return num;
}

/**
 * Read boolean, only accepts "true" or "false".
 * Re‑prompts on invalid input.
 *
 * @param prompt text to show the user
 * @return true if input is "true", false otherwise
 */
bool read_boolean(string prompt)
{
    string input;
    write(prompt);
    input = read_line();
    while (input != "true" && input != "false")
    {
        write_line("Please enter true or false");
        write(prompt);
        input = read_line();
    }
    return input == "true";
}

/**
 * Read and validate a double decimal number.
 * Re‑prompts if input is not a valid decimal.
 *
 * @param prompt text to show the user
 * @return valid double value
 */
double read_double(string prompt)
{
    string line = read_string(prompt);
    while (!is_double(line))
    {
        write_line("Please enter a decimal number.");
        line = read_string(prompt);
    }
    return to_double(line);
}

/**
 * Read double value limited to min‑max range.
 * Re‑prompts for values outside bounds.
 *
 * @param prompt text to show the user
 * @param min minimum allowed value
 * @param max maximum allowed value
 * @return double within min‑max inclusive
 */
double read_double_range(string prompt, double min, double max)
{
    double num = read_double(prompt);
    while (num < min || num > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        num = read_double(prompt);
    }
    return num;
}

/**
 * Swap two integer variables using pass‑by‑reference.
 *
 * @param a reference to first integer
 * @param b reference to second integer
 */
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}