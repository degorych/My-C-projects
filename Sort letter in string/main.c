#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){

    /* --- Constants --- */
    const int MAX_LENS_USERSTRING = 100000;
    const int NUMBEROFCHARREPETITIONS_SECOND_INDEX = 2;

    const int NUM_CHAR_INTO_ALPHABET = 27;
    const int START_CAPITAL_LETTER_ASCII = 65;
    const int END_CAPITAL_LETTER_ASCII = 90;
    const int START_LOWERCASE_LETTER_ASCII = 97;
    const int END_LOWERCASE_LETTER_ASCII = 122;

    /* --- Array for conversion capital letter to lowercase letter --- */
    char capitalToLowercase[NUM_CHAR_INTO_ALPHABET][2];

    /* --- Counters --- */
    int i = 0;
    int k = 0;
    int l = 0;
    int m = 0;

    /* --- Arrays pointers  --- */
    char* pUserString;
    char** pNumberOfCharRepetitions;

    pUserString = (char*)malloc(MAX_LENS_USERSTRING * sizeof(char)); // Create memory for pUserString[i]

    /* --- Fill userString array "0" elements --- */
    for (i = 0; i < MAX_LENS_USERSTRING; i++) {
        pUserString[i] = 0;
    }

    pNumberOfCharRepetitions = (char**)malloc(MAX_LENS_USERSTRING * sizeof(char*)); //Create memory for pNumberOfCharRepetitions[i]

    /* --- Create memory for pNumberOfCharRepetitions[i][k], fill numberOfCharRepetitions array "0" elements --- */
    for (i = 0; i < MAX_LENS_USERSTRING; i++) {
        pNumberOfCharRepetitions[i] = (char*)malloc(NUMBEROFCHARREPETITIONS_SECOND_INDEX * sizeof(char));
        for (k = 0; k < NUMBEROFCHARREPETITIONS_SECOND_INDEX; k++){
            pNumberOfCharRepetitions[i][k] = 0;
        }
    }

    /* --- Assign array for conversion capital letter to lowercase letter --- */
    for (i = 0, k = 0, l = START_CAPITAL_LETTER_ASCII, m = START_LOWERCASE_LETTER_ASCII; i < NUM_CHAR_INTO_ALPHABET; i++, l++, m++) {
        capitalToLowercase[i][k] = l;
        capitalToLowercase[i][k+1] = m;
    }

    printf("Enter some string: ");
    fgets(pUserString, MAX_LENS_USERSTRING, stdin);

    /* --- Conversion capital letter to lowercase letter --- */
    for (i = 0; i < MAX_LENS_USERSTRING; i++) {
        for (k = 0, l = 0; k < NUM_CHAR_INTO_ALPHABET; k++) {
            if (pUserString[i] == capitalToLowercase[k][l]) {
                pUserString[i] = capitalToLowercase[k][l+1];
            }
        }
    }

    /* --- Assign letter from usersString to numberOfCharRepetitions and calculate repetitions --- */
    for (i = 0; i < MAX_LENS_USERSTRING; i++) {
        if (pUserString[i] >= START_LOWERCASE_LETTER_ASCII && pUserString[i] <= END_LOWERCASE_LETTER_ASCII) {
            for (k = 0, l = 0; k < MAX_LENS_USERSTRING; k++) {

                if (pUserString[i] == pNumberOfCharRepetitions[k][l]) {
                    pNumberOfCharRepetitions[k][l+1] = pNumberOfCharRepetitions[k][l+1] + 1;
                    break;
                }
                else if (pUserString[i] != pNumberOfCharRepetitions[k][l] && pNumberOfCharRepetitions[k][l] == 0) {
                    pNumberOfCharRepetitions[k][l] = pUserString[i];
                    pNumberOfCharRepetitions[k][l+1] = 1;
                    break;
                }
            }
        }
    }

    free(pUserString);

    /* --- Variables for swap--- */
    char smallSwapVariableChar = '0';
    char bigSwapVariableChar = '0';
    char smallSwapVariableNum = '0';
    char bigSwapVariableNum = '0';

    /* --- Sort numberOfCharRepetitions array --- */
    for (k = 0; k < NUM_CHAR_INTO_ALPHABET; k++) {
        for (i = 0; i < NUM_CHAR_INTO_ALPHABET; i++) {
            if (pNumberOfCharRepetitions[i][1] < pNumberOfCharRepetitions[i+1][1]) {
                smallSwapVariableChar = pNumberOfCharRepetitions[i][0];
                bigSwapVariableChar = pNumberOfCharRepetitions[i+1][0];
                smallSwapVariableNum = pNumberOfCharRepetitions[i][1];
                bigSwapVariableNum = pNumberOfCharRepetitions[i+1][1];

                pNumberOfCharRepetitions[i][0] = bigSwapVariableChar;
                pNumberOfCharRepetitions[i][1] = bigSwapVariableNum;
                pNumberOfCharRepetitions[i+1][0] = smallSwapVariableChar;
                pNumberOfCharRepetitions[i+1][1] = smallSwapVariableNum;
            }
        }
    }

    /* --- Print numberOfCharRepetitions array --- */
    for (i = 0; i < NUM_CHAR_INTO_ALPHABET; i++) {
            if (pNumberOfCharRepetitions[i][0] != NULL){
                printf("\n %c", pNumberOfCharRepetitions[i][0]);
                printf(" - %d", pNumberOfCharRepetitions[i][1]);
            }
    }

    for (i = 0; i < NUM_CHAR_INTO_ALPHABET; i++) {
        free(pNumberOfCharRepetitions[i]);
    }
    free(pNumberOfCharRepetitions);

    return 0;
}
