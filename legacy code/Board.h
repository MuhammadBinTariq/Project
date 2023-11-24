#include <iostream>
#include <iomanip>

using namespace std;



// Prepares and displays the board
void initializeBoard(int* elements, int boardSize) {

    cout << "\n";

    for(int i {1}; i <= boardSize; i++) {

        if(i == 1) {

            cout << "\t\b" << i;

        }
        else {

            cout << "           " << i;

        }

    }

    cout << "\n";

    for (int i {0}; i < boardSize; i++) {
        
        for (int j {0}; j < boardSize; j++) {
            
            cout << "   +------+ ";
        
        }

        cout << '\n';

        for (int j {0}; j < boardSize; j++) {
            
            cout << "   |      | ";
        
        }

        cout << "\n";

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   |      | ";
        
        }

        cout << '\n';

        for (int j {0}; j < boardSize; j++) {
            
            if(j == 0) {

                cout << " " << i + 1;

            }
            else {

                cout << "  ";

            }

            cout << " |  " << setw(2) << setfill(' ') << *((elements + (i * boardSize)) + j) << "  | ";
        
        }

        cout << '\n';

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   |      | ";
        
        }

        cout << "\n";

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   |      | ";
        
        }

        cout << '\n';

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   +------+ ";
        
        }

        cout << '\n';
    }

}

// Fills the board according to the difficulty selected
void fillBoardArray(int* elements, int dimensions) {

    for(int i {0}; i < dimensions; i += 2) {

        *(elements + i) = (i + 1);
        *(elements + i + 1) = *(elements + i);

    }

}

// Randomly shuffles the elements of the board game
void randomIndexSwaps(int* elements, int indexLimit) {

    int temporaryValue {0};
    int randomIndex {0};

    srand(time(0));

    for(int i{0}; i < indexLimit; i++) {

        temporaryValue = *(elements + i);
        randomIndex = rand() % indexLimit;
        *(elements + i) = *(elements + randomIndex);
        *(elements + randomIndex) = temporaryValue;

    }

}

/* int board_printer() 
{
    int symarr[9] = {1,2,9,3,4,5,6,7,8};
    int *p = symarr;
    int dim = 2;

    for (int i = 0; i <  dim; ++i) 
    {
        for (int j = 0; j <  dim; ++j) 
        {
            cout << "+-----+ ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "|     | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "| " << setw(2) << *((p+i*dim)+j) << "  | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "|     | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "+-----+ ";
        }

        cout << '\n';
    }

    return 0;
} */