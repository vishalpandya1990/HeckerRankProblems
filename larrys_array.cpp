#include <vector>
#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/larrys-array/problem
 * 
 * Uses knowledge of inversions in array
 * 
 */

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int countOfInitialInversions = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[i] > arr[j]) countOfInitialInversions++;
            }
        }
        cout << (countOfInitialInversions % 2  ? "NO" : "YES") << endl;
        
    }
    return 0;
}
