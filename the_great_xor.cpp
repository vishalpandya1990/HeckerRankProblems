#include <bits/stdc++.h>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/the-great-xor/problem
 * 
 * Uses :- Combinatorics, Bitwise logic and manipulations
 * 
 */

long getLeftMostSetBitPos(long num)
{
    long count = 0;
    while (num != 0)
    {
        count++;
        num = num >> 1;
    }
    return(count);
}
long theGreatXor(long x){
    long width = getLeftMostSetBitPos(x);
    long maxNonZeroNums = (1L << width) - 1;
    return (maxNonZeroNums - x);
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long result = theGreatXor(x);
        cout << result << endl;
    }
    return 0;
}
