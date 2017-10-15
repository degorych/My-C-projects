#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* --- Coins array --- */
    int cent[5] = {50, 25, 10, 5, 1};

    /* --- Variables --- */
    int i = 0;
    int res = 0;
    int userMoney = 0;

    /* --- Enter data --- */
    float enterUserMoney = 0;

    printf("Enter your money: ");
    scanf("%f", &enterUserMoney);

    /* --- Float to int --- */
    enterUserMoney = enterUserMoney*100;
    userMoney = (int)enterUserMoney;

    for (i = 0; i < 5; i++) {
        res = res + userMoney/cent[i];
        if (userMoney%cent[i] == 0) {
            break;
        };
        userMoney = userMoney%cent[i];
    };

    printf("Number of coins: %d", res);
    return 0;
}
