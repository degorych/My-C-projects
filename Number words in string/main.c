#include <stdio.h>
#include <stdlib.h>

int main(){

    /* --- Constants --- */
    const int START_CAPITAL_LETTER_ASCII = 65;
    const int END_CAPITAL_LETTER_ASCII = 90;
    const int START_LOWERCASE_LETTER_ASCII = 97;
    const int END_LOWERCASE_LETTER_ASCII = 122;
    const int NUMBER_OF_LETTERS_IN_ALPHABET = 52;

    const int MAX_LENS_OF_STRING = 100000;

    /* --- Counters --- */
    int i = 0;
    int k = 0;
    int l = 0;

    /* --- Allocation of memory for user data --- */
    char *userString;
    userString = (char*)malloc(MAX_LENS_OF_STRING * sizeof(char));

    /* --- Allocation memory for letter indexes --- */
    int *foundLettersIndex;
    foundLettersIndex = (int*)malloc(MAX_LENS_OF_STRING * sizeof(int));

    /* --- Make all values of userString to "0" and foundLettersIndex to "-1" --- */
    for (i = 0; i < MAX_LENS_OF_STRING; i++) {
        userString[i] = 0;
        foundLettersIndex[i] = -1;
    }

    printf("Enter string here: ");
    fgets(userString, MAX_LENS_OF_STRING, stdin);

    /* --- Fill foundLettersIndex indexes of letters --- */
    for (i = 0, l = 0; i < MAX_LENS_OF_STRING; i++) {
        if ((userString[i] >= START_CAPITAL_LETTER_ASCII && userString[i] <= END_CAPITAL_LETTER_ASCII)||(userString[i] >= START_LOWERCASE_LETTER_ASCII && userString[i] <= END_LOWERCASE_LETTER_ASCII)) {
            foundLettersIndex[l] = i;
            l++;
        }
    }

    free(userString);

    int numberOfWords = 0;

    /* --- Count number of words --- */
    for (i = 0; i < MAX_LENS_OF_STRING; i++) {
        if (foundLettersIndex[i] != foundLettersIndex[i+1] - 1 && foundLettersIndex[i] != -1) {
            numberOfWords++;
        }
    }

    free(foundLettersIndex);

    printf("\nNumber of word in string: %d", numberOfWords);
    return 0;
}
