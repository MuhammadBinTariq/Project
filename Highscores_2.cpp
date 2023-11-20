#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_PLAYERS = 100;
int current_players;
string players[MAX_PLAYERS][2];

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

/*THE FOLLOWING SHOULD ONLY BE USED AFTER THE FILE HAS BEEN READ*/

void displayScores() 
{
    ifstream file("scores.txt");

    cout << "\n\t _____\t\t\t\t\t\t\t\t\t_____";
    cout << "\n\t|A .  | _____\t\t\t\t\t\t\t _____ |  . A|";
    cout << "\n\t| /.\\ ||A ^  | _____\t\t\t\t\t  _____ |  ^ A|| /.\\ |";
    cout << "\n\t|(_._)|| / \\ ||A _  | _____\t\t\t   _____ |  _ A|| / \\ ||(_._)|"; 
    cout << "\n\t|  |  || \\ / || ( ) ||A_ _ |\t\t\t  | _ _A|| ( ) || \\ / ||  |  |";
    cout << "\n\t|____V||  .  ||(_'_)||( v )|\t\t\t  |( v )||(_'_)||  .  ||V____|";
    cout << "\n\t\t\b|____V||  |  || \\ / |\t Leaderboard\t  | \\ / ||  |  ||V____|";
    cout << "\n\t\t\t\b\b|____V||  .  |\t\t\t  |  .  ||V____|";
    cout << "\n\t\t\t\t\b\b\b|____V|\t\t\t  |V____|\n\n";

    for (int i = 0; !players[i][0].empty(); i++) 
    {
        cout << "\t\t\t\t\t"<< i+1 << ". " << players[i][0] << ": " << players[i][1] << endl;
    }
    
    file.close();
}

void updateScores(string name, string score) 
{
    players[current_players][0] = name;
    players[current_players][1] = score;

    current_players++;

    ofstream file("scores.txt");

    file << current_players << endl;

    for (int i = 0; i < current_players; i++) 
    {
        file << players[i][0] << " " << players[i][1] << endl;
    }

    file.close();
}

int main() 
{
    readScores();

    displayScores();

    string name, score;
    for(int i = 0; i < 5; i++)
    {
    cout << "Enter a new player's name and score: ";
    cin >> name >> score;
    updateScores(name, score);
    }

    return 0;
}
