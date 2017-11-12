#include <stdio.h>
#include <stdlib.h>
#define ENCRYPT_VALUE 1
#define DECIPHER_VALUE 2

const int MAX_USER_STRING_LENS = 10000;
const int NUMBER_LETTERS_IN_ALPHABET = 26;
const char END_CAPITAL_LETTER_IN_ALPHABET = 'Z';
const char END_LOWERCASE_LETTER_IN_ALPHABET = 'z';
const char START_LOWERCASE_LETTER_IN_ALPHABET = 'a';
const char START_CAPITAL_LETTER_IN_ALPHABET = 'A';

/* --- Fill input array with a value --- */
void fillArray (char* inputArray, int lensArray, int value) {
    int i = 0;
    for (i = 0; i < lensArray; i++) {
        inputArray[i] = value;
    }
}

/* --- Get user choice variable for encrypt/decipher --- */
int getInputUserChoice (char* description, int choicevariable) {
    printf("%s", description);
    scanf("%d", &choicevariable);
    scanf("%*[^\n]");
    getchar ();
    return choicevariable;
}

/* --- Fill input user array letters from user string --- */
void fillInputUserArray (char* inputUserArray, int lensUserArray) {
    printf("\nEnter string: ");
    fgets(inputUserArray, lensUserArray, stdin);
}

/* --- Fill user keyword --- */
void fillUserKeyWord (char* description, char* inputUserData) {
    printf("%s", description);
    scanf("%s", inputUserData);
    scanf("%*[^\n]");
    getchar ();
}

/* --- Fill keyWordString keyWord letters and transform their for shift--- */
void fillKeyWordString (char* keyWordStr, char* inputUserData, char* keyWord) {
    int lensInputUserData = strlen(inputUserData);
    int lensKeyWord = strlen(keyWord);
    int i, j = 0;

    for (i = 0; i < lensInputUserData - 1;) {
        for (j = 0; j < lensKeyWord; j++, i++) {
            if (keyWord[j] >= START_LOWERCASE_LETTER_IN_ALPHABET && keyWord[j] <= END_LOWERCASE_LETTER_IN_ALPHABET) {
                keyWordStr[i] = keyWord[j] - START_LOWERCASE_LETTER_IN_ALPHABET + 1;
            }
            else if (keyWord[j] >= START_CAPITAL_LETTER_IN_ALPHABET && keyWord[j] <= END_CAPITAL_LETTER_IN_ALPHABET) {
                keyWordStr[i] = keyWord[j] - START_CAPITAL_LETTER_IN_ALPHABET + 1;
            }
            else {
                printf("\nYour keyword is incorrect. Keyword should contain only capital or lowercase letters");
                exit(-2);
            }
        }
    }
}

/* --- Encrypt function --- */
void encryptUserString (char* inputUserString, char* keyWordString) {
    printf("\nYour encrypted string: ");
    int lensInputUserArray = strlen(inputUserString);
    int i, j = 0;

    for (i = 0, j = 0; i < lensInputUserArray - 1; i++, j++) {
        if ((inputUserString[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] <= END_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] + keyWordString[i] <= END_LOWERCASE_LETTER_IN_ALPHABET)||(inputUserString[i] >= START_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] <= END_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] + keyWordString[i] <= END_CAPITAL_LETTER_IN_ALPHABET)) {
            printf("%c", inputUserString[i]+keyWordString[j]);
        }
        else if ((inputUserString[i] >= START_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] <= END_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] + keyWordString[i] > END_CAPITAL_LETTER_IN_ALPHABET) || (inputUserString[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] <= END_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] + keyWordString[i] > END_LOWERCASE_LETTER_IN_ALPHABET)) {
            printf("%c", inputUserString[i]+keyWordString[j] - NUMBER_LETTERS_IN_ALPHABET);
        }
        else {
            j--;
            printf("%c", inputUserString[i]);
        }
    }
}

/* --- Decipher function --- */
void decipherUserString (char* inputUserString, char* keyWordString) {
    printf("\nYour deciphered string: ");
    int lensInputUserArray = strlen(inputUserString);
    int i, j = 0;

    for (i = 0, j = 0; i < lensInputUserArray - 1; i++, j++) {
        if ((inputUserString[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] <= END_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] - keyWordString[i] >= START_LOWERCASE_LETTER_IN_ALPHABET)||(inputUserString[i] >= START_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] <= END_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] - keyWordString[i] >= START_CAPITAL_LETTER_IN_ALPHABET)) {
            printf("%c", inputUserString[i]-keyWordString[j]);
        }
        else if ((inputUserString[i] >= START_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] <= END_CAPITAL_LETTER_IN_ALPHABET && inputUserString[i] - keyWordString[i] < START_CAPITAL_LETTER_IN_ALPHABET) || (inputUserString[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] <= END_LOWERCASE_LETTER_IN_ALPHABET && inputUserString[i] - keyWordString[i] < START_LOWERCASE_LETTER_IN_ALPHABET)) {
            printf("%c", inputUserString[i]-keyWordString[j] + NUMBER_LETTERS_IN_ALPHABET);
        }
        else {
            j--;
            printf("%c", inputUserString[i]);
        }
    }
}

/* --- This function unit all functions for encrypting or decipher --- */
void allInOneFunction (void fillInputUserArray (char*, int), void fillUserKeyWord (char*, char*), void fillKeyWordString (char*, char*, char*), void encryptOrDecipherUserString (char*, char*), char* userString, int userStringLens, char* keyWordDescription, char* keyWord, char* keyWordString) {
    fillInputUserArray (userString, userStringLens); // Fill userString array of user data
    fillUserKeyWord (keyWordDescription, keyWord); // Fill keyword
    fillKeyWordString (keyWordString, userString, keyWord); // Fill keyword string
    encryptOrDecipherUserString (userString, keyWordString); // Encrypt or decipher and show user string
}

int main(){
    char* selectionMenuDescription = {"What do you want to do?\n\nSelect 1 for encrypt\nSelect 2 for decipher\n\nYour answer is: "};
    char* keyWordDescription = {"Enter keyword: "};

    int choiceSelector;

    char keyWord[MAX_USER_STRING_LENS];
    char keyWordString[MAX_USER_STRING_LENS]; // Sequence of keywords transformed for shift

    char userString[MAX_USER_STRING_LENS];
    fillArray(userString, MAX_USER_STRING_LENS, 0); // Fill userString array default value

    choiceSelector = getInputUserChoice (selectionMenuDescription, choiceSelector); // View selection menu and check selection on letters

    switch (choiceSelector) {
        case ENCRYPT_VALUE:
            /* --- Encrypt --- */
            allInOneFunction (fillInputUserArray, fillUserKeyWord, fillKeyWordString, encryptUserString, userString, MAX_USER_STRING_LENS, keyWordDescription, keyWord, keyWordString);
            break;

        case DECIPHER_VALUE:
            /* --- Decipher --- */
            allInOneFunction (fillInputUserArray, fillUserKeyWord, fillKeyWordString, decipherUserString, userString, MAX_USER_STRING_LENS, keyWordDescription, keyWord, keyWordString);
            break;

        default:
            printf("Your answer is wrong!");
            return -1;
    }
    return 0;
}
