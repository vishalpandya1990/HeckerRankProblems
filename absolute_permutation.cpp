#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/absolute-permutation/problem
 * 
 * Uses - Basic maths, observations and analytical approach
 * 
 */ 

void printArray(int a[], int n) {
    for(int i = 1; i < n; i++)
       cout << a[i] << " ";
    cout << a[n] << endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;
        int *output = new int[n+1];
        for(int i = 1; i <= n; i++)
            output[i] = i;
        assert((k >= 0) && (k < n));
        if(k == 0)
        {
            printArray(output, n);
        } 
        else 
        {
            int cur = 1;
            bool notPossible = false;
            bool visited[n+1];
            memset(visited, false, sizeof visited);
            while (cur <= k) 
            {
                if( (cur+k > n)||visited[cur+k]){
                    notPossible = true;
                    break;
                }
                output[cur] = cur+k;
                visited[cur+k] = true;
                cur++;
            }
            
            while(!notPossible && (cur <= n))
            {
                bool cantPickRight = (cur+k > n) || visited[cur+k];
                bool cantPickLeft = visited[cur-k];
                if( cantPickLeft && cantPickRight) {
                    notPossible = true;
                    break;
                }
                else if(cantPickLeft)
                {
                    output[cur] = cur + k;
                    visited[cur + k] = true;
                } 
                else
                {
                    output[cur] = cur - k;
                    visited[cur - k] = true;
                } 
                cur++;
           }
           
            if(notPossible){
                cout << "-1" << endl;
            } else{
                 printArray(output, n);
            }
            delete[] output;
        }
    }
    return 0;
}
