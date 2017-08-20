#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 * Problem statement :- https://www.hackerrank.com/challenges/find-the-running-median
 *
 * Uses insertion sort
 */

double getMedian(int a[], int endPos) {
    int num = endPos + 1;
    if(num%2 == 1) {
        return a[num/2] + 0.0;
    } else {
        int m2 = num/2;
        int m1 = m2 - 1;
        long sum = a[m1] + a[m2];
        return sum/2.0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    double m = 0.0f;
    for(i = 0; i < n; i++) {
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        m = getMedian(a, i);
        printf("%.1f\n", m);
        
    }
    return 0;
}
