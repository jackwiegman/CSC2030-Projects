/**
 * @file SalesTax.c
 *
 * @brief Takes input for the total collections for the inputted month and prints sales tax
 * information, including totals of county and state taxes, the total taxes, and the total sales
 * with taxes taken out. Prints and takes a new argument until user enters sentinel value
 */

#include <stdio.h>

#define MAX_NAME_LENGTH 25      // Max length of a month name
double STATE_SALES_TAX = 0.04;  // Constant for state tax rate
double COUNTY_SALES_TAX = 0.05; // Constant for county tax rate

/**
 * @brief Outputs a dialog that asks user for the total amount collected, then
 * prints sales tax information from county/state, the total tax, and the amount
 * of sales with tax subtracted.
 *
 * @param totalCollections total amount of money collected during the month
 * @return void, prints the desired output to console
 */
void printTaxes(double totalCollections) {

    // Initialize variables of the data presented
    double stateTaxTotal = 0.0;
    double countyTaxTotal = 0.0;
    double totalTax = 0.0;
    double salesTotal = 0.0;

    // Calculations to get all the data from the total collections
    countyTaxTotal = totalCollections * COUNTY_SALES_TAX;
    stateTaxTotal = totalCollections * STATE_SALES_TAX;
    totalTax = countyTaxTotal + stateTaxTotal;
    salesTotal = totalCollections - totalTax;

    // Print all sales tax information
    printf("Total Collections: $%0.2lf\n", totalCollections);
    printf("Sales: $%0.2lf\n", salesTotal);
    printf("County Sales Tax: $%0.2lf\n", countyTaxTotal);
    printf("State Sales Tax: $%0.2lf\n", stateTaxTotal);
    printf("Total Sales Tax Collected: $%0.2lf\n", totalTax);
}

/**
 * @brief main function, gets initial user input then prompts for input to print the tax info of
 * until the user decides to quit.
 */
int main() {

    double totalCollected = 0.0;      // Variable to hold the entered total amount of collections
    char month[MAX_NAME_LENGTH] = ""; // Variable to store name of month
    int sentinel = -1;                // Sentinel value user inputs to stop program

    // Prompt and scan for initial collection amount
    printf("Enter total totalCollections collected: (-1 to quit): ");
    scanf("%lf", &totalCollected);

    // Prompt and scan for initial collection amount if user indicates quitting
    if (totalCollected != sentinel) {
        printf("Enter name of month: ");
        scanf("%s", month);
    }

    // Loop until user indicates they are finished with the sentinel value
    while (totalCollected != sentinel) {

        // Print tax info first
        printTaxes(totalCollected);
        // printf("Month: %s\n", month);

        // Prompt for new total input
        printf("Enter total totalCollections collected: (-1 to quit): ");
        scanf("%lf", &totalCollected);

        // If user doesn't choose to quit, prompt for month
        if (totalCollected != sentinel) {
            printf("Enter name of month: ");
            scanf("%s", month);
        }
    }

    printf("Have a good day!\n");

    return 0;
}
