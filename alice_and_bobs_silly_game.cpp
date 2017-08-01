#include <iostream>
#include <cassert>
#include <cstring>

/*
 * Problem statement :- https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem
 * 
 * Uses basics of prime numbers and game theory
 *
 */

using namespace std;

const int maxN = 100000;

bool primes[maxN+1];
int  counts[maxN+1];

void fillPrimes(int maxN)
{
    primes[0] = primes[1] = false;
    for (int p = 2; p*p <= maxN; p++)
    {
        if (primes[p] == true)
        {
            for (int i = p*2; i <= maxN; i += p)
                primes[i] = false;
        }
    }
}

void fillCounts(int maxN)
{
   counts[0] = counts[1] = 0;
   counts[2] = 1;
   for(int i = 3; i <= maxN; i++) {
       counts[i] = counts[i-1] + (primes[i] ? 1 : 0);
       //cout << "i = " << i << " count = " << count[i] << " isPrime = " << prime[i] << endl;
   }
}

int main(){
    int g;
    cin >> g;
    memset(primes, true, sizeof primes);
    memset(counts, 0, sizeof counts);
    fillPrimes(maxN);
    fillCounts(maxN);
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        assert((n <= maxN) && (n > 0));
        cout << ( (counts[n] % 2  == 0) ? "Bob" : "Alice" )  << endl;
    }
    return 0;
}
