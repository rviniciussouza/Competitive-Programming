#include <bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
ll MOD; // = 1e9 + 7;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, long long p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
long long fib(long long N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;
    // F1[3] = 2;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1; //T[1][3] = 0;
    T[2][1] = 1, T[2][2] = 1; // T[2][3] = 1;
    // T[3][1] = 1, T[3][2] = 1; T[3][3] = 0;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res += (T[1][i] * F1[i]) % MOD;
    return res;
}

int main() {
    long long n;
    while(scanf("%lld %lld", &n, &MOD) == 2)
    printf("%lld\n", fib(fib(n)%MOD)%MOD);

    return 0;
}