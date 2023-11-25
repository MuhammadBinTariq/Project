#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <ctime>

#include <Windows.h>
#include <fstream>

#include "color_console.hpp"

using namespace std;




// Declaration of all constant
bool card_state[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
string array_four[64] = {"A","A","B","B","C","C","D","D","E","E","F","F","G","G","H","H","I","I","J","J","K","K","L","L","M","M","N","N","O","O","P","P","Q","Q","R","R","S","S","T","T","U","U","V","V","W","W","X","X","Y","Y","Z","Z","!","!","@","@","#","#","$","$","%","%","&","&"};





// Declaration of all called functions
void playerMenu();
bool gameRules();
int gameDifficulty();
void initializeBoard(int* elements, int boardSize);
void randomIndexSwaps(int* elements, int indexLimit);




/*
    DECORATIONS
*/

void designPrinter()
{
    cout << "\n\t _____\t\t\t\t\t\t\t\t\t_____";
    cout << "\n\t|A .  | _____\t\t\t\t\t\t\t _____ |  . A|";
    cout << "\n\t| /.\\ ||A ^  | _____\t\t\t\t\t  _____ |  ^ A|| /.\\ |";
    cout << "\n\t|(_._)|| / \\ ||A _  | _____\t\t\t   _____ |  _ A|| / \\ ||(_._)|"; 
    cout << "\n\t|  |  || \\ / || ( ) ||A_ _ |\t\t\t  | _ _A|| ( ) || \\ / ||  |  |";
    cout << "\n\t|____V||  .  ||(_'_)||( v )|\t\t\t  |( v )||(_'_)||  .  ||V____|";
    cout << "\n\t\t\b|____V||  |  || \\ / |\t\t\t  | \\ / ||  |  ||V____|";
    cout << "\n\t\t\t\b\b|____V||  .  |\t\t\t  |  .  ||V____|";
    cout << "\n\t\t\t\t\b\b\b|____V|\t\t\t  |V____|\n\n";
}





/*
    Highscore
*/

const int MAX_PLAYERS = 100;
string players[MAX_PLAYERS][2];

int current_players;

void readScores() 
{
    ifstream file("scores.txt");

    file >> current_players;
    
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        file >> players[i][0] >> players[i][1];
    }

    file.close();

}

void displayScores() 
{
    readScores();
    designPrinter();


    for (int i = 0; i < current_players-1; i++) 
    {     
        for (int j = 0; j < current_players-i-1; j++) 
        { 
            if (stoi(players[j][1]) < stoi(players[j+1][1])) 
            {
                swap(players[j][0], players[j+1][0]);
                swap(players[j][1], players[j+1][1]);
            }
        }
    } 

    for (int i = 0; !players[i][0].empty(); i++) 
    {
        cout << "\t\t\t\t\t"<< i+1 << ". " << players[i][0] << ": " << players[i][1] << endl;
    }
    
}

void updateScores(string name, int score) 
{
    readScores();

    players[current_players][0] = name;
    players[current_players][1] = to_string(score);

    current_players++;

    ofstream file("scores.txt");

    file << current_players << endl;

    for (int i = 0; i < current_players; i++) 
    {
        file << players[i][0] << " " << players[i][1] << endl;
    }

    file.close();
}





/*
    Board
*/

// Randomly shuffles the elements of the board game
void randomIndexSwaps(string* elements, int indexLimit) {

    string temporaryValue {""};
    int randomIndex {0};


    srand(time(0));

    for(int i{0}; i < indexLimit; i++) {

        temporaryValue = *(elements + i);
        randomIndex = rand() % indexLimit;
        *(elements + i) = *(elements + randomIndex);
        *(elements + randomIndex) = temporaryValue;

    }

}

void boardPrinter(string* elements, bool* state, int boardSize, int score, int streak) 
{

    cout << "\n";

    for(int i {1}; i <= boardSize; i++) {

        if(i == 1) {

            cout << "\t\b\b" << i;

        }
        else {

            cout << "          " << i;

        }

    }

    cout << "\n";

    for (int i {0}; i < boardSize; i++) {
        
        for (int j {0}; j < boardSize; j++) {
            
            cout << "   +-----+ ";
        
        }

        cout << '\n';

        for (int j {0}; j < boardSize; j++) {
            
            cout << "   |     | ";
        
        }


        cout << '\n';

        for (int j {0}; j < boardSize; j++) {
            
            if(j == 0) {

                char c = 'A'+i;
                cout << " " << c ;

            }
            else {

                cout << "  ";

            }

            cout << " |  ";

            if(*((state + (i * boardSize)) + j))
            {
                cout << *((elements + (i * boardSize)) + j);
            }
            else
            {
                cout << "*";
            }
            cout << "  | ";
        
        }

        cout << '\n';

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   |     | ";
        
        }


        cout << '\n';

        for (int j = 0; j < boardSize; j++) {
            
            cout << "   +-----+ ";
        
        }

        cout << '\n';
    }

    cout << "\n\nScore: " << score << endl;
    cout << "Streak: x" << streak-1 << endl;

}

int userInput(bool* state, int boardSize)
{
    int coords_x;
    char coords_y;

    cout << "\n\nEnter the x coordinates: ";
    cin >> coords_x;
    cout << "\n\nEnter the y coordinates: ";
    cin >> coords_y;

    coords_y = toupper(coords_y);

    *((card_state + ( (coords_y-'A')* boardSize)) + (coords_x-1)) = true;

    return  ((coords_y-'A')* boardSize + (coords_x-1));
}

