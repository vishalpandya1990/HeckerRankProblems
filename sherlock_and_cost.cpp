#include <iostream>
#include <vector>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/sherlock-and-cost/problem
 * 
 * Compenents used :- Arrays + Dynamic Programming
 */

int main() {
    int t;
    cin >> t;
    while(t--){
		int n, i;
		cin >> n;
		vector<int> b(n);
		vector<vector<int>> solution(n, vector<int>(2, 0));
		for(i = 0; i < n; i++)
		  cin >> b[i];
		for(i = 1; i < n; i++){
		   solution[i][0] = max(solution[i-1][0], solution[i-1][1] + abs(1-b[i-1]));
		   solution[i][1] = max(solution[i-1][0] + abs(b[i]-1), solution[i-1][1]+abs(b[i]-b[i-1]));
		}
		cout << max(solution[n-1][0], solution[n-1][1]) << endl;
	}
    	
	return 0;
}

