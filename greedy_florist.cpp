#include <bits/stdc++.h>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/greedy-florist/problem
 * 
 * Uses greedy approach
 * 
 */ 

int getMinimumCost(int n, int k, vector < int > c){
    sort(c.begin(), c.end());
    int repetition = 0;
    int boughtSoFar = 0;
    int cost = 0;
    int curFlower = n-1;
    while (boughtSoFar < n) {
        for(int customer = 0; (boughtSoFar < n) && (customer < k); customer++){
                   cost += (repetition + 1)*c[curFlower--];
                   boughtSoFar++;
        }
        repetition++;
    }
    return cost;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}
