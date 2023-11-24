#include <iostream>

using namespace std;

void initializeBoard(int* elements, int boardSize) {

    for(int i {0}; i < boardSize; i += 2) {

        *(elements + i) = (i + 1);
        cout << *(elements + i) << " ";
        *(elements + i + 1) = *(elements + i);
        cout << *(elements + i + 1) << " ";

    }

    cout << "\n";

    for(int i {0}; i < 4; i++) {

        for(int j {0}; j < 4; j++) {

            cout << *((elements + (i * 4)) + j) << " ";

        }

        cout << "\n";

    }

}

int main() {

    int cardElements[64];
    initializeBoard(cardElements, 16);

    return 0;

}