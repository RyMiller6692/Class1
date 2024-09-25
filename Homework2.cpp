#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Player {
    string name;
    string position;
    int yards;
};

void readPlayerStats(Player players[], int size, const string& filename) {
    ifstream file(filename);
    for (int i = 0; i < size; ++i) {
        file >> players[i].name >> players[i].position >> players[i].yards;
    }
    file.close();
}

int calculateTotalYards(Player players[], int size) {
    int totalYards = 0;
    for (int i = 0; i < size; ++i) {
        totalYards += players[i].yards;
    }
    return totalYards;
}

void displayPlayerStats(Player players[], int size) {
    cout << "Player Statistics:\n";
    for (int i = 0; i < size; ++i) {
        cout << players[i].name << " (" << players[i].position << ") - "
            << players[i].yards << " yards\n";
    }
}

int main() {
    const int TEAM_SIZE = 11;  
    Player team[TEAM_SIZE];

    string filename = "nfl_team.txt";
    readPlayerStats(team, TEAM_SIZE, filename);

    int totalYards = calculateTotalYards(team, TEAM_SIZE);

    displayPlayerStats(team, TEAM_SIZE);
    cout << "\nTotal yards gained by the team: " << totalYards << " yards\n";

    return 0;
}
