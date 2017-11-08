#include <iostream>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/contests/w6/challenges/consecutive-subsequences
 */

int main() {
    long t, n, k, i;
    cin >> t;
    while(t--) {
      cin >> n >> k;
      int a[n];
      long long p[n], f[k] = {0}, count = 0;
      for(i = 0; i < n; i++) {
         cin >> a[i];
         if(i) {
             p[i] = p[i-1] + a[i];
         } else {
             p[i] = a[i];
         }
         int r = p[i]%k;
         int x = f[r];
         count += x;
         f[p[i]%k]++;
      }
      count += f[0];
      cout << count << endl;
    }
    return 0;
}
