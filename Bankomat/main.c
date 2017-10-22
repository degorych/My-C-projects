#include <stdio.h>
#include <stdlib.h>

int main() {

    /* --- Variables --- */
    int pin = 0;
    int choiceSelector = 0;
    int depocitAccount = 0;
    int withdrawAccount = 0;

    /* --- Counters --- */
    int i = 0;
    int k = 0;
    int l = 0;

    /* --- Arrays --- */
    int account[5000];
    int systemPin[5000];
    char userPin[5];

    /* --- Constants --- */
    const int ADMIN_PIN = 9999;
    const int NUMBER_OF_ACCOUNT = 5000;

    const int START_NUMBER_ASCII = 47;
    const int END_NUMBER_ASCII = 58;
    const int CHAR_TO_INT = 48;

    const int NUM_CHAR_IN_PIN = 4;

    for (i = 0; i < NUMBER_OF_ACCOUNT; i++) {

        /* --- Generate money --- */
        account[i] = i*2 + 1;

        /* --- Generate pull pin --- */
        systemPin[i] = 2*i;
    }

    for (;;) { // If enter data is incorrect endless loop
        for (i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    printf("\nEnter pin: ");
                    break;
                case 1:
                    printf("\nYour pin is wrong. You have 2 tries: ");
                    break;
                case 2:
                    printf("\nYour pin is wrong. You have 1 tries: ");
                    break;
                case 3:
                    printf("\nEnter valid pin.");
                    return 0;
            }

            /* --- Check for enter data to number of chars --- */
            scanf("%s", userPin);
            if (userPin[NUM_CHAR_IN_PIN - 1] != NULL && userPin[NUM_CHAR_IN_PIN] == NULL) {
            }
            else {
                printf("\nEnter data is wrong\n");
                scanf("%*[^\n]");
                break;
            }

            /* --- Check for enter data to incorrect and transform char into pin --- */
            for (l = 0; l < NUM_CHAR_IN_PIN; l++) {
                if (userPin[l] > START_NUMBER_ASCII && userPin[l] < END_NUMBER_ASCII) {
                    for (l = 0, k = 1000, pin = 0; l < NUM_CHAR_IN_PIN, k >=1; l++, k = k/10) { // If user enter correct pin transform array userPin to int pin
                        pin = pin + (userPin[l] - CHAR_TO_INT)*k;
                    }
                }
                else {
                    printf("\nEnter data is wrong\n");
                    pin = -1;
                    scanf("%*[^\n]");
                    break;
                }
            }

            /* --- Admin verification --- */
            if (pin == ADMIN_PIN) {
                printf("\nYou login as admin.\n\nSelect one of the following operations:\n1. View balance all accounts\n2. Zero out account\n\nYour answer is: ");
                scanf("%d", &choiceSelector);

                switch (choiceSelector) {
                    case 1:
                        for (l = 0; l < NUMBER_OF_ACCOUNT; l++) {
                            printf("\n%d", account[l]);
                        }
                        break;
                    case 2:
                        for (l = 0; l < NUMBER_OF_ACCOUNT; l++) {
                            account[l] = 0;
                            printf("\n%d", account[l]);
                        }
                        break;
                    default:
                        printf("\nYour answer is incorrect");
                        return 0;
                }
                return 0;
            }

            /* --- Check pin --- */
            for (k = 0; k < NUMBER_OF_ACCOUNT; k++) {
                if (systemPin[k] == pin) {
                    printf("\nYour Pin code is correct!");
                    printf("\nSelect one of the following operations:\n1. View balance.\n2. Deposit account.\n3. Withdraw funds.\n\nYour answer is: ");
                    scanf("%d", &choiceSelector);

                    switch (choiceSelector) {
                        case 1:
                            printf("\nYour balance is: %d", account[k]);
                            return 0;
                        case 2:
                            printf("\nEnter amount you wish to deposit: ");
                            scanf("%d", &depocitAccount);
                            account[k] = account[k] + depocitAccount;
                            printf("\nOperation is success. Your balance is: %d", account[k]);
                            return 0;
                        case 3:
                            printf("\nEnter amount you wish to withdraw: ");
                            scanf("%d", &withdrawAccount);
                            account[k] = account[k] - withdrawAccount;
                            printf("\nOperation is success. Your balance is: %d", account[k]);
                            return 0;
                        default:
                            printf("\nYour answer is incorrect");
                            return 0;
                    }
                }
            }
        }
    }
}
