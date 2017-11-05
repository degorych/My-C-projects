#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void fillArray (char *pointer, int lens, int value) {
    int i = 0;
    for (i = 0; i < lens; i++) {
        pointer[i] = value;
    }
}

void fillMulDimArray (char **pointer, int lensRow, int lensCol, int value) {
    int i, k = 0;
    for (i = 0; i < lensRow; i++) {
        for (k = 0; k < lensCol; k++) {
            pointer[i][k] = value;
        }
    }
}

char **multidimensionalArray (int row, int column) {
    char** array = (char**)malloc (row * sizeof(char*));
    int i = 0;
    for (i = 0; i < row; i++ ) {
        array[i] = malloc (column * sizeof(char));
    }
    return array;
}

/* --- Constants --- */
const int MAX_LENS_USERSTRING = 100000;
const int NUM_CHAR_INTO_ALPHABET = 27;

const int START_CAPITAL_LETTER_ASCII = 65;
const int START_LOWERCASE_LETTER_ASCII = 97;
const int END_LOWERCASE_LETTER_ASCII = 122;

const int NUMBEROFCHARREPETITIONS_SECOND_INDEX = 2;
const int LETTERSARRAY_SECOND_INDEX = 2;
const int LETTER_INDEX = 0;
const int REPETITION_INDEX = 1;

void capitalAndLowercaseLetterArray (int column, char (*letterArray)[column], int row) {
    int i, k, l, m = 0;

    for (i = 0, k = 0, l = START_CAPITAL_LETTER_ASCII, m = START_LOWERCASE_LETTER_ASCII; i < row; i++, l++, m++) {
        letterArray[i][k] = l;
        letterArray[i][k+1] = m;
    }
}

void conversionCapToLow (char* userArray, int capAndLowLetterArSecondIndex, char (*capToLow)[capAndLowLetterArSecondIndex], int lensUserArray, int capAndLowLetterArFirstIndex) {
    int i, k, l = 0;
    for (i = 0; i < lensUserArray; i++) {
        for (k = 0; k < capAndLowLetterArFirstIndex; k++) {
            if (userArray[i] == capToLow[k][l]) {
                userArray[i] = capToLow[k][l+1];
            }
        }
    }
}

void calcRepetition (char* userString, char** repetition, int lens) {
    int i, k = 0;

    for (i = 0; i < lens; i++) {
        if (userString[i] >= START_LOWERCASE_LETTER_ASCII && userString[i] <= END_LOWERCASE_LETTER_ASCII) {
            for (k = 0; k < lens; k++) {
                if (userString[i] == repetition[k][LETTER_INDEX]) {
                    repetition[k][REPETITION_INDEX] = repetition[k][REPETITION_INDEX] + 1;
                    break;
                }
                else if (userString[i] != repetition[k][LETTER_INDEX] && repetition[k][LETTER_INDEX] == 0) {
                    repetition[k][LETTER_INDEX] = userString[i];
                    repetition[k][REPETITION_INDEX] = 1;
                    break;
                }
            }
        }
    }
    free(userString);
}

void sortLetters (char** sortArray, int lens) {
    int i, k = 0;

    char smallSwapVariableChar = '0';
    char bigSwapVariableChar = '0';
    char smallSwapVariableNum = '0';
    char bigSwapVariableNum = '0';

    for (k = 0; k < lens; k++) {
        for (i = 0; i < lens; i++) {
            if (sortArray[i][REPETITION_INDEX] < sortArray[i+1][REPETITION_INDEX]) {
                smallSwapVariableChar = sortArray[i][LETTER_INDEX];
                bigSwapVariableChar = sortArray[i+1][LETTER_INDEX];
                smallSwapVariableNum = sortArray[i][REPETITION_INDEX];
                bigSwapVariableNum = sortArray[i+1][REPETITION_INDEX];

                sortArray[i][LETTER_INDEX] = bigSwapVariableChar;
                sortArray[i][REPETITION_INDEX] = bigSwapVariableNum;
                sortArray[i+1][LETTER_INDEX] = smallSwapVariableChar;
                sortArray[i+1][REPETITION_INDEX] = smallSwapVariableNum;
            }
        }
    }

}

void printRez (char** printArray, int lens) {
    int i = 0;

    for (i = 0; i < lens; i++) {
        if (printArray[i][LETTER_INDEX] != NULL){
            printf("\n %c", printArray[i][LETTER_INDEX]);
            printf(" - %d", printArray[i][REPETITION_INDEX]);
        }
    }
}

void freeMem (char** freeArray, int lens) {
    int i = 0;
    for (i = 0; i < lens; i++) {
        free(freeArray[i]);
    }
    free(freeArray);
}

int main(){

    char* userString = (char*)malloc(MAX_LENS_USERSTRING * sizeof(char)); // Create memory for userString[i]

    /* --- Fill userString array "0" elements --- */
    fillArray (userString, MAX_LENS_USERSTRING, 0);

    /* --- Create memory for numberOfCharRepetitions[i][k] --- */
    char** numberOfCharRepetitions = multidimensionalArray(MAX_LENS_USERSTRING, NUMBEROFCHARREPETITIONS_SECOND_INDEX);

    /* --- Fill numberOfCharRepetitions array "0" elements --- */
    fillMulDimArray (numberOfCharRepetitions, MAX_LENS_USERSTRING, NUMBEROFCHARREPETITIONS_SECOND_INDEX, 0);

    /* --- Assign array for conversion capital letter to lowercase letter --- */
    char capitalToLowercase[NUM_CHAR_INTO_ALPHABET][LETTERSARRAY_SECOND_INDEX];
    capitalAndLowercaseLetterArray(LETTERSARRAY_SECOND_INDEX, capitalToLowercase, NUM_CHAR_INTO_ALPHABET);

    printf("Enter some string: ");
    fgets(userString, MAX_LENS_USERSTRING, stdin);

    /* --- Conversion capital letter to lowercase letter --- */
    conversionCapToLow(userString, LETTERSARRAY_SECOND_INDEX, capitalToLowercase, MAX_LENS_USERSTRING, NUM_CHAR_INTO_ALPHABET);

    /* --- Assign letter from usersString to numberOfCharRepetitions and calculate repetitions --- */
    calcRepetition(userString, numberOfCharRepetitions, MAX_LENS_USERSTRING);

    /* --- Sort numberOfCharRepetitions array --- */
    sortLetters (numberOfCharRepetitions, NUM_CHAR_INTO_ALPHABET);

    /* --- Print numberOfCharRepetitions array --- */
    printRez(numberOfCharRepetitions, NUM_CHAR_INTO_ALPHABET);

    /* --- Free numberOfCharRepetitions array memory --- */
    freeMem(numberOfCharRepetitions, NUM_CHAR_INTO_ALPHABET);

    return 0;
}
