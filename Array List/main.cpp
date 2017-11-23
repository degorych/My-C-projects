#include <iostream>

using namespace std;

class ArrayCollection {
private:
    static const int ARRAY_LENS = 2;

    int allocationSize;
    int currentSize;

    int* arrayCol;

public:
    ArrayCollection() {
        allocationSize = ARRAY_LENS;
        currentSize = 0;
        arrayCol = new int[ARRAY_LENS];
        fillArray(arrayCol, ARRAY_LENS);
    }

    /* --- Set parametres to array --- */
    void setParametres(int* setArray, int setCurrentSize, int setAllocationSize) {
        arrayCol = setArray;
        currentSize = setCurrentSize;
        allocationSize = setAllocationSize;
    }

    /* --- Initialize array --- */
    void fillArray(int* fillArray, int arraySize) {
        int i = 0;
        for (i = 0; i < arraySize; i++) {
            fillArray[i] = NULL;
        }
    }

    /* --- Get user element --- */
    int getElement() {
        int newElement;
        cout << "Enter new element: ";
        cin >> newElement;
        cout << endl;
        return newElement;
    }

    /* --- Add new element to free place or array end, if have enough place --- */
    void goodAddNewElement(int newElement) {
        int i;
        for (i = 0; i < allocationSize; i++) {
            if (arrayCol[i] == NULL) {
            arrayCol[i] = newElement;
            currentSize++;
            break;
            }
        }
    }

    /* --- Create new array, which more then used by a factor of allocationSizeFactor --- */
    void createNewArray(int allocationSizeFactor) {
        int i;
        int* newArray = new int[allocationSizeFactor*allocationSize];
        fillArray(newArray, allocationSizeFactor*allocationSize);

        for (i = 0; i < allocationSize; i++) {
            newArray[i] = arrayCol[i];
        }

        delete[] arrayCol;
        setParametres(newArray, allocationSize, allocationSizeFactor*allocationSize);
    }

    /* --- Add new element in array end --- */
    void addNewElement() {
        int newElement = getElement();
        if (currentSize < allocationSize) {
            goodAddNewElement(newElement);
        }
        else {
            createNewArray(2);
            goodAddNewElement(newElement);
        }
    }

    /* --- Show all elements in array --- */
    void showElements() {
        int i;
        for (i = 0; i < allocationSize; i++) {
            cout << arrayCol[i] << " ";
        }
        cout << endl;
    }

    /* --- Get user index --- */
    int getIndex() {
        int index;
        cout << "Enter index: ";
        cin >> index;
        cout << endl;

        return index;
    }

    /* --- Check index --- */
    int indexError(int index) {
        if (index >= allocationSize) {
            cout << "Index may be under " << allocationSize << endl;
            return -1;
        }
        else if (index < 0) {
            cout << "Enter number >= 0" << endl;
            return -1;
        }
    }

    /* --- Shift all elements after index to right --- */
    void loopForShift(int newElement, int index) {
        int i;
        for (i = allocationSize - 1; i > index; i--) {
            arrayCol[i] = arrayCol[i-1];
        }
    }

    /* --- Add new element if index is correct --- */
    void goodAddNewElementIndex(int newElement, int index) {
        if (arrayCol[index] == NULL) {
            arrayCol[index] = newElement;
        }
        else if (arrayCol[allocationSize-1] != NULL) {
            createNewArray(2);
            loopForShift(newElement, index);
        }
        else if (arrayCol[allocationSize-1] == NULL) {
            loopForShift(newElement, index);
        }
        arrayCol[index] = newElement;
        currentSize++;
    }

    /* Check for correct index and add new element --- */
    void addNewElementIndex() {
        int index = getIndex();
        int incorrectIndex = indexError(index);
        if (currentSize <= allocationSize && incorrectIndex != -1) {
            int newElement = getElement();
            goodAddNewElementIndex(newElement, index);
        }
    }

    /* --- Decrement array to uninitialized elements in end array --- */
    void optimalArraySize() {
        while (arrayCol[allocationSize-1] == NULL) {
            allocationSize--;
        }
        createNewArray(1);
    }

    /* --- Delete element with user index and shift another elements after index to right --- */
    void deleteElement() {
        int index = getIndex();
        int i;
        int incorrectIndex = indexError(index);
        if (incorrectIndex != -1){
            for (i = index; i < allocationSize - 1; i++) {
            arrayCol[i] = arrayCol[i+1];
            }
            arrayCol[allocationSize -1] = NULL;
        }

    }
};

int main(){
    int i;

    ArrayCollection* obj_ArrayCollection = new ArrayCollection;

    /* --- Make 3 add number in array end and show result --- */
    cout << "\n / --- Add 3 number to array end. --- /" << endl;
    for (i = 0; i < 3; i++) {
        obj_ArrayCollection->addNewElement();
        obj_ArrayCollection->showElements();
    }

    /* --- Make 3 add number with users index in array and show result --- */
    cout << "\n / --- Add 3 number with index. --- /" << endl;
    for (i = 0; i < 3; i++) {
        obj_ArrayCollection->addNewElementIndex();
        obj_ArrayCollection->showElements();
    }

    /* --- Delete NULL elements in array and show result --- */
    cout << "\n Optimization array: ";
    obj_ArrayCollection->optimalArraySize();
    obj_ArrayCollection->showElements();

    /* --- Delete element with user index in array and show result --- */
    cout << "\n / --- Delete element. --- /" << endl;
    obj_ArrayCollection->deleteElement();
    obj_ArrayCollection->showElements();

    delete obj_ArrayCollection;

    return 0;
}
