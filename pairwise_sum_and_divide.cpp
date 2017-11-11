#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/pairwise-sum-and-divide/problem
 */

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll n, t, res, c1, c2, i;
    cin >> t;
    while(t--) {
        cin >> n;
        ll a[n];
        res = c1 = c2 = 0;
        for(i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) c1++;
            if(a[i] == 2) c2++;
        }
        res += c1*(n-1);
        res += c2*(c2-1)/2;
        //res = 2*(c1*(c1-1)/2) + c1*(n-c1) + c2*(c2-1)/2
        cout << res << endl;

    }


    return 0;
}
