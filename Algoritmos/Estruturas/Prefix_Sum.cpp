#include <bits/stdc++.h>
using namespace std;

/*Prefix Sum 1D */

void Prefix_Sum(int arr[], int prefixSum[], int n) {

    prefixSum[0] = arr[0];
    for(int i=1; i < n; ++i) prefixSum[i] = prefixSum[i-1] + arr[i];
    for(int i=0; i < n; ++i) printf("%d \n", prefixSum[i]);
}

int main()
{
    int arr[] = {2,5,6,7,9,7,0,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    Prefix_Sum(arr, prefixSum, n);
    return 0;
}


/*

Aplicações

Equilibrium index of an array : Equilibrium index of an array is an index such that the
sum of elements at lower indexes is equal to the sum of elements at higher indexes.

Find if there is a subarray with 0 sum : Given an array of positive and negative
numbers, find if there is a subarray (of size at-least one) with 0 sum.

Maximum subarray size, such that all subarrays of that size have sum less than k:
Given an array of n positive integers and a positive integer k,
the task is to find the maximum subarray size such that all subarrays
of that size have sum of elements less than k.

Find the prime numbers which can written as sum of most consecutive primes:
Given an array of limits. For every limit, find the prime number which can
be written as the sum of the most consecutive primes smaller than or equal
to limit.

Longest Span with same Sum in two Binary arrays : Given two binary arrays arr1[] and arr2[] of
same size n. Find length of the longest common span (i, j)
where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].

Maximum subarray sum modulo m : Given an array of n elements and an integer m.
The task is to find the maximum value of the sum of its subarray modulo m i.e find
the sum of each subarray mod m and print the maximum value of this modulo operation.

Maximum subarray size, such that all subarrays of that size have sum less than k :
Given an array of n positive integers and a positive integer k, the task is to find the
maximum subarray size such that all subarrays of that size have sum of elements less than k.
*/