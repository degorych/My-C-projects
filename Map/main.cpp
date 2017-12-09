#include <iostream>
#include <cstring>
#define ARRAY_LENS 100

using namespace std;

class Map {
private:
    int userArray[ARRAY_LENS];

public:
    Map() {
        int i;
        for (i = 0; i < ARRAY_LENS; i++) {
            userArray[i] = 0;
        }
    }

    void put(char* value, int number) {
        int index = hashFunc(value);
        userArray[index] = number;
    }

    void show(char* value) {
        int index = hashFunc(value);
        cout << value << ", " << userArray[index] << endl;
    }

    void showAllValues() {
        int i;
        for (i = 0; i < ARRAY_LENS; i++) {
            if (userArray[i] != 0) {
                cout << i << " - " << userArray[i] << endl;
            }
        }
    }

    void deleteValue(char* value) {
        int index = hashFunc(value);
        userArray[index] = 0;
    }

    int hashFunc(char* userString) {
        int hashSum, sum = 0;
        int n = strlen(userString);
        sum = userString[0]+(userString[0]*2);
        hashSum = sum%30 + n;
        return hashSum;
    }
};

int main(){
    Map objMap;
    objMap.put("vasya", 10);
    objMap.put("lena", 20);
    objMap.put("masha", 30);

    objMap.show("vasya");
    objMap.show("lena");
    objMap.show("masha");
    cout << endl;

    objMap.showAllValues();
    cout << endl;
    objMap.deleteValue("lena");
    objMap.showAllValues();
    return 0;
}
