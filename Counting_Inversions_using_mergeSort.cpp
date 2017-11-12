#include <bits/stdc++.h>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/ctci-merge-sort/problem
 */

#define INF 10000007

//sorted sub-arrays to merge are: A[ls..le] and  A[le+1..re]
long merge(int a[], int ls, int le, int re) {

    int nl = le - ls + 1;
    int nr = re - le;
    if(nl <= 0 || nr <= 0) return 0;

    int L[nl], R[nr], i, j, k;
    for(i = 0; i < nl; i++)
        L[i] = a[ls+i];
    for(i = 0; i < nr; i++)
        R[i] = a[le+1+i];
    L[nl] = R[nr] = INF;
    //const int infinity = max(a[le], a[re]) + 1;

    long count = 0;
    i = j = 0;
    for(k = ls; k <= re; k++) {
        if(L[i] <= R[j]) {
            a[k] = L[i++];
        } else {
            if(L[i] != INF)
               count += (long)(nl - i); //note: this is due to not-so-routine implementation followed here.
            /*
             * number of inversios with second index element as j is = number of remaining elements in first/left array - including
             * current one (pointed by index i).
             * so count needs to be incremented by - (nl - i) [i elements of L are already processed before this iteration.]
             */
            a[k] = R[j++];
        }
    }
    return count;
}

long _countInversions(int a[], int s, int e) {
    if(s < e) {
        int m = (s+e)/2;
        long count = _countInversions(a, s, m);
        count += _countInversions(a, m+1, e);
        count += merge(a, s, m, e);
        return count;
    }
    return 0L;
}


long countInversions(int arr[], int n) {
    return _countInversions(arr, 0, n-1);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int arr[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = countInversions(arr, n);
        cout << result << endl;
    }
    return 0;
}
