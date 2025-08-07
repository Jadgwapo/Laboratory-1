# include <iostream>
# include <direct.h>
#include <windows.h>
#include <string>

using namespace std;

void showMenu();
void listFiles();
void createDirectory();
void changeDirectory();

int main () {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                listFiles ();
                break;
            case 2:
                createDirectory();
                break;
            case 3: 
                changeDirectory();
                break;
            case 4:
                cout << "Existing program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
            system("pause");
            system("cls");
    }      while (choice != 4);
            return 0;

}
void showMenu() {
    cout << "=== Directory Management System ===\n";
    cout << "[1] List Files\n";
    cout << "[2] Create Directory\n";
    cout << "[3] Change Directory\n";
    cout << "[4] Exit\n";
}
void listFiles() {
    cout << "\nFiles in current directory: \n";
    system("dir");
}
void createDirectory() {
    string folderName;
    cout << "Enter directory name: ";
    cin >> folderName;

    int result = _mkdir(folderNmae.c_str());
    if (result == 0){
        cout << "Directory \"" << folderName << "\" created successfully. \n";
    } else {
        cout << "Error: Directory might already exist. \n";
    }   
}
void changeDirectory() {
    int option;
    string path;

    cout << "[1] Move to Parent Directory\n";
    cout << "[2] Move to Root Directory\n";
    cout << "[3] Enter Custom Path\n";
    cout << "Enter your choice: ";
    cin >> option;
    cin.ignore();

    if (option == 1){
        SetCurrentDirectory("..");
    } else if (option == 2) {
        char rootPath[MAX_PATH];

        GetCurrentDirectory(MAX_PATH, rootPath);
        rootPath[3] ='\0';

        SetCurrentDirectory(rootPath);
    } else if (option == 3) {
        cout << "Enter path: ";
        getline(cin, path);
        if (!SetCurrentDirectory(path.c_str())) {
            cout << "Error: Path not found!\n";
            return;
        }
    } else {
        cout << "Invalid choice!\n";
        return;
    }
    char currentPath[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, currentPath);
    cout << "Current directory changed to: " << currentPath << endl;
}

