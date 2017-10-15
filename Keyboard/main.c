#include <stdio.h>
#include <stdlib.h>

int main() {

    char key[27] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'q'};
    char userData = 'a';
    int i = 0;

    printf("Enter one letter: ");
    scanf("%c", &userData);

    for (i = 0; i < 26; i++) {
        if (key[i] == userData) {
            printf("Next letter is %c", key[i+1]);
        }
    }
    return 0;
}
