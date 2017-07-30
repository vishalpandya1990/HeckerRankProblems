#include <bits/stdc++.h>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/sum-vs-xor/problem
 * 
 * Uses :- Basic Maths, and Xor as restricted binary addition.
 * 
 */

long solve(long n) {
   int numZeroes = 0;
    while(n > 0){
        if((n&1) == 0) numZeroes++;
        n >>= 1;
    }
    return (1L << numZeroes);
}

int main() {
    long n;
    cin >> n;
    long result = solve(n);
    cout << result << endl;
    return 0;
}
