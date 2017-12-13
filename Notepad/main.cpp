#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define ARRAY_SIZE 50

#define ADD_NEW_NOTE 1
#define DELETE_NOTE 2
#define EDIT_NOTE 3
#define SHOW_ALL_NOTES 4
#define EXIT_PROGRAM 5

using namespace std;

/* --- Manager information for user --- */
class UserInfoViewer {
public:
    void showUserMenu() {
        cout << "Select 1 to add new note\nSelect 2 to delete note\nSelect 3 to edit note\nSelect 4 to show all note\nSelect 5 to exit\n" << endl;
    }

    void showUserAnswer() {
        cout << "Your answer is - ";
    }

    void addNewNoteText() {
        cout << "Enter your note: ";
    }

    void showIncorrectUserSelectError() {
        cout << "Your answer is incorrect" << endl;
    }

    void showIncorrectUserIndexError() {
        cout << "Incorrect position" << endl;
    }

    void editNoteSelectPositionText() {
        cout << "Select note position: ";
    }

    void editNoteText() {
        cout << "Enter edited note: ";
    }

    void noteOverflow() {
        cout << "Warning! Your note is very long, some info can not be save";
    }
};

/* --- Manager notes operations --- */
class ManagerNotepad {
private:
    char note[ARRAY_SIZE];

public:
    ManagerNotepad() {
        fillArray(note, ARRAY_SIZE);
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
        cin.getline(note, ARRAY_SIZE-1);
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

        for (i = 1; i <= userNotesCounter; i++) {
            fread(note, sizeof(char), ARRAY_SIZE, file);
            cout << i << ". ";
            for (j = 0; j < ARRAY_SIZE; j++) {
                if (note[j] != 0) {
                    cout << note[j];
                }
            }
            cout << endl;
        }

        fclose(file);
        fillArray(note, ARRAY_SIZE);
    }
};

/* --- Manager menu, user selector, user index --- */
class ManagerMenu {
private:
    int userSelector;
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
        objUserInfoViewer->showUserAnswer();
        cin >> userSelector;
        cin.get();
    }

    void setUserIndex() {
        objUserInfoViewer->editNoteSelectPositionText();
        cin >> userIndex;
        cin.get();
    }

    bool checkUserIndex() {
        if (userIndex < 1 || userIndex >= objManagerNotepad->notesCounter()) {
            objUserInfoViewer->showIncorrectUserIndexError();
            return false;
        }
    }

    void userMenu() {
        for (;;) {
            objUserInfoViewer->showUserMenu();
            setUserAnswer();

            switch (userSelector) {
            case ADD_NEW_NOTE:
                objUserInfoViewer->addNewNoteText();
                objManagerNotepad->addNewNote();
                break;
            case DELETE_NOTE:
                setUserIndex();

                if (!checkUserIndex()) {
                    break;
                }

                objManagerNotepad->deleteNote(userIndex);
                break;
            case EDIT_NOTE:
                setUserIndex();

                if (!checkUserIndex()) {
                    break;
                }

                objUserInfoViewer->editNoteText();
                objManagerNotepad->editNote(userIndex);
                break;
            case SHOW_ALL_NOTES:
                objManagerNotepad->showNotes();
                break;
            case EXIT_PROGRAM:
                exit(0);
            default:
                objUserInfoViewer->showIncorrectUserSelectError();
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
