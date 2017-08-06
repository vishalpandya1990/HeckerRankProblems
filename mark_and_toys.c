#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 * Problem statement :- https://www.hackerrank.com/challenges/mark-and-toys/problem
 * 
 * Uses greedy approach
 *
 */ 

int compare (const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
 

int main() {
    int n, k, i, count;
    scanf("%d%d", &n, &k);
    int *prices = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &prices[i]);
    }
    
    qsort(prices,n,sizeof(int),compare);
   
    int answer = 0;
    
    int amountSpent=0;
    int j=0;
    while(amountSpent<k && j<n){
        amountSpent+=prices[j];
        answer++;
        j++;
    }
    if(amountSpent>k)
        answer--;
    if(prices[0]>k)
        answer=0;

    printf("%d\n", answer);
      
    return 0;
}
