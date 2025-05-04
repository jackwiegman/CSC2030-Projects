/**
 * @file PackingCharacters.c
 * @brief Pack 4 1 byte characters into a 4 byte unsigned integer and print result.
 *
 * @author Jack Wiegman
 *
 *
 * ## Problem Statement
 *
 * 10.12 (Packing Characters into an Integer)
 * The left-shift operator can be used to pack four character values into a four-byte unsigned int
 * variable. Write a program that inputs four characters from the keyboard and passes them to
 * function packCharacters. To pack four characters into an unsigned int variable, assign the first
 * character to the unsigned int variable, shift the unsigned int variable left by 8 bit positions
 * and combine the unsigned variable with the second character using the bitwise inclusive OR
 * operator. Repeat this process for the third and fourth characters. The program should output the
 * characters in their bit format before and after they’re packed into the unsigned int to prove
 * that the characters are in fact packed correctly in the unsigned int variable.
 */

#include <stdio.h>

#define CHARSIZEBITS 8 /**< Size of character values on the present system */

#define INTSIZEBITS 32 /**< Size of unsigned integer values on the present system */

/**
 * @brief Print a character as it's binary value.
 *
 * @details
 *
 * - Set a *display mask*, or a control value that we can compare bits to.
 *   - Set the value to 1 ( 00000001 ) then shift the value by 7 bits, one less than the size of
 *   a character. The new display mask will be one byte: 10000000
 * - Loop through the bits in the char from left to right printing one out, then bit shifting the
 *   character to the left so that the next bit is being compared to the position of the display
 *   mask
 * - The comparison itself will be a bitwise AND between the bit shifted character and the display
 *   mask, printing '1' if both values are 1, otherwise print `0`. This will display the approptiate
 *   value of the character bits.
 *
 * @param charToDisplay Single character to display.
 */
void printCharInBits(unsigned char charToDisplay) {
    unsigned char displayMask = 1 << (CHARSIZEBITS - 1);

    for (unsigned int i = 0; i < CHARSIZEBITS; i++) {
        putchar(charToDisplay & displayMask ? '1' : '0');
        charToDisplay <<= 1; /* Shift left */
    }
    putchar('\n');
}

/**
 * @brief Print the given integer in its bit format.
 *
 * @details
 * > Same algorithm as @ref printCharInBits() except using the size of an unsigned int: 32.
 *
 * - Comparing int value to the display mask set to 1 then bitshifted 31 bits left.
 * - Print out a space every 8 bits for readability.
 *
 * @param intToDisplay unsigned integer to display 4 byte bit value.
 */
void printIntInBits(unsigned int intToDisplay) {
    unsigned int displayMask = 1 << (INTSIZEBITS - 1);

    for (unsigned int i = 1; i <= INTSIZEBITS; i++) {
        putchar(intToDisplay & displayMask ? '1' : '0');
        intToDisplay <<= 1; /* Shift left */

        if (i % 8 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

/**
 * @brief Pack 4 one byte character values into 1 four byte unsigned integer.
 *
 * @details
 * - Initialize a new unsigned int variable to 0.
 * - Assign the first character to the int variable, this will fill the rightmost 8 bits.
 * - Now shift the unsigned integer 8 bits to the left, and compare via inclusive or to the next
 *   character, setting the next 8 bits of the integer.
 * - Repeat the process of bit shifting and comparing for the third and fourth characters.
 * - The unsigned integer is now packed and ready to be returned.
 *
 * @param c1 First character to pack.
 * @param c2 Second character to pack.
 * @param c3 Third character to pack.
 * @param c4 Fourth character to pack.
 * @return unsigned int with the characters bit values packed in from
 */
unsigned int packCharsToInt(char c1, char c2, char c3, char c4) {
    unsigned int packedInt = 0;        /** 00000000 00000000 00000000 00000000 */
    packedInt = c1;                    /** 00000000 00000000 00000000   [c1]   */
    packedInt = (packedInt << 8) | c2; /** 00000000 00000000   [c1]     [c2]   */
    packedInt = (packedInt << 8) | c3; /** 00000000   [c1]     [c2]     [c3]   */
    packedInt = (packedInt << 8) | c4; /**   [c1]     [c2]     [c3]     [c4]   */
    return packedInt;
}

/**
 * @brief Get 4 character input from user, print bit values then pack into unsigned int and print
 * the bit values of that as well.
 *
 * @details
 * - Get 4 characters from user via standard input.
 * - Print each character in text and its bit value by calling @ref printCharInBits().
 * - Send characters to be packaged into an integer and then print the integer's bit values.
 */
int main() {
    char c1, c2, c3, c4;

    puts("Enter 4 characters (without spaces), followed by [ENTER]: ");
    scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

    puts("Character bits:");

    printf("%c: ", c1);
    printCharInBits(c1);

    printf("%c: ", c2);
    printCharInBits(c2);

    printf("%c: ", c3);
    printCharInBits(c3);

    printf("%c: ", c4);
    printCharInBits(c4);

    unsigned int packagedChars = packCharsToInt(c1, c2, c3, c4);
    puts("Characters packed into an unsigned int--in bits:");
    printIntInBits(packagedChars);
    printf("%-9c%-9c%-9c%-9c\n", c1, c2, c3, c4);
    printf("Integer value: %u\n", packagedChars);

    return 0;
}
