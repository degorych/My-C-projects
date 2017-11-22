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
private:
    int age;
    string kind;
    string name;
    int pawsNum;
    int health;
    bool isShow;

public:
    Animal() {
        age = 0;
        kind = "0";
        name = "0";
        pawsNum = 0;
        health = 0;
        isShow = 0;
    }

    /* --- SET --- */
    void setValue(int valueAge, string valueKind, string valueName, int valuePawsNum, int valueHealth, bool valueIsShow) {
        age = valueAge;
        kind = valueKind;
        name = valueName;
        pawsNum = valuePawsNum;
        health = valueHealth;
        isShow = valueIsShow;
    }

    /* --- SET animal name for search in animal list --- */
    int setNameForSearch(string nameForSearch) {
        if (nameForSearch == name) {
            return 1;
        }
        else {
            return 0;
        }
    }

    /* --- Check to name existence --- */
    int checkToExistenceName() {
        if (name != "0") {
            return 1;
        }
    }

    /* --- Check to name existence and write him--- */
    int checkToExistenceName(int counter) {
        if (name != "0") {
            cout << counter << ". " << name << endl;
            return 1;
        }
    }

    /* --- GET function for add new animal --- */
    int getAge() {
        int valueAge;
        cout << "Enter age: ";
        cin >> valueAge;
        cout << endl;
        return valueAge;
    }

    string getKind() {
        string valueKind;
        cout << "Enter kind: ";
        cin >> valueKind;
        cout << endl;
        return valueKind;
    }

    string getName() {
        string valueName;
        cout << "Enter name: ";
        cin >> valueName;
        cout << endl;
        return valueName;
    }

    int getPawsNum() {
        int valuePawsNum;
        cout << "Enter paws number: ";
        cin >> valuePawsNum;
        cout << endl;
        return valuePawsNum;
    }

    int getHealth() {
        int valueHealth;
        cout << "Enter health: ";
        cin >> valueHealth;
        cout << endl;
        return valueHealth;
    }

    bool getIsShow() {
        bool valueIsShow;
        cout << "Enter 1, if animal is show, or 0 if animal in zoo: ";
        cin >> valueIsShow;
        cout << endl;
        return valueIsShow;
    }

    /* --- GET function for edit animal --- */
    int getAgeEdit() {
        int valueAge;
        cout << "Old age: " << age << "; new age: ";
        cin >> valueAge;
        cout << endl;
        return valueAge;
    }

    string getKindEdit() {
        string valueKind;
        cout << "Old kind: " << kind << "; new kind: ";
        cin >> valueKind;
        cout << endl;
        return valueKind;
    }

    string getNameEdit() {
        string valueName;
        cout << "Old name: " << name << "; new name: ";
        cin >> valueName;
        cout << endl;
        return valueName;
    }

    int getPawsNumEdit() {
        int valuePawsNum;
        cout << "Old paws number: " << pawsNum << "; new paws number: ";
        cin >> valuePawsNum;
        cout << endl;
        return valuePawsNum;
    }

    int getHealthEdit() {
        int valueHealth;
        cout << "Old health: " << health << "; new health: ";
        cin >> valueHealth;
        cout << endl;
        return valueHealth;
    }

    bool getIsShowEdit() {
        bool valueIsShow;
        if (isShow != 0) {
            cout << name << " is show now, select 0 to return in zoo, or 1 to live show: ";
            cin >> valueIsShow;
            cout << endl;
        }
        else {
            cout << name << " is not show now, select 1 to send in show, or 0 to live zoo: ";
            cin >> valueIsShow;
            cout << endl;
        }
        return valueIsShow;
    }

    /* --- Add new animal --- */
    void addNewAnimal() {
        int valueAge, valuePawsNum, valueHealth;
        string valueKind, valueName;
        bool valueIsShow;

        valueAge = getAge();
        valueKind = getKind();
        valueName = getName();
        valuePawsNum = getPawsNum();
        valueHealth = getHealth();
        valueIsShow = getIsShow();

        setValue(valueAge, valueKind, valueName, valuePawsNum, valueHealth, valueIsShow);
    }

    /* --- Delete animal --- */
    void deleteAnimal() {
        setValue(0, "0", "0", 0, 0, 0);
    }

    /* --- Show info about animal --- */
    void showInfoAboutAnimal() {
        cout << "Age: " << age << endl;
        cout << "Kind: " << kind << endl;
        cout << "Paws number: " << pawsNum << endl;
        cout << "Health " << health << endl;
        if (isShow != 0) {
            cout << "Is show" << endl;
        }
        else {
            cout << "Is not show" << endl;
        }
    }

    /* --- Edit info about animal --- */
    void editAnimalInfo() {
        int editAge, editPawsNum, editHealth;
        string editKind, editName;
        bool editIsShow;

        editAge = getAgeEdit();
        editKind = getKindEdit();
        editName = getNameEdit();
        editPawsNum = getPawsNumEdit();
        editHealth = getHealthEdit();
        editIsShow = getIsShowEdit();

        setValue(editAge, editKind, editName, editPawsNum, editHealth, editIsShow);;
    }
};

