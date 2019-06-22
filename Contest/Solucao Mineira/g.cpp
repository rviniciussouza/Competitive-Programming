#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 404;

int dp[N][N], n, custo[N][N];

int dist(int a, int b){

    int v1 = (min(a, b) + 26) - max(a, b);
    int v2 = max(a, b) - min(a, b);
    return min(v1, v2);
}

int back(int id, int k){
    if(k < 0) return INF;
    if(id == n) {
        if(k >= 0) return 0;
    }
    if(dp[id][k] != -1) return dp[id][k];
    int ans = INF;
    for (int i=id; i<n; i++){
        ans = min(ans, back(i+1, k-1) + custo[id][i]);
    }
    return dp[id][k] = ans;
}

int main()
{
    int k;
    cin >> n >> k;
    string str;
    cin >> str;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
          //  cout << i << ' ' << j << endl;
            int a = i, b = j;
            int c = 0;
            while (a < b){
                if(a != b) {
                    c += dist(str[a], str[b]);
                }
                a++, b--;
            }
            custo[i][j] = c;
            //cout << i << ' ' << j << ' ' << c << endl;
        }
    }
   // puts("pei");
   memset(dp, -1, sizeof dp);
    cout << back(0, k) << endl;
}