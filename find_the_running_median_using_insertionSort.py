from bisect import insort

# Problem statement :- https://www.hackerrank.com/challenges/find-the-running-median/
# Uses insertion sort

def median(A):
    if len(A)%2==0:
        r = A[len(A)/2]
        l = A[len(A)/2 - 1]
        med = float((l+r)/2.0)
    elif len(A)%2!=0:
        med = A[len(A)/2]

    return med

A=[]
for _ in range(int(raw_input())):
    insort(A,int(raw_input()))
    med = median(A)
    print med
