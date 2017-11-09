#include <stdio.h>
#include <stdlib.h>
#define ENCRYPT_VALUE 1
#define DECIPHER_VALUE 2

/* --- Fill userString array --- */

void fillArray (char* array, int lensArray) {
    int i = 0;
    for (i = 0; i < lensArray; i++) {
        array[i] = 0;
    }
}

/* --- Select key number or selector --- */

int enterDataAndNumberCheckingFunction (char *description, int enterNumber) {
    printf("%s", description);
    int checkEnterUserDataVar = scanf("%d", &enterNumber);
    scanf("%*[^\n]");
    getchar ();
    if (checkEnterUserDataVar == 0) {
        printf("Your enter data is incorrect\n");
    }
    return enterNumber;
}

/* --- Enter user data --- */

void userDataString (char* userData, int lensData) {
    printf("\nEnter string for encrypt: ");
    fgets(userData, lensData, stdin);
}

/* --- Check and loop key number --- */

int deleteLoopKeyNumber (int keyNum, int keyMaxValue) {
    if (keyNum > keyMaxValue) {
        keyNum = keyNum % keyMaxValue;
    }
    else if (keyNum < 0) {
        printf("Your key number is negative");
        exit(1);
    }
    return keyNum;
}

/* --- Encrypt or decipher user data and view result --- */

void encryptOrDecipher (char* userData, int keyNum, int encryptAndDecipher) {
    int i = 0;



    const int NUMBER_LETTERS_IN_ALPHABET = 26;
    const char END_CAPITAL_LETTER_IN_ALPHABET = 'Z';
    const char END_LOWERCASE_LETTER_IN_ALPHABET = 'z';
    const char START_LOWERCASE_LETTER_IN_ALPHABET = 'a';
    const char START_CAPITAL_LETTER_IN_ALPHABET = 'A';


    printf("\nResult is: ");
    for (i = 0; i < strlen(userData); i++) {
        if (userData[i] == '\n') {
            break;
        }
        else if ((encryptAndDecipher == ENCRYPT_VALUE && userData[i] <= END_CAPITAL_LETTER_IN_ALPHABET && userData[i] >= START_CAPITAL_LETTER_IN_ALPHABET && userData[i] + keyNum > END_CAPITAL_LETTER_IN_ALPHABET)||(encryptAndDecipher == ENCRYPT_VALUE && userData[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && userData[i] <= END_LOWERCASE_LETTER_IN_ALPHABET  && userData[i] + keyNum > END_LOWERCASE_LETTER_IN_ALPHABET)) {
            userData[i] = userData[i] - NUMBER_LETTERS_IN_ALPHABET + keyNum;
            printf("%c", userData[i]);
        }
        else if ((encryptAndDecipher == DECIPHER_VALUE && userData[i] <= END_CAPITAL_LETTER_IN_ALPHABET && userData[i] >= START_CAPITAL_LETTER_IN_ALPHABET && userData[i] - keyNum < START_CAPITAL_LETTER_IN_ALPHABET)||(encryptAndDecipher == DECIPHER_VALUE && userData[i] >= START_LOWERCASE_LETTER_IN_ALPHABET && userData[i] <= END_LOWERCASE_LETTER_IN_ALPHABET && userData[i] - keyNum < START_LOWERCASE_LETTER_IN_ALPHABET)) {
            userData[i] = userData[i] + NUMBER_LETTERS_IN_ALPHABET - keyNum;
            printf("%c", userData[i]);
        }
        else if (userData[i] != ' ') {
                if (encryptAndDecipher == ENCRYPT_VALUE) {
                    userData[i] = userData[i] + keyNum;
                    printf("%c", userData[i]);
                }
                else if (encryptAndDecipher == DECIPHER_VALUE) {
                    userData[i] = userData[i] - keyNum;
                    printf("%c", userData[i]);
                }

        }
        else if (userData[i] == ' ') {
            printf("%c", userData[i]);
        }
    }
}

void encryptAndDecipherFullFunction (void (*enterUserData)(char*, int), int (*keyNumberSelectionsFunc)(char*, int), int (*checkAndLoopKeyNumFunc)(int, int), void (*encryptOrDecipherUserData)(char*, int, int), char* userStr, int keyStr, int keyNum, int choiceSel, int lens, int letternum) {

    enterUserData (userStr, lens); // Enter user data
    keyNum = keyNumberSelectionsFunc (keyStr, keyNum); // Select key number
    int keyNumUnloop = checkAndLoopKeyNumFunc (keyNum, letternum); // Check and loop key number
    encryptOrDecipherUserData (userStr, keyNumUnloop, choiceSel); // Encrypt or decipher user data and view result
}

int main() {
    int choiceSelector = 0;
    int keyNumber = 0;

    const int MAX_USER_STRING_LENS = 10000;
    const int NUMBER_LETTERS_IN_ALPHABET = 26;

    char* selectionMenuString = {"What do you want to do?\n\nSelect 1 for encrypt\nSelect 2 for decipher\n\nYour answer is: "};
    char* keyString = {"Enter key number: "};
    char* encryptString = {"Your encrypt string is: "};
    char* decipherString = {"Your decipher string is: "};

    char userString[MAX_USER_STRING_LENS];
    fillArray(userString, MAX_USER_STRING_LENS); // Fill userString array

    choiceSelector = enterDataAndNumberCheckingFunction (selectionMenuString, choiceSelector); // View selection menu and check selection on letters

    switch (choiceSelector) {
        case ENCRYPT_VALUE:
            encryptAndDecipherFullFunction (userDataString, enterDataAndNumberCheckingFunction, deleteLoopKeyNumber, encryptOrDecipher, userString, keyString, keyNumber, choiceSelector, MAX_USER_STRING_LENS, NUMBER_LETTERS_IN_ALPHABET);
            break;
        case DECIPHER_VALUE:
            encryptAndDecipherFullFunction (userDataString, enterDataAndNumberCheckingFunction, deleteLoopKeyNumber, encryptOrDecipher, userString, keyString, keyNumber, choiceSelector, MAX_USER_STRING_LENS, NUMBER_LETTERS_IN_ALPHABET);
            break;
        default:
            printf("Your answer is wrong!");
            break;
    }
    return 0;
}
