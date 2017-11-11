#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/maximum-cost-queries/problem
 */

typedef long long ll;

struct edge {
    ll u, v, w;
};

int compareByWt(const void *a, const void *b) {
   edge *e1 = (edge *)a;
   edge *e2 = (edge *)b;
   return e1->w - e2->w;
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

ll merge(component c[], ll ra, ll rb) {
    ll sizeA = -(c[ra].parent);
    ll sizeB = -(c[rb].parent);
    if(sizeA < sizeB) {
        c[ra].parent = rb;
        c[rb].parent = -(sizeA + sizeB);
    } else {
        c[rb].parent = ra;
        c[ra].parent = -(sizeA + sizeB);
    }
    return sizeA * sizeB;
}

int main() {
    ll n, q, i, u, v, w;
    cin >> n >> q;
    component c[n];
    for(i = 0; i < n; i++) {
        c[i].parent = -1;
    }
    edge edges[n-1];
    i = 0;
    while(i < n-1) {
        cin >> u >> v >> w;
        edges[i].u = u-1;
        edges[i].v = v-1;
        edges[i].w = w;
        i++;
    }
    qsort(edges, n-1, sizeof(edge), compareByWt);
    vector<ll> lengths, pathCount;
    lengths.push_back(0);
    pathCount.push_back(0);
    for(i = 0; i < n-1; i++) {
        ll ra = getRoot(c, n, edges[i].u);
        ll rb = getRoot(c, n, edges[i].v);
        if(ra != rb) {
            lengths.push_back(edges[i].w);
            ll lessThanPathCount = pathCount.back();
            ll newPaths = merge(c, ra, rb);
            pathCount.push_back(lessThanPathCount + newPaths);
        }
    }

    /*
      ll nn = lengths.size();
      for(i = 0; i < nn; i++) {
          cout << "-- " << lengths[i] << " " << pathCount[i] << endl;
      }
    */

    for(i = 0; i < q; i++) {
        ll l, r, lowpos, uppos, res = 0;
        cin >> l >> r;
        vector<ll>::iterator low, up;
        low = lower_bound(lengths.begin(), lengths.end(), l);   // first element >= length l
        up  = lower_bound(lengths.begin(), lengths.end(), r+1); // first element >= length r+1
        uppos = up - lengths.begin() - 1;   // last element <= r
        lowpos = low - lengths.begin() - 1; // last element <  l
        if(low != lengths.end()) {
             ll tt = pathCount[uppos], bb = 0;
             if(low != lengths.begin()) {
                bb = pathCount[lowpos];
             }
             res = tt - bb;
        }
        cout << res << endl;
    }

    return 0;
}
