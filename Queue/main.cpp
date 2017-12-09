#include <iostream>
#include <stdlib.h>
#define ARRAY_SIZE 10

using namespace std;

class Queue {
    int queueArray[ARRAY_SIZE];
    int* first;
    int* last;

public:
    Queue() {
        first = queueArray;
        last = queueArray;
    }

    /* --- Put new value in queue --- */
    void put(int value) {
        checkQueueArrayFull();

        *last = value;
        last = swapPointer(last);
    }

    /* --- Get first value to queue --- */
    int get() {
        checkQueueArrayEmpty();

        int value = *first;
        first = swapPointer(first);
        return value;
    }

    /* --- Swap pointer from end to start queue --- */
    int* swapPointer(int* pointer) {
        if (pointer == &queueArray[ARRAY_SIZE-1]) {
            pointer = &queueArray[0];
        }
        pointer++;
        return pointer;
    }

    /* --- Number values in queue --- */
    int queueArrayLens() {
        if (first == last) { // If array is empty lens = 0
            return 0;
        }
        else {
            return findPointersIndexes();
        }
    }

    /* --- Find pointers indexes and choice function for values counter --- */
    int findPointersIndexes() {
        int i, firstIndex, lastIndex;
        for (i = 0; i < ARRAY_SIZE; i++) {
            if (first == &queueArray[i]) {
                firstIndex = i;                     // Find index first
            }
            else if (last == &queueArray[i]) {
                lastIndex = i;                      // Find index last
            }
        }
        return choiceFunctionForValuesCounter(firstIndex, lastIndex);
    }

    /* --- Choice function for values counter --- */
    int choiceFunctionForValuesCounter(int firstIndex, int lastIndex) {
        int n;
        if (firstIndex > lastIndex) {
            n = ARRAY_SIZE - firstIndex + lastIndex;  // If was swap and first > last
        }
        else {
            n = lastIndex - firstIndex;               // If was not swap and first < last
        }
        return n;
    }

    void queueArrayLensMessage() {
        cout << "\nQueue array lens is " << queueArrayLens() << endl;
    }

    /* --- Check queue to full filling --- */
    void checkQueueArrayFull() {
        if (queueArrayLens() == ARRAY_SIZE-1) {
            cout << "Warning! Queue is full" << endl;
            exit (-1);
        }
    }

    /* --- Check queue to empty filling --- */
    void checkQueueArrayEmpty() {
        if (queueArrayLens() == 0) {
            cout << "Warning! Queue is empty" << endl;
            exit (-2);
        }
    }
};

int main(){
    Queue objQueue;

    int i;
    for (i = 0; i < 7; i++) {
        objQueue.put(i*10+10);
    }

    for (i = 0; i < 5; i++) {
        cout << objQueue.get() << endl;
    }

    objQueue.queueArrayLensMessage();
    return 0;
}
