#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/best-divisor
 * 
 * Solution technique used :- Brute-force
 * 
 */

int sumOfDigits(int  num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int findBetter(int a, int b){
    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    if(sumA > sumB) return a;
    if(sumB > sumA) return b;
    return min(a, b);
}

int main(){
    int n;
    cin >> n;
    int bestDivisor;
    for(int i = 1; i*i <= n; i++){
       if(n%i == 0) {
           bestDivisor = findBetter(bestDivisor, i);
           bestDivisor = findBetter(bestDivisor, n/i);
       }
    }
    cout << bestDivisor << endl;
    return 0;
}
