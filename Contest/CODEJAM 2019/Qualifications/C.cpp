#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;

bool primos[MN];
pair<int, int> mx[MN];
pair<int, int> pre[MN * MN], prod[MN * MN];

void sieve() {
    for(int i = 2; i * i <= MN; ++i) {
        if(primos[i] == true) {
            for(int j = i + i; j <= MN; j += i) {
                primos[j] = false;
            }
        }
    }
}

int main() {


    int T, N, L, C;

    scanf("%d", &T);

    memset(primos, true, sizeof primos);
    sieve();

    for(int i = 2; i <= MN; ++i) {
        for(int j = 2; j <= MN; ++j) {
            if(primos[i] && primos[j]) {
                pre[i*j] = make_pair(min(i, j), max(i, j));
            }
        }
    }


    for(int k = 1; k <= T; ++k) {

        scanf("%d %d", &N, &L);
        map<int, char> mapa;
        set<int> used_primes;

        for(int i = 0; i < L; ++i) {
            scanf("%d", &C);
            prod[i] = pre[C];
            printf("%d %d\n", prod[i].first, prod[i].second);

            used_primes.insert(pre[C].first);
            used_primes.insert(pre[C].second);
        }

        set<int>::iterator it;
        for(it = used_primes.begin(), int i = 0; it != used_primes.end(); ++it) {
            mapa.insert(make_pair(*it,'A'+i++));
        }

        string ans;
        for(int i = 0; i < L; ++i) {
            if(prod[i].first == prod[i+1].first && prod[i].second == prod[i+1].second) {
                ans[i] = prod[i].first;
            }
        }

        printf("--------\n");
        for(int i = 0; i < L; ++i) {
            printf("%d %d\n", mx[i].first, mx[i].second);
        }
        printf("--------\n");

        for(int i = 0; i < L; ++i) {
            
            if(mx[i].second % 2 == 0) {
                if(prod[i].first == prod[mx[i].second].first || prod[i].first == prod[mx[i].second].second) {
                    ans.insert(0,1, mapa[prod[i].first]);
                }
                else {
                    ans.insert(0,1, mapa[prod[i].second]);
                }
            } 
            else {
                if(prod[i].first != prod[mx[i].second].first || prod[i].first != prod[mx[i].second].second) {
                    ans.insert(0,1, mapa[prod[i].first]);
                }
                else {
                    ans.insert(0,1, mapa[prod[i].second]);
                }
            }
        }

        //     if(i == L - 1) {
        //         if(prod[i].first == prod[i-1].second || prod[i].first == prod[i-1].first) {
        //             ans.insert(0, 1, mapa[prod[i].first]);
        //             ans.insert(0, 1, mapa[prod[i].second]);
        //         }

        //         else {
        //             ans.insert(0, 1, mapa[prod[i].second]);
        //             ans.insert(0, 1, mapa[prod[i].first]);
        //         }
        //     }

        //     else {
        //         if(prod[i].first != prod[i+1].first && prod[i].first != prod[i+1].second) {
        //             ans.insert(0, 1, mapa[prod[i].first]);
        //         }
        //         else ans.insert(0, 1, mapa[prod[i].second]);
        //     }
        // }


        cout << "Case #" << k << ": ";

        for(int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i];
        }

        cout << '\n';
    }

    return 0;
}