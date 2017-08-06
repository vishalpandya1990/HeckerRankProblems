#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
 * Problem statement :- https://www.hackerrank.com/challenges/countingsort4/problem
 * 
 * Counting sort implementation with satellite data
 * 
 */ 

typedef struct{
    long int data;
    char str[12];
}node;

long int T[100];

int main() {

    long int n;  
    scanf("%ld",&n);
    
    node *list=(node *)malloc(n*sizeof(node));
    node *output=(node *)malloc(n*sizeof(node));
     
    for(long int i=0;i<n;i++){
        fscanf(stdin,"%ld %s",&(list[i].data),&(list[i].str));
        if(i<(n/2))
            strcpy(list[i].str,"-");
        T[list[i].data]++;
    }   
    
    for(long int i=1;i<100;i++)
          T[i]=T[i-1]+T[i];
    
    for(long int i=n-1;i>=0;i--){
        long int x=list[i].data;
        output[T[x]-1].data=x;
        strcpy(output[T[x]-1].str,list[i].str);
        T[x]--;
    }
   
    for(long int i=0;i<n;i++)
        printf("%s ",output[i].str);
    
    return 0;
}
