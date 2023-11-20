#include <iostream>
#include <string>
#include <windows.h>
#include <cwchar>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void initializeBoard() {

    int ROWS {4};
    int COLUMNS {4};

    int board[ROWS][COLUMNS];
    srand(time(0));

    for(int i {0}; i < ROWS; i++) {

        for(int j {0}; j < COLUMNS; j++) {

            board[i][j] = rand() % 8 + 1;
            cout << board[i][j];

        }

        cout << endl;

    }    

}

void playerMenu() {

    string tagName {" "};
    int gameCondition {0};

    // system("Color 04");

    cout << "Welcome to Memoir - The Card Game" << endl;

    cout << "Enter your player tag: ";
    cin >> tagName;

    // system("Color 0A");

    cout << "Greetings " << tagName << "!" << endl;
    cout << "Press (1) to start a new game or (0) to quit: ";
    cin >> gameCondition;

    initializeBoard();

}

int main() {

    cout << "\5";

    return 0;

}