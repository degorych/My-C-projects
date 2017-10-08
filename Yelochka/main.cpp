#include<stdio.h>
int main()
{
    int numOfFloors;
    printf("Enter number of floors: ");
    scanf("%d", &numOfFloors);
    int i = 1; //Cycle counters for first building
    int k = 1;
    int l = 1;
    if (numOfFloors > 0 and numOfFloors < 50) //Data enter verification
    {
    printf("\nFirst building \n \n"); //First building script
    do {
        do {
            printf("*"); i--;
        }
        while (i > 0);
        printf("\n"); k++; i = i + k;
    }
    while (i < numOfFloors + 1);
    i--; //Cycle counters for second building
    k--;
    printf("\nSecond building \n \n"); //Second building script
    do {
        do {
            printf("*"); i--;
        }
        while (i > 0);
        printf("\n"); i = k - 1; k--;
    }
    while (k > 0);
    i = 1; //Cycle counters for third building
    k = 1;
    printf("\nThis is Yelochka building:)\n \n"); //Third building script
    do {
        do {
            while (l < numOfFloors)
            {
                printf(" "); l++;
            };
            printf("*"); i--;
        }
        while (i > 0);
        printf("\n"); k = k + 2; i = i + k; l = (i + 1)/2;
    }
    while (i < numOfFloors*2 + 1);
    i= numOfFloors - 1; //Stump
    while (i > 0)
    {
        printf(" "); i--;
    };
    printf("*");
    }
    else { //Information for incorrect enter data
        printf("\nEnter data from 0 to 50!\n");
    };
}
