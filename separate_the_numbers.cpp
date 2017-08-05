#include <bits/stdc++.h>

using namespace std;

/*
 * Problems statement :- https://www.hackerrank.com/challenges/separate-the-numbers/problem
 * 
 * Uses basic string manipulations, and analysis
 *
 */ 

typedef unsigned long long int ulli;

string curString;
ulli a1 = -1;

int getNextInt(const char *str, ulli start, ulli lastVal) {
    if(!str) return -1;
    if(str[0] == '0') return -1;
    ulli n = strlen(str);
    ulli end = start;
    while(end < n){
        char tmp[n] = {0};
        strncpy(tmp, str+start, end-start+1);
        ulli num = atoi(tmp);
        if(num == lastVal + 1) return end;
        if(num > lastVal) return -1;
        end++;
    }
    return -1;
}

bool solveAfterA1(ulli n, ulli a1) {
       ulli nextNum = a1;
       string nextStr = to_string(nextNum);
       string pattern = "";
       while((pattern.length() < n) && ((nextStr.length() + pattern.length()) <= n)) {
                  pattern.append(nextStr);
                  nextNum++;
                  nextStr = to_string(nextNum);
       }
       if((pattern.length() == n) && (pattern.compare(curString) == 0))
           return true;
       return false;
}

bool solve(const char *str) {
    if(!str) return false;
    ulli n = strlen(str);
    if(n == 1) return false;
    if(str[0] == '0') return false;
    if(n == 2){
        if( (str[0] != '0') && (str[1] != '0') && (str[1] == str[0] + 1))
        {
            ::a1 = str[0] - '0';
            return true;
        }
        else
            return false;
    }
    
    ulli a1_width = 1;
    while(a1_width < n) {
        char tmp1 [n] = {0};
        strncpy(tmp1, str, a1_width);
        ulli a1 = strtoull(tmp1, 0, 0);
        bool res = solveAfterA1(n, a1);
        if(res) {
            ::a1 = a1;
            return true;
        }
        a1_width++;
    }
    return false;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        curString = s;
        const char *str = s.c_str();
        bool ans = solve(str);
        if(ans)
            cout << "YES" << " " << a1 << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