// Prepares and displays the board
void initializeBoard(string* elements, bool* card_state, int boardSize) 
{
    bool game_state = true;
    int match_count = 0;
    int streak_history = 1;
    int current_match[2];

    string player_name;
    int player_score = 100;

    randomIndexSwaps(elements, boardSize*boardSize);

    cout << "\nEnter your name:";
    cin >> player_name;


    while (game_state)
    {
        system("CLS");
        boardPrinter(elements, card_state, boardSize, player_score, streak_history);
        for(int i = 0; i < 2; i++)
        {
            current_match[i] = userInput(card_state, boardSize);
            system("CLS");
            boardPrinter(elements, card_state, boardSize, player_score, streak_history);
        }
        
        if(elements[current_match[0]]==elements[current_match[1]])
        {
            match_count++;
            streak_history += 1;
            player_score += 5*streak_history;
        }
        else
        {
            card_state[current_match[0]] = false;
            card_state[current_match[1]] = false;
            streak_history = 1;
            player_score -= 1;
        }
        
        if(match_count==(boardSize*boardSize/2))
        {
            updateScores(player_name, player_score);
            game_state = false;
            designPrinter();
            cout << "\t\t\t\t\t\t Game won!";
            Sleep(5000);
            break;
        }
        else if(player_score < 0)
        {
            updateScores(player_name, player_score);
            game_state = false;
            designPrinter();
            cout << "\t\t\t\t\t\t Game lost!";
            Sleep(5000);
            break;
        }
        
        Sleep(5000);
        system("CLS"); 
    }
    system("CLS"); 
}





/* 
    MENU ELEMENTS
*/

// Displays user menu
void playerMenu() {

    int userChoice {0};
    int sizeOfBoard {0};

    cout << "\n" << setfill('*') << setw(95) << "*\n";

    cout << "\n\t\t\t\t\b\b" << console.get("Welcome to Memoir - The Card Game!", { console.green, console.bold, console.underline });

    designPrinter();

    cout << "\n\n\t\t\t\t\t\b\b\b" << console.get("1. New Game\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("2. Rules of Memoir\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("3. Leaderboard\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("4. Quit Game\n", { console.green });
    
    do {

        cout << console.get("\n\t\t\t\tEnter the corresponding number: ", { console.white });
        cin >> userChoice;

    }while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 19);

    system("CLS");

    switch(userChoice) {

        case 1:
            
            sizeOfBoard = gameDifficulty();
            initializeBoard(array_four, card_state, sizeOfBoard);
            break;

        case 2:
            
            if(gameRules()) {

                system("CLS");
                sizeOfBoard = gameDifficulty();
                initializeBoard(array_four, card_state, sizeOfBoard);

            }
            else {

                system("CLS");
                playerMenu();   // Returns to game menu after rules

            }

            break;
        
        case 3:
            system("CLS");
            displayScores();
        case 4:

            return;
            break;

        case 19:
            
            system("curl parrot.live");     // Easter Egg
            break;

    }

}

// Determines game mode difficulty
int gameDifficulty() {

    int difficultyChosen {0};

    cout << "\n" << setfill('*') << setw(95) << "*\n";
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("Select Difficulty:\n", { console.blue, console.bold, console.underline });
    cout << "\n\n\t\t\t\t\t\b\b\b" << console.get("1. Easy 4x4 Game\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("2. Medium 6x6 Game\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("3. Hard 8x8 Game\n", { console.green });
    
    do {

        cout << console.get("\n\t\t\t\tEnter the corresponding number: ", { console.white });
        cin >> difficultyChosen;

    }while(difficultyChosen != 1 && difficultyChosen != 2 && difficultyChosen != 3);

    switch(difficultyChosen) {

        case 1:

            difficultyChosen = 4;
            break;

        case 2:

            difficultyChosen = 6;
            break;

        case 3:

            difficultyChosen = 8;
            break;

    }

    system("CLS");

    return difficultyChosen;

}

// Displays game rules for a first time player
bool gameRules() {

    int input {0};

    cout << "\n" << setfill('*') << setw(95) << "*\n";

    cout << "\nDo you dream to have your name in the annals of history? Memoir gives you that chance - but\n";
    cout << "in the records of your own memory :D\n";
    cout << "\nA simple game (I mean it! Or do I? *Cue Vsauce music*). A test of your memory. The rules are\nas follows:\n";
    
    cout << "\nObjective: The goal is to match pairs of cards with the same rank/symbol/set/style.\n";
    
    cout << "\nGameplay:\n";
    cout << "\t \6 Players take turns flipping over two cards\n";
    cout << "\t \5 If the two cards match, they remain upright and the player takes another turn\n";
    cout << "\t \4 If the cards do not match, the player flips them back face down\n";
    cout << "\t \3 The game continues until all pairs have been matched\n";

    cout << "\nDo you have what it takes to imprint your mark in the Memoir? The key to success is your memory...\n";
    
    do{

        cout << "\nEnter (1) to begin Memoir, or (0) to return to menu: ";
        cin >> input;

    }while(input != 0 && input != 1);

    if(input)
        return true;
    
    return false;

}



// ehe good ol' main
int main() {

    playerMenu();

    return 0;

}