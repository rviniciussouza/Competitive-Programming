#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

vector<pair<int, int> > linha(MAXN, make_pair(-1, 4));
vector<pair<int, int> > coluna(MAXN, make_pair(-1, 4));

int main() {
    int n, m, k, v;
    string d;
    cin >> n >> m >> k;

    int ans[] = {0,0,0,0,0};

    for(int i = 1; i <= k; ++i) {
        cin >> d >> v;
        if(d == "L") {
            linha[v] = make_pair(i, i % 4);
        }
        else coluna[v] = make_pair(i, i%4);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(linha[i].first > coluna[j].first) {
                ans[linha[i].second]++;
            }
            else {
                ans[coluna[j].second]++;
            }
        }
    }

    printf("R%d H%d C%d P%d\n", ans[1], ans[2], ans[3], ans[0]);

    return 0;

}