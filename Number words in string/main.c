#include <stdio.h>
#include <stdlib.h>

void fillArray (char* charFillAr, int* intFillAr, int charNum, int intNum, int lens) {
    int i = 0;
    for (i = 0; i < lens; i++) {
        charFillAr[i] = charNum;
        intFillAr[i] = intNum;
    }
}

void fillIndexArray (char *userArr, int *indexArr, int lens) {
    int i, l = 0;

    const int START_CAPITAL_LETTER_ASCII = 65;
    const int END_CAPITAL_LETTER_ASCII = 90;
    const int START_LOWERCASE_LETTER_ASCII = 97;
    const int END_LOWERCASE_LETTER_ASCII = 122;

    for (i = 0, l = 0; i < lens; i++) {
        if ((userArr[i] >= START_CAPITAL_LETTER_ASCII && userArr[i] <= END_CAPITAL_LETTER_ASCII)||(userArr[i] >= START_LOWERCASE_LETTER_ASCII && userArr[i] <= END_LOWERCASE_LETTER_ASCII)) {
            indexArr[l] = i;
            l++;
        }
    }
    free(userArr);
}

int numWord(int *indexArr, int lens, int defaultValue) {
    int numberOfWords = 0;
    int i = 0;

    for (i = 0; i < lens; i++) {
        if (indexArr[i] != indexArr[i+1] - 1 && indexArr[i] != defaultValue) {
            numberOfWords++;
        }
    }
    free(indexArr);
    return numberOfWords;
}

int main(){

    const int MAX_LENS_OF_STRING = 1000000;
    const int DEFAULT_USER_ARRAY_VALUE = 0;
    const int DEFAULT_INDEX_ARRAY_VALUE = -1;

    /* --- Allocation memory for user data --- */
    char *userString;
    userString = (char*)malloc(MAX_LENS_OF_STRING * sizeof(char));

    /* --- Allocation memory for letter indexes --- */
    int *foundLettersIndex;
    foundLettersIndex = (int*)malloc(MAX_LENS_OF_STRING * sizeof(int));

    /* --- Make all values of userString to "0" and foundLettersIndex to "-1" --- */
    fillArray (userString, foundLettersIndex, DEFAULT_USER_ARRAY_VALUE, DEFAULT_INDEX_ARRAY_VALUE, MAX_LENS_OF_STRING);

    printf("Enter string here: ");
    fgets(userString, MAX_LENS_OF_STRING, stdin);

    /* --- Fill foundLettersIndex indexes of letters from users array --- */
    fillIndexArray (userString, foundLettersIndex, MAX_LENS_OF_STRING);

    /* --- Count number of words --- */
    int numberOfWords = numWord(foundLettersIndex, MAX_LENS_OF_STRING, DEFAULT_INDEX_ARRAY_VALUE);

    printf("\nNumber of word in string: %d", numberOfWords);
    return 0;
}
