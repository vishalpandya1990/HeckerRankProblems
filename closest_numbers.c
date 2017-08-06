#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Problem statement :- https://www.hackerrank.com/challenges/closest-numbers/problem
 * 
 * Uses basic sorting mechanism
 * 
 */ 

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);    
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    int *a=(int*)malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++)
        scanf("%d ", a+i);
    
    qsort(a, n, sizeof(int), compare);   
    
    int min=INT_MAX;
    for(int i=0;i<n-1;i++)
        if(abs(a[i]-a[i+1]) < min)
         min = abs(a[i]-a[i+1]);
    
    for(int i=0;i<n-1;i++)
        if(abs(a[i]-a[i+1]) == min)
         printf("%d %d ", a[i], a[i+1]);
 
    return 0;
}
