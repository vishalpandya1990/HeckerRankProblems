#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/kundu-and-tree/problem
 */

typedef long long ll;

const ll mod = 1000000007;

ll binomialCoeff(ll n, ll k)
{
    if(n < k) return 0;
    ll C[n+1][k+1];
    ll i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}

struct component {
   ll parent;
};

ll getRoot(component c[], ll n, ll idx) {
    ll i = idx;
    while((i >= 0) && (i < n) && (c[i].parent >= 0)) {
        i = c[i].parent;
    }
    return i;
}

void merge(component c[], ll ra, ll rb) {
    ll sizeA = -(c[ra].parent);
    ll sizeB = -(c[rb].parent);
    if(sizeA < sizeB) {
        c[ra].parent = rb;
        c[rb].parent = -(sizeA + sizeB);
    } else {
        c[rb].parent = ra;
        c[ra].parent = -(sizeA + sizeB);
    }
}

int main() {
    ll n, i, u, v;
    char ch;
    cin >> n;
    component c[n];
    for(i = 0; i < n; i++) {
        c[i].parent = -1;
    }
    for(i = 0; i < n-1; i++) {
        cin >> u >> v >> ch;
        if(ch == 'b') {
            ll rootA = getRoot(c, n, u-1);
            ll rootB = getRoot(c, n, v-1);
            if(rootA != rootB) {
                  merge(c, rootA, rootB);
            }
        }
    }

    ll ans = binomialCoeff(n, 3);
    for(i = 0; i < n; i++) {
        ll sz = -(c[i].parent);
        if((c[i].parent < 0)&&(sz > 1)) {
           ans -= binomialCoeff(sz, 3);
           ans -= binomialCoeff(sz, 2) * (n - sz);
        }
    }
    cout  << ans%mod << endl;
    return 0;
}
