#include <iostream>
#include <cstring>
using namespace std;

struct reg{
    string nome;
    int dist;
    int preco;
    int estrelas;
};

reg V[1010];
bool flag[1010];

bool compare(reg a, reg b) {
    int cnt = 0, cnk = 0;
    if(a.dist < b.dist) cnt++;
    else if(a.dist > b.dist) cnt--;
    else cnk++;

    if(a.preco < b.preco) cnt++;
    else if(a.preco > b.preco) cnt--;
    else cnk++;

    if(a.estrelas > b.estrelas) cnt++;
    else if(a.estrelas < b.estrelas) cnt--;
    else cnk++;    

    if(cnt > 0 && cnt + cnk == 3) return 0;
    else if(cnt < 0 && cnt - cnk == -3) return -1;
    else return 1;
}

int main() {

    int n;

    while(true) {
        cin >> n;
        if(n == 0) break;

        memset(flag, true, sizeof flag);

        for(int i = 0; i < n; ++i) {
            cin >> V[i].nome >> V[i].dist >> V[i].preco >> V[i].estrelas;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; j++) {
                if(flag[i] && flag[j]) {
                    int k = compare(V[i], V[j]);
                    if(k == 0) {
                        flag[j] = false;
                    }
                    else if(k == -1) flag[i] = false;
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(flag[i]) cout << V[i].nome << '\n';
        }

        cout << "*" << '\n';
    }

    return 0;

}