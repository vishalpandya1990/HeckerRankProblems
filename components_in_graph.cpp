#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/components-in-graph/problem
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
    ll sizea = -(c[ra].parent);
    ll sizeb = -(c[rb].parent);
    if(sizea < sizeb) {
        c[ra].parent = rb;
        c[rb].parent = -(sizea + sizeb);
    } else {
        c[rb].parent = ra;
        c[ra].parent = -(sizea + sizeb);
    }
}

int main() {
    ll n, a, b, i;
    cin >> n;
    component c[2*n];
    for(i = 0; i < 2*n; i++) {
        c[i].parent = -1;
    }
    for(i = 0; i < n; i++) {
        cin >> a >> b;
        ll ra = getRoot(c, 2*n, a-1);
        ll rb = getRoot(c, 2*n, b-1);
        if(ra != rb) {
            merge(c, ra, rb);
        }

    }
    ll min = 2*n + 1, max = -1;
    for(i = 0; i < 2*n; i++) {
        if(c[i].parent < 0) {
            ll size = -(c[i].parent);
            if((size > 1) && (size < min)) {
                min = size;
            }
            if((size > 1) && (size > max)) {
                max = size;
            }
        }
    }
    cout << min << " " << max << "\n";
    return 0;
}
