#include <bits/stdc++.h>
using namespace std;

const int MN = 1123456;

int D[MN][27];
int B[1][27];

bool isAnagrama(int x, int y) {
    for(int i = 0; i < 26; ++i) {
        if(D[y][i] - D[x-1][i] != B[0][i]) return false;
    }
    return true;
}

int main() {

    int k;
    string T, M;

    cin >> T;
    cin >> M;

    memset(D, 0, sizeof D);
    memset(B, 0, sizeof B);

    // D[0][T[0] - 'a'] += 1;

    for(int i = 1; i <= T.size(); ++i) {
        for(int j = 0; j < 26; ++j) {
            D[i][j] = D[i-1][j];
        }
        D[i][T[i-1] - 'a'] += 1;
    }

    for(int i = 0; i < M.size(); ++i) {        
        B[0][M[i] - 'a'] += 1;
    }

    int fim;
    long long ans = 0;

    for(int i = 0, ant = 0; i < T.size() - M.size() + 1; ++i) {
        fim = i + M.size() - 1;

        if(isAnagrama(i+1, fim+1)) {
            long long aux = T.size() - fim;
            aux *= i - ant + 1;
            ant = i + 1;
            ans += aux;
        }
    }
    printf("%lld\n", ans);

    return 0;

}