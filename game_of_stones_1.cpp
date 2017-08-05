#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/game-of-stones-1/problem
 * 
 * Uses dynamic programming, game theory basics
 * 
 */ 	

const int maxN = 100;
const int numPlayers = 2;

int winner[numPlayers][maxN+1];

void initWinners(void) {
    for(int i = 0; i < numPlayers; i++){
        for(int j = 0; j <= maxN; j++){
            winner[i][j] = -1;
        }
    }
}

void initializeBaseCases(void) {
    winner[0][0] = 1;
    winner[1][0] = 0;
    winner[0][1] = 1;
    winner[1][1] = 0;
    winner[0][2] = 0;
    winner[1][2] = 1;
    winner[0][3] = 0;
    winner[1][3] = 1;
    winner[0][4] = 0;
    winner[1][4] = 1;
    winner[0][5] = 0;
    winner[1][5] = 1;
    winner[0][6] = 0;
    winner[1][6] = 1;
}

void fillWinners() {
    initializeBaseCases();
    for(int ns = 7; ns <= maxN; ns++){
        for(int p = 0; p < 2; p++) {
            int x, y, z;
            x = winner[1-p][ns-2];
            y = winner[1-p][ns-3];
            z = winner[1-p][ns-5];
            if((x == p) || (y == p) || (z == p))
                winner[p][ns] = p;
            else
                winner[p][ns] = 1-p;
        }
    }
    
}

int main() {
    initWinners();
    fillWinners();
    int t;
    cin  >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = winner[0][n];
        if(!ans)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}
