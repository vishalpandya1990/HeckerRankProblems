#include <bits/stdc++.h>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/largest-rectangle/problem
 */

long largestRectangle(vector<int> h) {
    h.push_back(0);
    vector<int>s;
    long i = 0, n = h.size();
    long max = -1;
    while(i < n) {
        while(s.size() > 0 && h[s.back()] >= h[i]) {
            long ht = h[s.back()];
            s.pop_back();
            long rse = i;
            long lse = s.size() > 0 ? s.back() : -1;
            long curArea = ht * (rse - lse - 1);
            if(max < curArea)
                max = curArea;
        }
        s.push_back(i);
        i++;
    }

    return max;
}

long largestRectangle1(vector <int> h) {
    // assuming non-negative heights.
    long i = 0, n = h.size();
    long ls[n+1], ltop = -1, lse[n] = {0};
    while(i < n) {
       while(ltop >= 0 && h[ls[ltop]] >= h[i]) ltop--;
       if(ltop < 0)
          lse[i]  = -1;
       else
          lse[i] = ls[ltop];
       ls[++ltop] = i;
       i++;
    }

    long rse[n] = {0}, rs[n+1], rtop = -1;
    i = n-1;
    while(i >= 0) {
        while(rtop >= 0 && h[rs[rtop]] >= h[i]) rtop--;
        if(rtop < 0)
            rse[i] = -1;
        else
            rse[i] = rs[rtop];
        rs[++rtop] = i;
        i--;
    }
    long max = -1;
    for(i = 0; i < n; i++) {
        long ln = i - lse[i];
        long rn = (rse[i] >= 0 ? rse[i]  : n) - i;
        long curArea = (ln + rn -1)*h[i];
        if(curArea > max) max = curArea;
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}
