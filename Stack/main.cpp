#include <iostream>
#include <stdlib.h>
#define ARRAY_SIZE 10

using namespace std;

class Stack {
    int stackArray[ARRAY_SIZE];
    int* last;

public:
    Stack() {
        last = stackArray;
    }

    /* --- Put new value to stack --- */
    void put(int value) {
        checkStackArrayFull();

        *last = value;
        last++;
    }

    /* --- Get last value to stack --- */
    int get() {
        checkStackArrayEmpty();

        last--;
        int value = *last;
        return value;
    }

    /* --- Number values in stack --- */
    int stackArrayLens() {
        int i, n;
        for (i = 0, n = 0; i < ARRAY_SIZE; i++) {
            if (last != &stackArray[i]) {
                n++;
            }
            else {
                break;
            }
        }
        return n;
    }

    void stackArrayLensMessage() {
        cout << "\nStack array lens is " << stackArrayLens() << endl;
    }

    /* --- Check stack array to full filling --- */
    void checkStackArrayFull() {
        if (stackArrayLens() == ARRAY_SIZE-1) {
            cout << "Warning! Stack is full" << endl;
            exit (-1);
        }
    }

    /* --- Check stack array to empty filling --- */
    void checkStackArrayEmpty() {
        if (stackArrayLens() == 0) {
            cout << "Warning! Stack is empty" << endl;
            exit (-2);
        }
    }
};

int main(){
    Stack objStack;

    int i;
    for (i = 0; i < 7; i++) {
        objStack.put(i*10+10);
    }

    for (i = 0; i < 5; i++) {
        cout << objStack.get() << endl;
    }

    objStack.stackArrayLensMessage();
    return 0;
}
