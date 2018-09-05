#include <bits/stdc++.h>
using namespace std;
/*Encontre os números primos que podem ser escritos
como soma da maioria dos primos consecutivos
*/

const int MAX  = 10000;
 
void sieveSundaram(vector <int> &primes)
{
    bool marked[MAX/2 + 1] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
 
    // Since 2 is a prime number
    primes.push_back(2);
 
    // Print other primes. Remaining primes are of the
    // form 2*i + 1 such that marked[i] is false.
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}
 
// function find the prime number which can be written
// as the sum of the most consecutive primes
int LSCPUtil(int limit, vector<int> &prime, long long int sum_prime[])
{
    // To store maximum length of consecutive primes that can
    // sum to a limit
    int max_length = -1;
    // The prime number (or result) that can be reprsented as
    // sum of maximum number of primes.
    int prime_number = -1;
 
    for (int i=0; prime[i]<=limit; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (sum_prime[i] - sum_prime[j] > limit)
                break;
 
            long long int consSum  = sum_prime[i] - sum_prime[j];
 
            if (binary_search(prime.begin(), prime.end(), consSum))
            {
                // update the length and prime number
                if (max_length < i-j+1)
                {
                    max_length = i-j+1;
                    prime_number = consSum;
                }
            }
        }
    }
 
    return prime_number;
}
 
// Returns the prime number that can written as sum
// of longest chain of consecutive primes.
void LSCP(int arr[], int n)
{
    vector<int> primes;
    sieveSundaram(primes);
 
    long long int sum_prime[primes.size() + 1];

    sum_prime[0] = 0;
    for (int i = 1 ; i <= primes.size(); i++)
        sum_prime[i] = primes[i-1] + sum_prime[i-1];
 
    for (int i=0; i<n; i++)
      cout << LSCPUtil(arr[i], primes, sum_prime) << " ";
}
 
// Driver program
int main()
{
    int arr[] = {10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    LSCP(arr, n);
    return 0;
}