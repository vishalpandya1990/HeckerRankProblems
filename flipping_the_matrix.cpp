#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/flipping-the-matrix/problem
 * 
 * It uses analysis of matrix algebra for given set of permissible operations, and greedy approach.
 */

int maxOf4(int a, int b, int c, int d){
    int max1 = max(a, b);
    int max2 = max(c, d);
    return max(max1, max2);
}

int main() { 
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(2*n, vector<int>(2*n,0));
        for(int i = 0; i < 2*n; i++){
              for(int j = 0; j < 2*n; j++)
                  cin >> arr[i][j];
        }
        int sum = 0;
        int twoN = 2*n;
        for(int i  = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 sum += maxOf4(arr[i][j], arr[i][twoN-1-j], arr[twoN-1-i][j], arr[twoN-1-i][twoN-1-j]);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
