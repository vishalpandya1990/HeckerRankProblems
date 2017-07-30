#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/strange-code/problem
 * 
 * Uses - Basic Maths - Arithmetic Progession
 * 
 */

int main(){
    long long t;
    cin >> t;
    long ans;
    if(t < 4) {
        ans = 3 - (t - 1);
        goto DONE;
    }
    long prev_st, cur_st, cur_val;
    prev_st = 1;
    cur_st = 4;
    cur_val = 6;
    while (t >= cur_st){
        prev_st = cur_st;
        cur_st = cur_st + cur_val;
        cur_val = 2*cur_val;
    }
    ans = (cur_val/2) - (t - prev_st);
DONE:
    cout << ans << endl;
    return 0;
}
