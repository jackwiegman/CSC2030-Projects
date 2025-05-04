/**
 * @mainpage
 * @author Jack Wiegman
 * @file FahrenheitToCelsius.c
 * @brief Program that converts Fahrenheit temperature to Celsius with 3 digits of percision.
 *
 * ## Problem Statement
 *
 * ### 9.10 Temperature Conversions
 * Write a program that converts integer Fahrenheit temperatures from 0 to 212 degrees to
 * floating-point Celsius temperatures with 3 digits of precision. Perform the calculation using the
 * formula
 * @code
 * celsius = 5.0 / 9.0 * (fahrenheit - 32);
 * @endcode
 * The output should be printed in two right-justified columns of 10 characters each, and the
 * Celsius temperatures should be preceded by a sign for both positive and negative values.
 *
 */

#include <stdio.h>

/**
 * @fn float farToCel(int fTemp)
 * @brief Calculate a float value for tempreature in celsius from the fahrenheit temp integer.
 *
 * @details
 * Calculate the new temperature with the following formula.
 * @code
 * celsius = 5.0 / 9.0 * (fahrenheit - 32)
 * @endcode
 * and return the value
 *
 * @param fTemp Integer temperature in fahrenheit.
 * @return Float value of temperature in celsius.
 */
float farToCel(int fTemp) {
    /* Return fTemp as float in celsius. */
    return (5.0 / 9.0) * (fTemp - 32);
}

/**
 * @fn int main()
 *
 * @brief Prints a column of Fahrenheit temperatures and their corresponding Celsius values.
 *
 * @details
 * - Declares an integer representing degrees Fahrenheit (`fTemp`) and a float for degrees Celsius
 * (`cTemp`).
 * - Formats output into two right-justified columns, each 10 characters wide.
 * - Displays Celsius values with a leading sign (`+` or `-`) and 3 digits of precision.
 * - Prints column headers using the same formatting.
 * - Iterates through Fahrenheit values from 0 to 212.
 *   - For each value, converts it to Celsius using the formula: `(5.0 / 9.0) * (F - 32)`.
 *   - Prints both values according to the specified format.
 * - Exits after printing the full temperature conversion table.
 */
int main() {
    int fTemp;
    float cTemp;

    printf("%10s%10s\n", "Fahrenheit", "Celsius");

    for (fTemp = 0; fTemp <= 212; fTemp++) {
        cTemp = farToCel(fTemp);

        printf("%10d%+10.3f\n", fTemp, cTemp);
    }
    return 1;
}
