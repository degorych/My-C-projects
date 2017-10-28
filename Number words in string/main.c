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

    /* --- Letters array --- */
    char letterArray[NUMBER_OF_LETTERS_IN_ALPHABET];

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

    /* --- Create Array of capitals and lowercases letters --- */
    for (i = 0, k = START_CAPITAL_LETTER_ASCII, l = START_LOWERCASE_LETTER_ASCII; i < 52, k <= END_CAPITAL_LETTER_ASCII, l <= END_LOWERCASE_LETTER_ASCII; i++) {
        if (i < 26) {
            letterArray[i] = k;
            k++;
        }
        else {
            letterArray[i] = l;
            l++;
        }
    }

    printf("Enter string here: ");
    fgets(userString, MAX_LENS_OF_STRING, stdin);

    /* --- Fill foundLettersIndex indexes of letters --- */
    for (i = 0, l = 0; i < MAX_LENS_OF_STRING; i++) {
        for (k = 0; k < NUMBER_OF_LETTERS_IN_ALPHABET; k++) {
            if (userString[i] == letterArray[k]) {
                foundLettersIndex[l] = i;
                l++;
            }
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