class Zoo {
private:
    Animal* obj_Animal = new Animal[MAX_ANIMAL_NUMBER];
    int animalCounter;

public:
    Zoo() {
        animalCounter = 0;
    }

    /* --- For incorrect animal name or if number of animals is "0" --- */
    void animalNotFound(int counter) {
        if (counter == MAX_ANIMAL_NUMBER) {
            cout << "Animal not found" << endl;
        }
    }

    /* --- Get animal name in user console for search in animal list --- */
    string getNameAnimalInZoo() {
        string nameForSearch;

        cin.get();
        cout << "Enter animal name: ";
        getline(cin, nameForSearch);
        cout << endl;
        return nameForSearch;
    }

    void addNewAnimal() {
        int i;
        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj_Animal[i].checkToExistenceName() != 1) {
                obj_Animal[i].addNewAnimal();
                animalCounter++;
                break;
            }
        }
    }

    void deleteAnimal() {
        string nameForSearch = getNameAnimalInZoo();
        int i;
        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj_Animal[i].setNameForSearch(nameForSearch) == 1) {
                obj_Animal[i].deleteAnimal();
                animalCounter--;
                break;
            }
        }
        animalNotFound(i);
    }

    void showInfoAboutAnimal() {
        string nameForSearch = getNameAnimalInZoo();
        cout << "\n---------- " << nameForSearch << " ----------\n" << endl;
        int i;
        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj_Animal[i].setNameForSearch(nameForSearch) == 1) {
                obj_Animal[i].showInfoAboutAnimal();
                break;
            }
        }
        animalNotFound(i);
        cout << "-------------------------\n" << endl;
    }

    void editAnimalInfo() {
        string nameForSearch = getNameAnimalInZoo();
        cout << "\n---------- Edit " << nameForSearch << "----------\n" << endl;

        int i;
        for (i = 0; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj_Animal[i].setNameForSearch(nameForSearch) == 1) {
                obj_Animal[i].editAnimalInfo();
                break;
            }
        }
        animalNotFound(i);
        cout << "----------------------------" << endl;
    }

    void showAllAnimalInZoo() {
        int i,j;

        cout << "----- Animal List -----\n" << endl;
        for (i = 0, j = 1; i < MAX_ANIMAL_NUMBER; i++) {
            if (obj_Animal[i].checkToExistenceName(j) == 1) {
                j++;
            }
        }

        if (j == 1) {
            animalNotFound(i);
        }
        else {
            cout << "\nTotal: " << animalCounter << endl;
        }
        cout << "\n-----------------------\n" << endl;
    }

    /* --- Delete animal objects from memory  --- */
    void deleteAnimals() {
        delete[] obj_Animal;
    }
};

class ZooManager {
public:
    /* --- Show menu and user choice --- */
    int menu() {
        int choiceSelector;

        cout << "  / --- Select action: --- /\n1. Add new animal.\n2. Delete animal.\n3. Show info about animal.\n4. Edit animal info.\n5. Show animal list.\n6. Exit program." << endl;
        cout << "\nYou answer: ";
        cin >> choiceSelector;
        cout << endl;

        return choiceSelector;
    }

    void choiceVariants(Zoo* obj) {
        for (;;) {
            int userchoice = menu();

            switch (userchoice) {
                case ADD_ANIMAL_VALUE:
                    obj->addNewAnimal();
                    break;
                case DELETE_ANIMAL_VALUE:
                    obj->deleteAnimal();
                    break;
                case SHOW_INFO_ABOUT_ANIMAL:
                    obj->showInfoAboutAnimal();
                    break;
                case EDIT_ANIMAL_INFO_VALUE:
                    obj->editAnimalInfo();
                    break;
                case SHOW_ALL_ANIMAL_IN_ZOO:
                    obj->showAllAnimalInZoo();
                    break;
                case EXIT_PROGRAM:
                    exit(-1);
                default:
                    cout << "Your answer is incorrect";
                    exit(-2);
            }
        }
    }
};

int main(){
    Zoo* obj_Zoo = new Zoo;
    ZooManager* obj_ZooManager = new ZooManager;
    obj_ZooManager->choiceVariants(obj_Zoo);

    obj_Zoo->deleteAnimals();
    delete obj_Zoo;
    delete obj_ZooManager;

    return 0;
}
