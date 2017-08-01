#include <bits/stdc++.h>

using namespace std;

 /*
  * Problem statement - https://www.hackerrank.com/challenges/richie-rich/problem\
  * 
  * Uses - Palindrome basics
  * 
  */

/*
 * Following solution passes in 27 out of 32 test-cases provided.
 * 
 * TODO
 * 1. run following test-input.
 *     15 8 128392759430124 
 *     Ans - 929394959493929
 * 2. Fix failing 5 test-cases.
 *
 */

/*
 * Based on pairs of complementary charatcers with mismatch, we can
 * classify the charcter-pairs in input as following:
 *
 * Case-1 - Both the characters of the pair are equal to 9. (no mismatch)
 * Case-2 - Both the characters of the pair are equal to non-9 character. (no mismatch)
 * Case-3 - There is mismatch and one character is equal to 9, while  other is not. (mismatch)
 * Case-4 - There is mismatch and none is equal to 9.
 *
 * For Case-1 - Nothing to be done.
 * For Case-3 - If there are moves remaining, make other character equal to 9.
 * For Case-2 - If there are "sufficient" moves, make both equal to 9, otherwise leave them unchanged.
 * For Case-4 - Two options - Depending on moves available/remaining, either make both equal to 9, or
 *                            replace smaller with bigger.
 * If in the end (i.e. after handling mismatches), there are moves remaining, try to make bigger palindrome.
 * Make note of middle element in case of odd-length input. Its not part of any pair. So 1 move is sufficient.
 * Handle all base cases properly.
 *
 */

const char nine = '9';

bool isPalindrome(string s) {
   for(int i = 0, j = s.length()-1; i < j; i++, j--) {
       if(s.at(i) != s.at(j)) 
           return false;
   }
    return true;
}

int getCountOfMismatchingPair(string s) {
   int count = 0;
   for(int i = 0, j = s.length()-1; i < j; i++, j--) {
       if(s.at(i) != s.at(j)) 
           count++;
   }
    return count;
}

string makeBiggerPalindrome(string s, int maxMoves) {
    int movesDone = 0, n = s.length();
    for(int i = 0, j =  n - 1; (movesDone + 2 <= maxMoves ) && (i < j); i++, j--) {
        if(s.at(i) == '9') continue;
        s.replace(i, 1, 1, nine);
        s.replace(j, 1, 1, nine);
        movesDone += 2;
    }
    if(movesDone < maxMoves && (n%2 == 1))
        s.replace(n/2, 1, 1, nine);
    return s;
}

string handleSingleMismatch(string s, int k, int *rem) {
    int i, j, remMoves = k;
    for(i = 0, j = s.length() - 1; (i < j) && (remMoves > 0); i++, j--) 
    {
        if(s.at(i) != s.at(j)) 
        {
            if(s.at(i) == '9') {
                s.replace(j, 1, 1, nine);
                remMoves--;
            } else if(s.at(j) == '9') {
                s.replace(i, 1, 1, nine);
                remMoves--;
            } else {
                
            }
        }
    }
    *rem = remMoves;
    return s;
}

string handleDoubleMismatch(string s, int k, int *rem) {
     int remPairCount = getCountOfMismatchingPair(s);
     if(remPairCount == 0) {
         *rem = k;   
         return s;
     }
     int remMoves = k;
     int i , j;
     for(i = 0, j = s.length() - 1; (remMoves > 0) && (i < j); i++, j--) 
     {
         if((s.at(i) == s.at(j)) && (s.at(i) == '9')) continue;

         bool misMatch = s.at(i) != s.at(j);
         bool remainingToCheck = misMatch ? remPairCount - 1 : remPairCount;
         bool changeBoth = (remMoves >= 2) && (remainingToCheck <= (remMoves - 2));
        
         if(changeBoth) {
             s.replace(j, 1, 1, nine);
             s.replace(i, 1, 1, nine);
             remMoves -= 2;
         } else if (misMatch) {
                const char left[] = {s.at(i), 0};
                const char right[] = {s.at(j), 0};
                if(atoi(left) > atoi(right)) {
                    s.replace(j, 1, 1, left[0]);
                } else {
                    s.replace(i, 1, 1, right[0]);
                }
                remMoves--;
         }
         
         if(misMatch) remPairCount--;
     }
    *rem = remMoves;
    return s;
}

string richieRich(string s, int n, int k){
    if(n == 0) return "-1";
    if(n == 1){
        if(s.at(0) != '9' && k > 0) return "9";
        else return s;
    }
    if(k == 0){
        if(isPalindrome(s)) return s;
        else return "-1";
    }
    
    int rem1, rem2;
    string s1 = handleSingleMismatch(s, k, &rem1);
    //cout << "s1 = " << s1 << " rem1 = " <<  rem1 << endl;
    string s2 = handleDoubleMismatch(s1, rem1, &rem2);
    //cout << "s2 = " << s2 << " rem2 = " <<  rem2 << endl;
    string result;
    if(isPalindrome(s2) && (rem2 > 0) ) 
        result = makeBiggerPalindrome(s2, rem2);
    else if (isPalindrome(s2))
        result = s2;
    else
        result = "-1";
    return result;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
