/**
 * @file ShuffleDealPoker.c
 * @brief Card shuffling and dealing
 */

#include "ShuffleDealPoker.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const size_t numHands = 7;
/* initialize suit array */
const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

/* initialize face array */
const char *face[FACES] = {"Ace",   "Deuce", "Three", "Four", "Five",  "Six", "Seven",
                           "Eight", "Nine",  "Ten",   "Jack", "Queen", "King"};
int main(void) {
    /* initialize deck array */
    unsigned int deck[SUITS][FACES] = {0};

    unsigned int hand[HANDSIZE][2];

    srand(time(NULL)); /* seed random number generator */
    shuffle(deck);     /* shuffle the deck */

    dealHand(deck, hand);

    printHand(hand, suit, face);

    // unsigned int sortedHand[HANDSIZE][2];
    sortHand(hand);
    printHand(hand, suit, face);

    unsigned int pairs = 0;
    pairs = findPairs(hand);
    unsigned int straightFlushVal = 0;
    straightFlushVal = getStraightFlushValue(hand);

    printHandContents(pairs, straightFlushVal);
    return 0;
}

/**
 * @fn void shuffle(unsigned int wDeck[][FACES])
 * @brief Shuffle cards in deck to random locations
 *
 * @param wDeck a 2d array representing the cards in the deck
 * @param FACES number of faces in the deck
 */
void shuffle(unsigned int wDeck[][FACES]) {
    /* For each of the cards, choose slot of deck randomly */
    for (size_t card = 1; card <= CARDS; card++) {
        size_t row;    /* row number */
        size_t column; /* column number */
        /* Choose new random location until unoccupied slot found */
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);

        /* place card number in chosen slot of deck */
        wDeck[row][column] = card;
    }
}

/**
 * @fn void dealHand(unsigned int wDeck[][FACES], unsigned int hand[][2])
 * @brief Deal the top \ref HANDSIZE cards and put them in hand deck.
 *
 * Loops through deck finding card 1 through \p HANDSIZE then assigns the row and column
 * (representing suit and face) that the card was found in to the next place in the hand array,
 * filling the array with a new hand of \p HANDSIZE cards.
 *
 * @param wDeck a 2d unsigned integer array of cards in the deck
 * @param FACES a constant integer representing the number of faces in the deck.
 * @param hand a 2d integer array of size [\ref HANDSIZE][2] representing the cards in the hand.
 */
void dealHand(unsigned int wDeck[][FACES], unsigned int hand[][2]) {

    /* deal each of the cards */
    for (size_t card = 1; card <= HANDSIZE; card++) {
        /* loop through rows of wDeck */
        for (size_t row = 0; row < SUITS; row++) {
            /* loop through columns of wDeck for current row */
            for (size_t column = 0; column < FACES; column++) {
                /* if slot contains current card, display card */
                if (wDeck[row][column] == card) {
                    /* printf("%5s of %-8s%c", wFace[column], wSuit[row],
                            card % 2 == 0 ? '\n' : '\t');  2-column format */

                    /* Add row/column to a size 2 array within hand array */
                    hand[card - 1][0] = row;
                    hand[card - 1][1] = column;
                }
            }
        }
    }
}

/**
 * @fn void printHand(unsigned int hand[][2], const char *wSuit[SUITS], const char *wFace[FACES])
 * @brief Loops through hand to print each card to console.
 * Loops through each "card", represented as an index of the \ref hand array. Each card is an array
 * of two integers representing a corresponding index in the \ref wSuit and \ref wFace arrays. These
 * indexes contain the name and face of the card.
 *
 * @param hand 2d array containing cards in the hand.
 * @param wSuit array containing suit values at corresponding locations to hand array values.
 * @param SUITS constant int, number of suits in deck (4).
 * @param wFace array containing face values at corresponding locations to hand array values.
 * @param FACES constant int, number of faces in deck (13).
 */
void printHand(unsigned int hand[][2], const char *wSuit[SUITS], const char *wFace[FACES]) {

    printf("5 card hand:\n");

    for (int i = 0; i < HANDSIZE; i++) {
        printf("%5s of %-8s\n", wFace[hand[i][1]], wSuit[hand[i][0]]);
    }
}

/**
 * @brief Find the number of same face cards (pairs)
 *
 * @param hand array of cards.
 * @return Integer based on value of hand where pair=1, 2 pair=2, 3 of a kind=4, & 4 of a kind=8
 */
unsigned int findPairs(unsigned int hand[][2]) {

    unsigned handValue = 0;
    const unsigned int pairVal = 1;
    const unsigned int twoPairVal = 2;
    const unsigned int threeOfAKindVal = 4;
    const unsigned int fourOfAKindVal = 8;

    unsigned int cardVal = 0;  /* Value to represent the current card being compared */
    unsigned int compCard = 0; /* Face value of temporary card compared to */
    int sameFaces = 0;         /* Track how many of the same face there are in deck */
    int firstPair = -1;        /* Face value of first set of cards to ensure no duplicates */

    /* Loop through hand */
    for (int i = 0; i < HANDSIZE; i++) {
        /* Setting card values */
        cardVal = hand[i][faceIndex];

        /* Loop through hand to compare, unless its the same card index */
        for (int j = 0; j < HANDSIZE && j != i; j++) {
            /* Ensure not from a pair already accounted for */
            if (firstPair == cardVal) {
                continue;
            }

            compCard = hand[j][faceIndex];

            if (compCard == cardVal) {
                sameFaces++;
            }
            printf("Same Faces: %d\n", sameFaces);
        }
        /* Add to hand value to value of the pairs to this card & mark that face was counted. */
        switch (sameFaces) {
        /* Card has one match, so is a pair */
        case 1:
            handValue += pairVal;
            firstPair = cardVal;
            break;
        /* Card has two matches, three of a kind */
        case 2:
            handValue += threeOfAKindVal;
            firstPair = cardVal;
            break;
        /* Card has 3 matches, four of a kind */
        case 3:
            handValue += fourOfAKindVal;
            firstPair = cardVal;
            break;
        }
        sameFaces = 0;
    }

    return handValue;
}

