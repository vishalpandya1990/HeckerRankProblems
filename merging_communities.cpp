#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/merging-communities/problem
 */


typedef long long ll;

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
    ll n, q, i, a, b;
    char f;
    cin >> n >> q;
    component c[n];
    for(i = 0; i < n; i++) {
        c[i].parent = -1;
    }
    while(q--) {
        cin >> f;
        if(f == 'M') {
            cin >> a >> b;
            ll rootA = getRoot(c, n, a-1);
            ll rootB = getRoot(c, n, b-1);
            if(rootA != rootB) {
                  merge(c, rootA, rootB);
            }
        } else {
            cin >> a;
            ll root = getRoot(c, n, a-1);
            cout << -(c[root].parent) << endl;
        }
    }
    return 0;
}
