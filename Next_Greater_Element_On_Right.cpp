#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
 */

#define UNDEFINED 700000

void nextGreaterElement_stackBased(int a[], int res[], int n){
    int s[n+1], top = 0, i;
    s[0] = UNDEFINED;
    for(i = n-1; i >= 0; i--) {
        while(top >= 0 && s[top] <= a[i]) top--;
        res[i] = s[top];
        s[++top] = a[i];
    }
}

void printResult(int res[], int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(res[i] == UNDEFINED) res[i] = -1;
        cout <<  a[i] << " " << res[i] << endl;
    }
}

int main() {
    int n, i;
    cin >> n;
    int a[n], res[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    nextGreaterElement_stackBased(a, res, n);
    printResult(res, a, n);
    return 0;
}
