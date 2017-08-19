#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/two-pluses/problem
 * 
 * Uses basic problem solving and brute-force approach
 * 
 */ 


#define DEBUG1 0
#define DEBUG2 0

int  n, m;
char grid[16][16];
int  myMax[16][16];

typedef struct _cell{
   int x, y;
}cell;

bool hasCell(vector<cell>& v, cell &c) {
    for(vector<cell>::iterator it = v.begin(); it != v.end(); it++) {
        if(((*it).x == c.x) && ((*it).y == c.y)) return true;
    }
    return false;
}

bool doOverlap(vector<cell> &f, vector<cell> &s) {
    for(vector<cell>::iterator it = f.begin(); it != f.end(); it++){
        if(hasCell(s, *it)) return true;
    }
    return false;
}

int getHorizontalLength(int i, int j){
    int l = 0, r = 0;
    int cur = j+1;
    while(cur < m && grid[i][cur] == 'G')
        cur++;
    r = cur - j - 1;
    
    cur = j-1;
    while(cur >= 0 && grid[i][cur] == 'G')
        cur--;
    l = j - cur - 1;
    int m = min(l, r);
    #if DEBUG1
    cout << "i = " << i << " j = " << j << " HL = " << (1 + 2*m) << endl;
    #endif
    return (2*m + 1);
}

int getVerticalLength(int i, int j){
    int b = 0, u = 0;
    int cur = i+1;
    while(cur < n && grid[cur][j] == 'G')
        cur++;
    b = cur - i - 1;
    
    cur = i-1;
    while(cur >= 0 && grid[cur][j] == 'G')
        cur--;
    u = i - cur - 1;
    int m = min(b, u);
    #if DEBUG1
    cout << "i = " << i << " j = " << j << " VL = " << (1 + 2*m) << endl;
    #endif
    return (2*m + 1);
}

int getMaxAreaForThisCenter(int i, int j){
    if(grid[i][j] != 'G') return 0;
    int x = getHorizontalLength(i, j);
    int y = getVerticalLength(i, j);
    int min_xy = min(x, y);
    if(min_xy == 1) return 1;
    return (2 * min_xy - 1);
}

int getMaxProd(int x1, int y1, int x2, int y2){
    vector<cell> first;
    vector<cell> second;
    int i, j, a1, a2;
    int d1 = (myMax[x1][y1] - 1) >> 2;
    int d2 = (myMax[x2][y2] - 1) >> 2;
    bool overlapWhenLastAddedIsFirst = false, overlapWhenLastAddedIsSecond = false;
    bool added1 = false, lastAdded2 = false;
    first.push_back({.x = x1, .y = y1});
    second.push_back({.x = x2, .y = y2});
    for (i = 1, j = 1; (i <= d1) || (j <= d2); ){
       added1 = false;
       if(i <= d1) {
            first.push_back({.x = x1, .y = y1+i});
            first.push_back({.x = x1, .y = y1-i});
            first.push_back({.x = x1+i, .y = y1});
            first.push_back({.x = x1-i, .y = y1});
            if(doOverlap(first, second)){
                 overlapWhenLastAddedIsFirst = true;
                 if(lastAdded2) j--; // to nullify j++ in last iteration so that j points to most recent second-cell added.
                 break;
            }
            added1 = true;
            i++;
       }
       lastAdded2 = false;
       if(j <= d2) {
            second.push_back({.x = x2, .y = y2+j});
            second.push_back({.x = x2, .y = y2-j});
            second.push_back({.x = x2+j, .y = y2});
            second.push_back({.x = x2-j, .y = y2});
            if(doOverlap(first, second)){
                if(added1){
                   i--;  // to nullify i++ above so that i points to most recent first-cell added in this iteration.
                }
                overlapWhenLastAddedIsSecond = true;
                break;
            }
            lastAdded2 = true;
            j++;
       }
    }
    /*
     * When no overlap happens for first/second i.e. it extends maximum before other point overaps 
     * with it, then out-of-bound occurs for that index.
     */
    if(overlapWhenLastAddedIsFirst || i > d1)
        i--;
    if(overlapWhenLastAddedIsSecond || j > d2)
        j--;
    a1 = 1 + 4*i;
    a2 = 1 + 4*j;
    return a1*a2;
}


int getMaxProdWithThisCell(int x, int y){
    int maxProd = -1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(x != i || y != j) { 
                int tmp = getMaxProd(x, y, i, j);
                if(tmp > maxProd)
                    maxProd = tmp;
           }
        }
    }
    return maxProd;
}

void printArea(void) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << myMax[i][j] << " ";
        cout << endl;
    }       
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            myMax[i][j] = getMaxAreaForThisCenter(i, j);
    #if DEBUG2
    printArea();
    #endif
    int maxProd = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
                 int curProd = getMaxProdWithThisCell(i, j);
                 if(curProd > maxProd)
                     maxProd = curProd;
        }
    }
    cout << maxProd << endl;
   
    return 0;
}
