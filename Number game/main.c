#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    /* --- Enter data, generate number and selection array --- */
    int userNum = 0; 
    int genNum = 0; 
    char selector[50] = {0}; 

    for (;;) {
        /* --- Generate number --- */
        srand(time(NULL));
        genNum = rand() % 10;

        int i = 0;
        for (i = 0; i < 3; i++) {
            /* --- Choose variant --- */
            switch (i) {
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

            /* --- Check for enter data --- */
            if(scanf("%d",&userNum)!=1) {
                printf("\nEnter data is wrong\n");
                scanf("%*[^\n]");
                continue;
            };
            
            if (userNum < 0) {
                printf("\nOops, your number is negative!\n");
                continue;
            }
            
            if (userNum > genNum) {
                printf("\nBigger!\n");
            }
            
            if (userNum < genNum) {
                printf("\nSmaller!\n");
            }
            
            if (userNum == genNum) {
                printf("\nYou Win\n");
                break;
            }
        };
        printf("\n++++GAME OVER++++\n");

        /* --- Choice game again or no --- */
        rintf("\nDo you want to continue? No or Yes: ");
        scanf("%s", selector);

        char positAnsw[] = {"Yes"};
        char negatAnsw[] = {"No"};

        if (strcmp(negatAnsw, selector) == 0) {
            return 0;
        }
        else if (strcmp(positAnsw, selector) == 0) {
        }
        else {
            printf("Your answer has bad format");
            return 0;
        }
    }
};
