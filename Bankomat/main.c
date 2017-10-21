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
    int systemPin[5001];
    char userPin[5];

    for (i = 0; i < 5000; i++) {

        /* --- Generate money --- */
        account[i] = i*2 + 1;

        /* --- Generate pull pin --- */
        systemPin[i] = 2*i;
    }

    /* --- Generate admin pin --- */
        systemPin[5000] = 9999;

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
            if (userPin[3] != NULL && userPin[4] == NULL) {
            }
            else {
                printf("\nEnter data is wrong\n");
                scanf("%*[^\n]");
                break;
            }

            /* --- Check for enter data to incorrect and transform char into pin --- */
            for (l = 0; l < 4; l++) {
                if (userPin[l] > 47 && userPin[l] < 58) {
                    for (l = 0, k = 1000, pin = 0; l < 4, k >=1; l++, k = k/10) { // If user enter correct pin transform array userPin to int pin
                        pin = pin + (userPin[l] - 48)*k;
                    }
                }
                else {
                    printf("\nEnter data is wrong\n");
                    pin = 0;
                    scanf("%*[^\n]");
                    break;
                }
            }

            /* --- Admin verification --- */
            if (pin == systemPin[5000]) {
                printf("\nYou login as admin.\n\nSelect one of the following operations:\n1. View balance all accounts\n2. Zero out account\n\nYour answer is: ");
                scanf("%d", &choiceSelector);

                switch (choiceSelector) {
                    case 1:
                        for (l = 0; l < 5000; l++) {
                            printf("\n%d", account[l]);
                        }
                        break;
                    case 2:
                        for (l = 0; l < 5000; l++) {
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
            for (k = 0; k < 5000; k++) {
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
