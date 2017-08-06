#include <set>
#include <string>
#include <iostream>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/weighted-uniform-string
 * 
 * Uses string basics and STL (set/map)
 * 
 */ 

typedef unsigned long long int ulli;

void fillSums(string &str, set<ulli> &set) {
    ulli n = str.length();
    ulli cur = 0;
    ulli curUniformSubStrWt = 0;
    while(cur < n) {
        ulli curCharFreq = 1;
        ulli curCharWt = str.at(cur) - 'a' + 1;
        set.insert(curCharWt);
        while((cur+1 < n) && (str.at(cur+1) == str.at(cur))){
            cur++;
            curCharFreq++;
            set.insert(curCharWt*curCharFreq);
        }
        cur++;
    }
}


int main(){
    string s;
    cin >> s;
    set<ulli> st;
    fillSums(s, st);
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(st.find(x) != st.end())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