/**
 * @fn unsigned int getStraightFlushValue(unsigned int hand[][2])
 * @brief Searches hand for straight/royal straights & flushes. Returns hand value.
 *
 * @param hand array of cards in the current hand, order irrelevant.
 * @return Value is the sum of possible hand combinations where straight=1, flush=2, & royal=4.
 */
unsigned int getStraightFlushValue(unsigned int hand[][2]) {

    unsigned int handVal = 0;
    /* Total value of hand to be returned, with the following values of each hand possibility */
    const unsigned int straightVal = 1; /* Value to add if hand is a straight */
    const unsigned int flushVal = 2;    /* Value to add if hand is a flush */
    const unsigned int royalVal = 4;    /*Value to add if hand is a royal straight (Ten-Ace) */

    unsigned int sortedHand[HANDSIZE][2]; /* Array to place the sorted by face hand */

    /* Add cards from original hand array to sorted hand array */
    for (int i = 0; i < HANDSIZE; i++) {
        for (int j = 0; j < 2; j++) {
            sortedHand[i][j] = hand[i][j];
        }
    }
    sortHand(sortedHand);                                /* Sort the sortedHand array */
    unsigned int handSuitInt = sortedHand[0][faceIndex]; /* Value of suit to compare for a flush */
    /* variables to keep state */
    _Bool handIsStraight = true;
    _Bool handIsFlush = true;
    _Bool handIsRoyal = false;

    /* Loop through hand */
    for (int i = 1; i < HANDSIZE; i++) {

        /* Check for a straight by making sure each index is 1 greater than the last */
        if (sortedHand[i][faceIndex] - sortedHand[i - 1][faceIndex] != 1) {
            handIsStraight = false;

            if ((i == 1) && (sortedHand[i][faceIndex] == 9 && sortedHand[i - 1][faceIndex] == 0)) {
                /* If first two indicies are ace and 10, it has to be a straight if the other cards
                 * are a straight, so we can keep handIsStraight true and continue. */
                handIsStraight = true;

                /* Also set royal to true since this is the only possibility for it */
                handIsRoyal = true;
            }
        }

        /* Check flush status and turn false if not matching */
        if (sortedHand[i][suitIndex] != handSuitInt) {
            handIsFlush = false;
        }
    }

    /* Check each variable for hand contents and add value if hand contained it */
    if (handIsStraight) {
        handVal += straightVal;
    }
    if (handIsFlush) {
        handVal += flushVal;
    }
    if (handIsRoyal) {
        handVal += royalVal;
    }

    return handVal;
}

/**
 * @fn void sortHand(unsigned int hand[][2])
 * @brief Sort the provided array by face value.
 * Insertion sort implementation.
 *
 * @param hand array containing card values to be sorted.
 */
void sortHand(unsigned int hand[][2]) {

    unsigned int holdFace; /* temp variable to store values in */

    unsigned int holdSuit; /* temp variable to store values in */

    for (int i = 0; i < HANDSIZE; i++) {
        for (int j = i; j > 0; j--) {
            holdFace = hand[j][faceIndex]; /* store variable */
            holdSuit = hand[j][suitIndex];

            if (hand[j - 1][faceIndex] > hand[j][faceIndex]) {
                hand[j][suitIndex] = hand[j - 1][suitIndex];
                hand[j][faceIndex] = hand[j - 1][faceIndex];
                hand[j - 1][suitIndex] = holdSuit;
                hand[j - 1][faceIndex] = holdFace;
            }
        }
    }
}

/**
 * @brief Print what kind of poker hands the hand contains;
 * Take in straight/flush and pair values and print output based on value of hand.
 *
 * @param pairsValue Octal value of similar face cards.
 * @param straightFlushValue Octal value of straights and flushes in the hand.
 */
void printHandContents(unsigned int pairsValue, unsigned int straightFlushValue) {
    _Bool pairsFound = true;
    _Bool straightFlushFound = true;
    switch (pairsValue) {
    case 0:
        pairsFound = false;
        break;
    /* One pair found */
    case 1:
        printf("Hand contains one pair!");
        printf("\n");
        break;
    case 2:
        printf("Hand contains two pair!");
        printf("\n");
        break;
    case 4:
        printf("Hand contains three of a kind!");
        printf("\n");
        break;
    case 5:
        printf("Hand contains a full house!");
        printf("\n");
        break;
    case 8:
        printf("Hand contains a four of a kind!");
        printf("\n");
        break;
    }

    switch (straightFlushValue) {
    case 0:
        straightFlushFound = false;
        break;
    case 1:
        printf("Hand contains a straight!");
        printf("\n");
        break;
    case 2:
        printf("Hand contains a flush!");
        printf("\n");
        break;
    case 3:
        printf("Hand contains a straight flush!");
        printf("\n");
        break;
    case 4:
        printf("Hand contains a royal straight!");
        printf("\n");
        break;
    case 6:
        printf("Hand contains a royal flush!");
        printf("\n");
        break;
    }
    printf("Pairs Val: %d\n", pairsValue);
    printf("Straigh Val: %d\n", straightFlushValue);

    if (!(pairsFound || straightFlushFound)) {
        printf("Hand does not contain anything of value.\n");
    }
}
