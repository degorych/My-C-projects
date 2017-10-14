#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* --- User data --- */
    int userData = 0;

    /* --- Counters --- */
    int i = 0;
    int k = 0;
    int l = 0;

    /* --- Manager variables --- */
    int star = 0; // Expression for "*" - number "*" in cycle
    int space = 0; // Expression for " " - number " " in cycle

    /* --- Enter data --- */
    printf("Enter number: ");
    scanf("%d", &userData);

    /* --- First triangle --- */
    printf("\nFirst triangle\n\n");

    for (i = 0; i < userData; i++) {
        for (k = 0, star = userData - i; k < star; k++) {
            printf("*");
        }

        printf("\n");
    }

    /* --- Second triangle --- */
    printf("\nSecond triangle\n\n");

    for (i = 0; i < userData; i++) {
        for (k = 0, star = i + 1; k < star; k++) {
            printf("*");
        }

        printf("\n");
    }

    /* --- Yelochka --- */
    printf("\nThis is Yelochka\n\n");

    for (i = 0; i < userData; i++) {
        for (k = 1, space = userData - i; k < space; k++) {
            printf(" ");
        }

        for (l = 0, star = 2*i + 1; l < star; l++) {
            printf("*");
        }

        printf("\n");
    }

    /* --- Stump ---*/
    for (i = 1; i < userData; i++) {
            printf(" ");
    }

    printf("*");

    return 0;
}
