#include <vector>
#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/new-year-chaos/problem
 * 
 * Components used :- Inversions and Basic sorting techniques
 */

int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n, chaotic = 0;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
           if((q[q_i]-1)-q_i > 2)
               chaotic = 1;

       }
       if(chaotic){
           cout << "Too chaotic" << endl;
           continue;
       }
        int ans = 0;
        for(int pass = 1; pass < n; pass++){
            bool sort_done = true;
            for(int i = 0; i < n - pass; i++){
                if(q[i] > q[i+1]){
                   int tmp = q[i];
                   q[i] = q[i+1];
                   q[i+1] = tmp;
                   ans++; 
                   sort_done = false; 
                }
            }
            if(sort_done)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
