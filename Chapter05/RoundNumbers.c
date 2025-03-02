/**
 * @file RoundNumbers.c
 * @brief Prints a user inputted number rounded to the tenths, hundreths, thousandths, and nearest
 * integer.
 *
 * @usage Run program from terminal by calling the executable. Then enter numbers you would like to
 * round. When you are finished, enter -1 to exit the program.
 *
 */

#include <math.h>
#include <stdio.h>

/**
 * @brief rounds number to an integer
 *
 * @param num double to be rounded
 * @return integer representing the rounded number
 */
int roundToInteger(double num) {
    int rounded = floor(num + 0.5);
    return rounded;
}

/**
 * @brief rounds number to nearest tenth
 *
 * @param num double to be rounded
 * @return rounded double
 */
double roundToTenths(double num) {
    double rounded = floor(num * 10 + 0.5) / 10;
    return rounded;
}

/**
 * @brief rounds number to nearest hundreth
 *
 * @param num double to be rounded
 * @return rounded double
 */
double roundToHundreths(double num) {
    double rounded = (floor(num * 100 + 0.5)) / 100;
    return rounded;
}

/**
 * @brief rounds number to nearest thousandth
 *
 * @param num double to be rounded
 * @return rounded double
 */
double roundToThousandths(double num) {
    double rounded = floor(num * 1000 + 0.5) / 1000;
    return rounded;
}

/**
 * @brief Runs main loop rounding user inputted numbers. Prompts user then takes their input. If it
 * is not the sentinel value (-1), supply the number to each rounding function and print each
 * output. Check again and run until user enters sentinel value
 *
 */
int main() {

    double userNum;

    printf("Please enter a number to round (enter -1 to quit): ");
    scanf("%lf", &userNum);

    while (userNum != -1) {

        int roundedToInt = roundToInteger(userNum);
        double roundedToTenths = roundToTenths(userNum);
        double roundedToHundreths = roundToHundreths(userNum);
        double roundedToThousandths = roundToThousandths(userNum);

        printf("Here is your number, %lf, rounded to...\n", userNum);
        printf("An integer: %d\n", roundedToInt);
        printf("The tenths place: %.1lf\n", roundedToTenths);
        printf("The hundreths place: %.2lf\n", roundedToHundreths);
        printf("The thousandths place: %.3lf\n", roundedToThousandths);

        printf("Please enter a number to round (enter -1 to quit): ");

        scanf("%lf", &userNum);
    }

    printf("Thank you, come again!\n");

    return 0;
}
