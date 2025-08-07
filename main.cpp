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
