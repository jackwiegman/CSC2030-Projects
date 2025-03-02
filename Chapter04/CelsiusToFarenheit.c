/**
 * @author Jack Wiegman
 * @file CelsiusToFarenheit.c
 * @brief Takes input for a temperature value in celsius and then return value converted to
 * farenheit. Then prints a table of conversions from 30-50 degrees C.
 *
 */

#include <stdio.h>

/**
 * @brief Converts value from celsius and returns the float value in farenheit
 *
 * @param degC a float representing a temp in celsius
 * @return float value of the parater value in farenheit
 */
float celsiusToFarenheit(float degC) {
    float inputDegC = degC;
    float inputDegF = (degC * 9) / 5;
    inputDegF += 32;
    return inputDegF;
}

/**
 * @brief Prints header of table and then table of values in celsius converted to farenheit.
 *
 * @param degC value in celsius to convert to farenheiht
 */
void printTable(float degC) {
    // printf("Celsius");
    // int tableLenth = 10;
    // int deg = (int)round(inputDegC);
    // for (int i = deg - tableLength; i >= deg + tableLength; i++) {
    printf("C   |   F\n");
    printf("=========\n");
    for (int i = 30; i <= 50; i++) {
        float degF = celsiusToFarenheit(i);
        printf("%d  |   %#0.2f\n", i, degF);
    }
}

/**
 *
 * @return
 */
int main() {
    float temp = 0;

    printf("Enter temperature in Celcius: ");
    scanf("%f", &temp);
    printf("%#0.2f in celsius is %#0.2f degrees farenheit.\n", temp, celsiusToFarenheit(temp));
    printTable(temp);
    return 0;
}
