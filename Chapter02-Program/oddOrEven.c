/**
 * @file oddOrEven.c
 * @author Jack Wiegman
 * @date 01-31-2025
 * @assignment Chapter 2 Program
 * @brief Program to check odd or even.
 */

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Check if number is even or odd.
 *
 * @param[in] num Number to check if even or odd
 * @return true if even, false if odd.
 */
bool isEven(int num) { return !(num % 2); }

/**
 * @brief Main function. Adds numbers to array and checks array to see if
 * even/odd works properly for all numbers in array, then prints the result of
 * each comparison.
 *
 * @return 0 to end program.
 */
int main() {
    int num1 = 112;
    int num2 = 105;
    int num3 = 0;
    int num4 = -29;
    int num5 = -28;
    int numArr[] = {num1, num2, num3, num4, num5};

    for (int i = 0; i < 5; i++) {
        if (isEven(numArr[i])) {
            printf("%d is Even\n", numArr[i]);
        } else {
            printf("%d is Odd\n", numArr[i]);
        }
    }
    return 0;
}
