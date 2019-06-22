#include <stdio.h>
#include <vector>

using namespace std;

#define FOR(i, N) for(int i = 1; i <= N; ++i)

typedef long long ll;
typedef vector<vector<ll> > matrix;
int K = 2;
long long M;

matrix mul(matrix A, matrix B) {

    matrix ANS(K+1, vector<ll>(K+1));
    FOR(i, K) FOR(j, K) FOR(k, K)
        ANS[i][j] = (ANS[i][j] + A[i][k] * B[k][j]) % M;
    return ANS;
}   


matrix pow(matrix T, int p) {

    if(p == 1) return T;
    if(p%2 == 1) return mul(T, pow(T, p-1)); 
    matrix X = pow(T, p/2);
    return mul(X, X);
}

long long fib(ll N, ll M) {


    vector<ll> F(K+1);
    matrix T(K+1, vector<ll>(K+1));

    F[1] = 1;
    F[2] = 1;

    T[1][1] = 0; T[1][2] = 1;
    T[2][1] = 1; T[2][2] = 1;

    if(N == 1) return 1;
    else {
        T = pow(T, N - 1);
    }

    ll ans = 0;
    FOR(i, K) ans += (T[1][i] * F[i]) % M;

    return ans;

}

int main() {

    ll a;

    while(scanf("%lld %lld", &a, &M) == 2) {
        printf("%lld\n", fib(fib(a, M)%M, M)%M);
    }

    return 0;
}