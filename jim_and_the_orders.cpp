#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem statement :- nhttps://www.hackerrank.com/challenges/jim-and-the-orders/problem
 * 
 * Uses basic greedy approach
 * 
 */ 

typedef unsigned long long int ulli;

typedef struct
{
    ulli fanid, ordertime, processtime, deliverytime;
}order;


int compare(const void *a, const void *b)
{
    ulli x = ((order *)a)->deliverytime;
    ulli y = ((order *)b)->deliverytime;
    if(x==y) 
        return ( ((order *)a)->fanid < ((order *)b)->fanid ) ? -1 : 1;
    else
        return x-y;
}

int main() {
    ulli n, i;
    cin >> n;
    order *bulkorder = new order[n+1];
    for(i=1;i<=n;i++)
    {
        ulli x, y;
        cin >> x >> y;
        bulkorder[i].fanid=i;
        bulkorder[i].ordertime=x;
        bulkorder[i].processtime=y;
        bulkorder[i].deliverytime=x+y;
    }
    qsort(bulkorder+1,n,sizeof(order),compare);   
    for(i=1;i<=n;i++)
        cout << bulkorder[i].fanid << " ";
    return 0;
}
