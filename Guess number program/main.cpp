#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int userNum = 0; //Enter number
    int genNum = 0; //Generate number
    char selector[3] = {0}; //Selection counter
    char letterCheck = 0;

    for (;;) {
        srand(time(NULL));
        genNum = rand() % 10;

        for (int i = 0; i < 3; i++) {
            switch ( i ) {
            case 0:
            printf("\nEnter positive number: ");
            break;
            case 1:
            printf("\nRe Enter please (2 tries remains): ");
            break;
            case 2:
            printf("\nRe Enter please (1 tries remains): ");
            break;
            };

            scanf("%d%c", &userNum, &letterCheck);

            if (!letterCheck) {
                printf("You mast enter the number");
            };

            if (userNum < 0) {
                printf("\nOops, your number is negative!\n");
                continue;
            };
            if (userNum > genNum) {
                printf("\nBigger!\n");
            };
            if (userNum < genNum) {
                printf("\nSmaller!\n");
            };
            if (userNum == genNum) {
                printf("\nYou Win\n");
                break;
            };
        };
        printf("\n++++GAME OVER++++\n");

        printf("\nDo you want to continue? No or Yes: ");
        scanf("%s", selector);

        if (selector[0] == 'N', selector[1] == 'o') {
            return 0;
        }
        else if (selector[0] == 'Y', selector[1] == 'e', selector[2] == 's') {
            continue;
        }
        else {
            printf("Your answer is wrong");
            return 0;
        }
    };
}



