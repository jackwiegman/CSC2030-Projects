/**
 * @file ConcatenateStrings.c
 * @brief Concatenate two strings provided by a user.
 *
 * Prompt user at the terminal to enter two strings, entered one at a time. Then print the words,
 * both before and after concatenating them, as well as the length of the concatenated word.
 */

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH_MAX 100 /**< Max size of a single user inputted string. */

/**
 * @fn void getValidInput(char *inputWordString, size_t maxLength)
 * @brief Get input and validate the data, putting valid data into provided string.
 *
 * @details
 * Prompt user to input a string of a max length: \ref maxLength. Then take the stream into \ref
 * inputWordString from stdin, only taking in the \ref STRING_LENGTH_MAX number of characters.
 * Check both if the string is greater than 0 characters with a newline. Also that the string
 * terminates with a newline before the end of the fgets() string so that we know it is within \ref
 * STRING_LENGTH_MAX. If it is, break the loop as we have a valid string being pointed to. If not
 * check if the string is too long or too short.'\n'If it's not greater than 1 newline character,
 * give error message for that.'\n'If the string isn't too short, loop through stdin until either a
 * '\\n' or EOF character. This will clear stdin and ready it for new input. Also give the message
 * that the string is too long. After the errors are printed and the stream is clear, the loop runs
 * again, prompting until it recieves valid input.
 *
 * @param inputWordString Pointer to an array of characters to hold the input string.
 * @param maxLength Max number of characters allowed in string array.
 */
void getValidInput(char *inputWordString, size_t maxLength) {

    while (1) {
        printf("Please enter a string of max length %d: ",
               STRING_LENGTH_MAX); /* Prompt user input. */

        fgets(inputWordString, maxLength,
              stdin); /* Takes in string from stdin to inputWordString. */

        size_t strLength = strlen(inputWordString); /* Length of the input string. */

        if (inputWordString[0] != '\n' && inputWordString[strLength - 1] == '\n') {
            /* Change out newline for null byte to make a string */
            inputWordString[strLength - 1] = '\0';

            /* String is validated and we can exit */
            break;
        } else { /* Input too long, input not valid. */

            int temp;

            /*
             * Takes a character from stdin until there are no more characters and the stream is
             * cleared.
             */
            if (strLength > 1) {
                while ((temp = getchar()) != '\n' && temp != EOF) {
                };
            }

            /* Print error message */
            if (strLength > 1) {
                printf("Input too long. Max string length is %lu characters.\n", maxLength);
            } else {
                printf("Must input a string. Max string length is %lu characters.\n", maxLength);
            }
        }
    }
}

/**
 * @fn int main()
 * @brief Run main instructions and tests for concatenating strings.
 *
 * @details
 * Create two input strings that will be passed to the validate function to be filled with user
 * input one at a time. These arrays have a max size of \ref STRING_LENGTH_MAX and can hold up to
 * that many characters. The array pointers are both passed to the function to fill them with valid
 * input. The program will print the original string info, then go on to concatenate the strings
 * into the \ref resultString. This is done by copying the first string into the result string, then
 * concatenating the second string onto the result string. The result string is initialized with
 * twice the size of the input strings so that it has the capacity to fit both. The information for
 * the concatenated string is then printed.
 *
 */
int main() {

    char inputString1[STRING_LENGTH_MAX]; /**< Character array of first user inputted string. */
    char inputString2[STRING_LENGTH_MAX]; /**< Character array of second user inputted string. */
    char resultString[STRING_LENGTH_MAX * 2]; /**< Character array of input strings concatenated. */

    printf("Please enter two strings, each with a max length of %d characters.\n",
           STRING_LENGTH_MAX);

    /* Call function to fill arrays with valid strings to be used to concatenate. */
    getValidInput(inputString1, STRING_LENGTH_MAX);
    getValidInput(inputString2, STRING_LENGTH_MAX);

    /* Print out each original string and it's length. */
    printf("String one: %s\nLength: %lu\nString two: %s\nLength: %lu\n", inputString1,
           strlen(inputString1), inputString2, strlen(inputString2));

    strcpy(resultString, inputString1);
    strcat(resultString, inputString2);

    printf("Concatenated string: %s\nLength: %lu\n", resultString, strlen(resultString));

    return 0;
}
