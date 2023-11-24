#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "color_console.hpp"

using namespace std;

void playerMenu();
bool gameRules();

void playerMenu() {

    int userChoice {0};

    cout << "\n" << setfill('*') << setw(95) << "*\n";

    cout << "\n\t\t\t\t\b\b" << console.get("Welcome to Memoir - The Card Game!", { console.blue, console.bold, console.underline });

    cout << "\n\t _____\t\t\t\t\t\t\t\t\t_____";
    cout << "\n\t|A .  | _____\t\t\t\t\t\t\t _____ |  . A|";
    cout << "\n\t| /.\\ ||A ^  | _____\t\t\t\t\t  _____ |  ^ A|| /.\\ |";
    cout << "\n\t|(_._)|| / \\ ||A _  | _____\t\t\t   _____ |  _ A|| / \\ ||(_._)|"; 
    cout << "\n\t|  |  || \\ / || ( ) ||A_ _ |\t\t\t  | _ _A|| ( ) || \\ / ||  |  |";
    cout << "\n\t|____V||  .  ||(_'_)||( v )|\t\t\t  |( v )||(_'_)||  .  ||V____|";
    cout << "\n\t\t\b|____V||  |  || \\ / |\t\t\t  | \\ / ||  |  ||V____|";
    cout << "\n\t\t\t\b\b|____V||  .  |\t\t\t  |  .  ||V____|";
    cout << "\n\t\t\t\t\b\b\b|____V|\t\t\t  |V____|";

    cout << "\n\n\t\t\t\t\t\b\b\b" << console.get("1. New Game\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("2. Rules of Memoir\n", { console.green });
    cout << "\n\t\t\t\t\t\b\b\b" << console.get("3. Quit Game\n", { console.green });
    
    do {

        cout << console.get("\n\t\t\t\tEnter the corresponding number: ", { console.red });
        cin >> userChoice;

    }while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 19);

    system("CLS");

    switch(userChoice) {

        case 1:
            
            // Calls difficulty & Board game
            break;

        case 2:
            
            if(gameRules()) {

                system("CLS");
                // Calls difficulty & Board game

            }
            else {

                system("CLS");
                playerMenu();   // Returns to game menu after rules

            }

            break;

        case 3:

            break;

        case 19:
            
            system("curl parrot.live");     // Easter Egg
            break;

    }

}

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

int main() {

    playerMenu();

    return 0;

}