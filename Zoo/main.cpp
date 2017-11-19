#include <iostream>
#include <stdlib.h>

#define ADD_ANIMAL_VALUE 1
#define DELETE_ANIMAL_VALUE 2
#define SHOW_INFO_ABOUT_ANIMAL 3
#define EDIT_ANIMAL_INFO_VALUE 4
#define SHOW_ALL_ANIMAL_IN_ZOO 5
#define EXIT_PROGRAM 6

using namespace std;

const int MAX_ANIMAL_NUMBER = 20;

class Animal {
public:
    int age;
    string kind;
    string name;
    int pawsNum;
    int health;
    bool isShow;

    A () {
        age = 0;
        kind = "0";
        name = "0";
        pawsNum = 0;
        health = 0;
        isShow = 0;
    }

    void setValue (int valueAge, string valueKind, string valueName, int valuePawsNum, int valueHealth, bool valueIsShow) {
        age = valueAge;
        kind = valueKind;
        name = valueName;
        pawsNum = valuePawsNum;
        health = valueHealth;
        isShow = valueIsShow;
    }
};

class ZooManager {
public:
    void animalNotFound (int counter) {
        if (counter == MAX_ANIMAL_NUMBER) {
            cout << "Animal not found" << endl;
        }
    }

    void showMenu (Animal* obj) {
        int choiceSelector;

        for (;;) {
            cout << "  / --- Select action: --- /\n1. Add new animal.\n2. Delete animal.\n3. Show info about animal\n4. Edit animal info.\n5. Show animal list\n6. Exit program" << endl;
            cout << "\nYou answer: ";
            cin >> choiceSelector;
            cout << endl;

            switch (choiceSelector) {
                case ADD_ANIMAL_VALUE:
                    addNewAnimal(obj);
                    break;
                case DELETE_ANIMAL_VALUE:
                    deleteAnimal(obj);
                    break;
                case SHOW_INFO_ABOUT_ANIMAL:
                    showInfoAboutAnimal(obj);
                    break;
                case EDIT_ANIMAL_INFO_VALUE:
                    editAnimalInfo(obj);
                    break;
                case SHOW_ALL_ANIMAL_IN_ZOO:
                    showAllAnimalInZoo(obj);
                    break;
                case EXIT_PROGRAM:
                    exit(-1);
                default:
                    cout << "Your answer is incorrect";
                    exit (-2);
            }
        }
    }

    void addNewAnimal (Animal* obj) {
        int valueAge, valuePawsNum, valueHealth;
        string valueKind, valueName;
        bool valueIsShow;

        cout << "Enter age: ";
        cin >> valueAge;
        cout << endl;

        cout << "Enter kind: ";
        cin.get();
        getline(cin,valueKind) ;
        cout << endl;

        cout << "Enter name: ";
        getline(cin, valueName) ;
        cout << endl;

        cout << "Enter number of paws : ";
        cin >> valuePawsNum;
        cout << endl;

        cout << "Enter health: ";
        cin >> valueHealth;
        cout << endl;

        cout << "Animal in show? For yes - 1, for no - 0: ";
        cin >> valueIsShow;
        cout << endl;

        int i;
        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj[i].pawsNum == 0) {
                obj[i].setValue (valueAge, valueKind, valueName, valuePawsNum, valueHealth, valueIsShow);
                break;
            }
        }
    }

    void deleteAnimal (Animal* obj) {
        string name;
        int i;

        cin.get();
        cout << "Enter animal name: ";
        getline(cin, name);
        cout << endl;

        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (name == obj[i].name) {
                obj[i].setValue(0, "0", "0", 0, 0, 0);
                break;
            }
        }
        animalNotFound (i);
    }

    void showInfoAboutAnimal (Animal* obj) {
        string name;
        int i;

        cin.get();
        cout << "Enter animal name: ";
        getline(cin, name);
        cout << "\n---------- " << name << " ----------\n" << endl;

        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (name == obj[i].name) {
                cout << name << " age: " << obj[i].age << endl;
                cout << name << " kind: " << obj[i].kind << endl;
                cout << name << " paws number: " << obj[i].pawsNum << endl;
                cout << name << " health " << obj[i].health << endl;
                if (obj[i].isShow != 0) {
                    cout << name << " is show" << endl;
                }
                else {
                    cout << name << " is not show" << endl;
                }
                break;
            }
        }
        animalNotFound (i);
        cout << "--------------------" << endl;
    }

    void editAnimalInfo (Animal* obj) {
        string name, newKind;
        int i, newAge, newPawsNum, newHealth;
        bool newIsShow;

        cin.get();
        cout << "Enter animal name: ";
        getline(cin, name);
        cout << "\n---------- Edit " << name << "----------\n" << endl;

        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (name == obj[i].name) {
                cout << "Old age: " << obj[i].age << "; new age: ";
                cin >> newAge;
                cout << endl;

                cout << "Old kind: " << obj[i].kind << "; new kind: ";
                cin.get();
                getline(cin, newKind);
                cout << endl;

                cout << "Old paws number: " << obj[i].pawsNum << "; new paws number: ";
                cin >> newPawsNum;
                cout << endl;

                cout << "Old health: " << obj[i].health << "; new health: ";
                cin >> newHealth;
                cout << endl;

                if (obj[i].isShow != 0) {
                    cout << name << " is show now, select 0 to return in zoo, or 1 to live show: ";
                    cin >> newIsShow;
                    cout << endl;
                }
                else {
                    cout << name << " is not show now, select 1 to send in show, or 0 to live zoo: ";
                    cin >> newIsShow;
                    cout << endl;
                }
                obj[i].setValue (newAge, newKind, name, newPawsNum, newHealth, newIsShow);
                break;
            }
        }
        animalNotFound (i);
        cout << "-------------------------" << endl;
    }

    void showAllAnimalInZoo (Animal* obj) {
        int i,j;
        cout << "----- Animal List -----" << endl;
        for (i = 0, j = 1; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj[i].pawsNum != 0) {
                cout << j << ". " << obj[i].name << endl;
                j++;
            }
        }
        if (j == 1) {
            animalNotFound (i);
        }
        cout << "-----------------------\n" << endl;
    }
};

int main(){
    Animal* obj_Animal = new Animal[20];
    ZooManager* obj_ZooManager = new ZooManager;
    obj_ZooManager->showMenu(obj_Animal);

    delete []obj_Animal;
    delete obj_ZooManager;

    return 0;
}
