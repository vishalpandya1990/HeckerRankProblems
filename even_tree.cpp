#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * https://www.hackerrank.com/challenges/even-tree/problem
 *
 * Uses basic graph traversal.
 */ 

int N, subtreeSize[105];
vector<int> adj[105];

void ComputeSizes(int u, int p) {
    subtreeSize[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            ComputeSizes(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
}

int main() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ComputeSizes(0, -1);
    int ans = 0;
    for (int i = 1; i < N; ++i)
        if (subtreeSize[i] % 2 == 0)
            ans += 1;
    cout << ans << endl;
    return 0;
}
