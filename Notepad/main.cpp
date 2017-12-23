#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>

#define ARRAY_SIZE 50

/* --- Menu (ASCII) --- */
#define ADD_NEW_NOTE 49
#define DELETE_NOTE 50
#define EDIT_NOTE 51
#define SHOW_ALL_NOTES 52
#define EXIT_PROGRAM 53

/* --- Text constructor --- */
#define SHOW_USER_MENU 0
#define ENTER_NOTE 1
#define SELECT_POSITION 2
#define ENTER_EDITED_NOTE 3
#define ENTER_ANSWER 4

/* --- Error constructor --- */
#define INCORRECT_ANSWER 0
#define INCORRECT_POSITION 1
#define LONG_NOTE_ERROR 2

using namespace std;

/* --- Manager information for user --- */
class UserInfoViewer {
private:
    char userText[5][120] = {"\nSelect 1 to add new note\nSelect 2 to delete note\nSelect 3 to edit note\nSelect 4 to show all note\nSelect 5 to exit\n\n",
                             "Enter your note: ",
                             "Select note position: ",
                             "Enter edited note: ",
                             "Enter answer: "};
    char userErrorMessage[3][61] = {"\nYour answer is incorrect",
                                    "\nIncorrect position",
                                    "\nWarning! Your note is very long, some info can not be save"};

public:
    void userTextConstructor(int index) {
        int i;
        for (i = 0; i < 120; i++) {
            if (userText[index][i] != 0) {
                cout << userText[index][i];
            }
        }
    }

    void userErrorConstructor(int index) {
        int i;
        for (i = 0; i < 61; i++) {
            if (userErrorMessage[index][i] != 0) {
                cout << userErrorMessage[index][i];
            }
        }
        cout << endl;
    }

    void showUserNotes(int counter, FILE* file) {
        int i, j;
        char note[ARRAY_SIZE] = {0};
        cout << endl;
        for (i = 1; i <= counter; i++) {
            fread(note, sizeof(char), ARRAY_SIZE, file);
            cout << i << ". ";
            for (j = 0; j < ARRAY_SIZE; j++) {
                if (note[j] != 0) {
                    cout << note[j];
                }
                else {
                    break;
                }
            }
            cout << endl;
        }
    }
};

/* --- Manager notes operations --- */
class ManagerNotepad {
private:
    char note[ARRAY_SIZE];
    UserInfoViewer* objUserInfoViewer = new UserInfoViewer;

public:
    ManagerNotepad() {
        fillArray(note, ARRAY_SIZE);
    }

    ~ManagerNotepad() {
        delete objUserInfoViewer;
    }

    void fillArray(char* userArray, int sizeArray) {
        int i;
        for (i = 0; i < sizeArray; i++) {
            userArray[i] = 0;
        }
    }

    int notesCounter() {
        FILE* file;
        file = fopen("notepad.txt", "r");
        int counter = 0;
        while (!feof(file)) {
            if (fgetc(file) == '|') {
                counter++;
            }
        }
        fclose(file);
        return counter;
    }

    void fillNoteFromConsol() {
        cin.getline(note, ARRAY_SIZE);

        if (note[ARRAY_SIZE-2] != 0) {
            objUserInfoViewer->userErrorConstructor(2);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        note[ARRAY_SIZE-1] = '|';
    }

    void addNewNote() {
        fillNoteFromConsol();

        FILE* file;
        file = fopen("notepad.txt", "a");
        fwrite(note, sizeof(char), ARRAY_SIZE, file);
        fclose(file);

        fillArray(note, ARRAY_SIZE);
    }

    void deleteNote(int position) {
        int userNotesCounter = notesCounter();

        /* --- Array for notes situated after delete note --- */
        int tempArraySize = ARRAY_SIZE*(userNotesCounter - position);
        char tempArray[tempArraySize];
        fillArray(tempArray, tempArraySize);

        /* --- Array for notes without delete note --- */
        int buferSize = ARRAY_SIZE*(userNotesCounter - 1);
        char bufer[buferSize];
        fillArray(bufer, buferSize);

        FILE* file;
        file = fopen("notepad.txt", "r+");

        fseek(file , ARRAY_SIZE*position, SEEK_SET);
        fread(tempArray, sizeof(char), tempArraySize, file);

        fseek(file , ARRAY_SIZE*(position - 1), SEEK_SET);
        fwrite(tempArray, sizeof(char), tempArraySize, file);

        fseek(file , 0, SEEK_SET);
        fread(bufer, sizeof(char), buferSize, file);

        fclose(file);

        /* --- Rewrite file --- */
        FILE* newFile;
        newFile = fopen("notepad.txt", "w");
        fwrite(bufer, sizeof(char), buferSize, newFile);
        fclose(newFile);
    }

    void editNote(int position) {
        fillNoteFromConsol();

        FILE* file;
        file = fopen("notepad.txt", "r+");
        fseek(file , ARRAY_SIZE*(position-1), SEEK_SET);
        fwrite(note, sizeof(char), ARRAY_SIZE, file);
        fclose(file);

        fillArray(note, ARRAY_SIZE);
    }

    void showNotes() {
        int i,j;
        int userNotesCounter = notesCounter();

        FILE* file;
        file = fopen("notepad.txt", "r");

        objUserInfoViewer->showUserNotes(userNotesCounter, file);

        fclose(file);
    }
};

/* --- Manager menu, user selector, user index --- */
class ManagerMenu {
private:
    char userSelector;
    int userIndex;

    UserInfoViewer* objUserInfoViewer = new UserInfoViewer;
    ManagerNotepad* objManagerNotepad = new ManagerNotepad;

public:
    ManagerMenu() {
        userSelector = 0;
        userIndex = 0;
    }

    ~ManagerMenu() {
        delete objUserInfoViewer;
        delete objManagerNotepad;
    }

    void setUserAnswer() {
        objUserInfoViewer->userTextConstructor(ENTER_ANSWER);
        cin >> userSelector;
        cin.get();
    }

    void setUserIndex() {
        objUserInfoViewer->userTextConstructor(SELECT_POSITION);
        cin >> userIndex;
        cin.get();
    }

    bool checkUserIndex() {
        setUserIndex();

        if (userIndex < 1 || userIndex > objManagerNotepad->notesCounter()) {
            objUserInfoViewer->userErrorConstructor(INCORRECT_POSITION);
            return 0;
        }
        return 1;
    }

    void userMenu() {
        for (;;) {
            objUserInfoViewer->userTextConstructor(SHOW_USER_MENU);
            setUserAnswer();

            switch (userSelector) {
            case ADD_NEW_NOTE:
                objUserInfoViewer->userTextConstructor(ENTER_NOTE);
                objManagerNotepad->addNewNote();
                break;

            case DELETE_NOTE:
                if (!checkUserIndex()) {
                    break;
                }

                objManagerNotepad->deleteNote(userIndex);
                break;

            case EDIT_NOTE:
                if (!checkUserIndex()) {
                    break;
                }

                objUserInfoViewer->userTextConstructor(ENTER_EDITED_NOTE);
                objManagerNotepad->editNote(userIndex);
                break;

            case SHOW_ALL_NOTES:
                objManagerNotepad->showNotes();
                break;

            case EXIT_PROGRAM:
                return;

            default:
                objUserInfoViewer->userErrorConstructor(INCORRECT_ANSWER);
                break;
            }
        }
    }
};

int main(){
    ManagerMenu* objManagerMenu = new ManagerMenu;
    objManagerMenu->userMenu();

    delete objManagerMenu;

    return 0;
}
