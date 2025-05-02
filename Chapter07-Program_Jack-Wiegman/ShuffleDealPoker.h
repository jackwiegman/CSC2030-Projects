/**
 * @file ShuffleDealPoker.h
 * @brief Header file for ShuffleDealPoker.c
 */

#ifndef SHUFFLEDEALPOKER_H
#define SHUFFLEDEALPOKER_H

#include <stdbool.h>
#include <stddef.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

const size_t HANDSIZE = 5; /**< Size of poker hand to deal */
const int suitIndex = 0;   /**< The index of suits in each card array */
const int faceIndex = 1;   /**< The index of faces in each card array */

void shuffle(unsigned int wDeck[][FACES]);
void dealHand(unsigned int wDeck[][FACES], unsigned int hand[][2]);
void printHand(unsigned int hand[][2], const char *wSuit[SUITS], const char *wFace[FACES]);
unsigned int findPairs(unsigned int hand[][2]);
unsigned int getStraightFlushValue(unsigned int hand[][2]);
void sortHand(unsigned int hand[][2]);
void printHandContents(unsigned int pairsValue, unsigned int straightFlushValue);

int main(void);

#endif
