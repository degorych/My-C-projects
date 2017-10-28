#include <stdio.h>
#include <stdlib.h>

#define FIRST_TRY 0
#define SECOND_TRY 1
#define THIRD_TRY 2
#define BREAK_PROGRAM 3
#define SHOW_ALL_ACCOUNT 1
#define MAKE_ZERO_ACCOUNT 2
#define SHOW_BALANS 1
#define DEPOSIT_ACCOUNT 2
#define WITHDRAW_FUNDS 3

int main() {

    /* --- Variables --- */
    int pin = 0; // Pin from userPin array
    int choiceOperationSelector = 0; // Choice which operation program mast do
    int depocitAccount = 0; // Increment user account to ... $
    int withdrawAccount = 0; // Decrement user account to ... $
    char yesNoSelector = 0; // Continue working or exit to program
    int powerOfTen = 1; // Number for transform userPin array to int pin (10 in power of char-1 in pin)

    /* --- Counters --- */
    int i = 0;
    int k = 0;
    int l = 0;

    /* --- Constants --- */
    const int ADMIN_PIN = 9999;
    const int NUMBER_OF_ACCOUNT = 5000;

    const int START_NUMBER_ASCII = 48; // '0' into ASCII
    const int END_NUMBER_ASCII = 57; // '9' into ASCII

    const int NUM_CHAR_IN_PIN = 4;

    /* --- Arrays --- */
    int account[NUMBER_OF_ACCOUNT];
    int systemPin[NUMBER_OF_ACCOUNT];
    char userPin[NUM_CHAR_IN_PIN + 1];

    for (i = 0; i < NUMBER_OF_ACCOUNT; i++) {

        /* --- Generate money --- */
        account[i] = i*2 + 1;

        /* --- Generate pull pin --- */
        systemPin[i] = 2*i;
    }

    for (;;) { // If enter data is incorrect endless loop
        for (i = 0; i < 4; i++) {
            switch (i) {
                case FIRST_TRY:
                    printf("\nEnter pin: ");
                    break;
                case SECOND_TRY:
                    printf("\nYour pin is wrong. You have 2 tries: ");
                    break;
                case THIRD_TRY:
                    printf("\nYour pin is wrong. You have 1 tries: ");
                    break;
                case BREAK_PROGRAM:
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

            /* --- Check for enter data to incorrect and transform char array to pin variable --- */
            for (l = 0; l < NUM_CHAR_IN_PIN; l++) {

                /* --- Calculate int powerOfTen to transform array userPin to int pin --- */
                for (k = 1, powerOfTen = 1; k < NUM_CHAR_IN_PIN; k++) {
                    powerOfTen = powerOfTen*10;
                }

                /* --- Transform array userPin to int pin --- */
                if (userPin[l] >= START_NUMBER_ASCII && userPin[l] <= END_NUMBER_ASCII) {
                    for (l = 0, k = powerOfTen, pin = 0; l < NUM_CHAR_IN_PIN, k >=1; l++, k = k/10) { // If user enter correct pin transform array userPin to int pin
                        pin = pin + (userPin[l] - START_NUMBER_ASCII)*k;
                    }
                }
                else {
                    pin = -1;
                }
            }
            if (pin == -1) {
                printf("\nEnter data is wrong\n");
                for (k = 0; k < NUM_CHAR_IN_PIN + 1; k++) {
                    userPin[k] = 0;
                }
                scanf("%*[^\n]");
                break;
            }


            /* --- Admin verification --- */
            if (pin == ADMIN_PIN) {
                for (;;) {
                    printf("\nYou login as admin.\n\nSelect one of the following operations:\nView balance all accounts - 1\nZero out account - 2\n\nYour answer is: ");
                    scanf("%d", &choiceOperationSelector);

                    switch (choiceOperationSelector) {
                        case SHOW_ALL_ACCOUNT:
                            for (l = 0; l < NUMBER_OF_ACCOUNT; l++) {
                                printf("\n%d", account[l]);
                            }
                            break;
                        case MAKE_ZERO_ACCOUNT:
                            for (l = 0; l < NUMBER_OF_ACCOUNT; l++) {
                                account[l] = 0;
                                printf("\n%d", account[l]);
                            }
                            break;
                        default:
                            printf("\nYour answer is incorrect. Try again.");
                            scanf("%*[^\n]");
                            break;
                    }

                    choiceOperationSelector = 0;
                    scanf("%*[^\n]");

                    printf("\nContinue operations? Y/N: ");
                    scanf(" %c", &yesNoSelector);

                    switch (yesNoSelector) {
                        case 'Y':
                            break;
                        case 'N':
                            return 0;
                        default:
                            printf("\nYour answer is incorrect");
                            choiceOperationSelector = 0;
                            scanf("%*[^\n]");
                            break;
                    }
                }
            }

            /* --- Check pin --- */
            for (k = 0; k < NUMBER_OF_ACCOUNT; k++) {
                if (systemPin[k] == pin) {
                    for (;;) {
                        printf("\nYour Pin is correct!\nSelect one of the following operations:\nView balance - 1.\nDeposit account - 2.\nWithdraw funds - 3.\n\nYour answer is: ");
                        scanf("%d", &choiceOperationSelector);

                        switch (choiceOperationSelector) {
                            case SHOW_BALANS:
                                printf("\nYour balance is: %d", account[k]);
                                break;
                            case DEPOSIT_ACCOUNT:
                                printf("\nEnter amount you wish to deposit: ");
                                scanf("%d", &depocitAccount);
                                account[k] = account[k] + depocitAccount;
                                printf("\nOperation is success. Your balance is: %d", account[k]);
                                break;
                            case WITHDRAW_FUNDS:
                                printf("\nEnter amount you wish to withdraw: ");
                                scanf("%d", &withdrawAccount);
                                account[k] = account[k] - withdrawAccount;
                                printf("\nOperation is success. Your balance is: %d", account[k]);
                                break;
                            default:
                                printf("\nYour answer is incorrect. Try again.");
                                scanf("%*[^\n]");
                                break;
                        }
                        choiceOperationSelector = 0;
                        scanf("%*[^\n]");

                        printf("\nContinue operations? Y/N: ");
                        scanf(" %c", &yesNoSelector);
                        switch (yesNoSelector) {
                            case 'Y':
                                break;
                            case 'N':
                                return 0;
                            default:
                                printf("\nYour answer is incorrect");
                                choiceOperationSelector = 0;
                                scanf("%*[^\n]");
                                break;
                        }
                    }
                }
            }
        }
    }
}
