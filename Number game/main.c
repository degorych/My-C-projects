#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    int userNum = 0; //Enter number
    int genNum = 0; //Generate number
    char selector[50] = {0}; //Selection array

    for (;;) {
        srand(time(NULL));
        genNum = rand() % 10;

        int i = 0;
        for (i = 0; i < 3; i++) {
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

            if(scanf("%d",&userNum)!=1) { // Check for enter data
                printf("\nEnter data is wrong\n");
                scanf("%*[^\n]");
                continue;
            }
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

        printf("\nDo you want to continue? No or Yes: "); //Choice game again or no
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
}
