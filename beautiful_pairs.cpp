#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/beautiful-pairs/problem
 * 
 * Uses - basic problem analysis
 *
 */ 


void printMap(map<int, int> m) {
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        cout << "Key = " << it->first << " Value = " << it->second << endl;
}

int getPairwiseDisjointPairsCount(vector<int>& a, vector<int>& b )
{
    int n = a.size();
    int count = 0;
    map<int, int> ma, mb;

    for(int i = 0; i < n; i++){
    
        if(ma.find(a[i]) == ma.end()){
            ma[a[i]] = 1;
        } else {
            ma[a[i]]++;
        }
        
        if(mb.find(b[i]) == mb.end()){
            mb[b[i]] = 1;
        } else {
            mb[b[i]]++;
        }
            
    }
    
    //printMap(ma);
    //printMap(mb);
 
    for (int i = 0; i < n; i++){
        int x = a[i];
        int countA = (ma.find(x) == ma.end()) ? 0 : ma[x];
        int countB = (mb.find(x) == mb.end()) ? 0 : mb[x];
        int min_ab = min(countA, countB);
        if(min_ab) {
            ma[x] -= min_ab;
            mb[x] -= min_ab;
            count += min_ab;
        }
    }
    return count;
}

/*

int ma[1001], mb[1001];

int getPairwiseDisjointPairsCount(vector<int>& a, vector<int>& b )
{
    int n = a.size();
    int count = 0;
    
   for (int i = 0; i < n; i++){
        int x = a[i];
        int min_ab = min(ma[x], mb[x]);
        if(min_ab) {
            ma[x] -= min_ab;
            mb[x] -= min_ab;
            count += min_ab;
        }
    }
    return count;
}
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        //ma[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        //mb[b[i]]++;
    }
    int k = getPairwiseDisjointPairsCount(a, b);
    int ans = (k < n) ? (k + 1) : (n - 1);
    cout << ans << endl;
    
    return 0;
}
