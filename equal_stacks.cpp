#include <set>
#include <vector>
#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/equal-stacks/problem
 * 
 * Uses greedy approach
 * 
 */ 

typedef long long int lli;

int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    
    vector<int> h1(n1);
    lli x = 0;
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       x += h1[h1_i]; 
    }
    vector<int> h2(n2);
    lli y = 0;
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
       y += h2[h2_i] ;
    }
    vector<int> h3(n3);
    lli z = 0;
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
       z += h3[h3_i] ;
    }
    
    lli ans = -1;
    if((x == y) && (y == z)){
        ans = x;
        cout << ans << endl;
        return 0;
    }
    
    lli t = 0;
    set<lli> :: iterator it;
    
    set<lli> set1;
    for(lli i = 0 ; i < n1; i++){
        t += h1[i];
        set1.insert(x-t);
    }
    
    t = 0;
    set<lli> set2;
    for(lli i = 0 ; i < n2; i++){
        t += h2[i];
        it = set1.find(y-t);
        if(it != set1.end())
            set2.insert(y-t);
    }
        
    t = 0;
    set<lli> set3;
    for(lli i = 0 ; i < n3; i++){
        t += h3[i];
        it = set2.find(z-t);
        if(it != set2.end()){
            ans = z-t;
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}
