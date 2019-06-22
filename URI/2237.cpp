#include <bits/stdc++.h>
using namespace std;

struct estado {
    int config[4][4];
};



int main() {

    int A[4][4], B[4][4];

    map<estado, int> mapa;

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    int cnt_v = 0;
    mapa[A] cnt_v++;

    queue<pair<estado, int> > vertices_ger;

    vertices_ger.push(make_pair(A, cnt_v-1));

    while(!vertices_ger.empty()) {

        ii = vertices_ger.top(); vertices_ger.pop();

        for(int i = 0; i < 3; ++i) {

            estado novo = estado_cur;
            novo.config[i+1][0] = estado_cur.config[i][0]; 
            novo.config[i][0] = estado_cur.config[i+1][0];

        }
    }

    for(int i = 0; i < 3; ++i) {

        

        if(mapa.find(novo) == mapa.end()) {
            mapa[novo] = cnt_v++;
            G[mapa[estado_cur]].push_back(make_pair(mapa[novo], estado_cur[i][0] + estado_cur[i+1][0]));
            G[mapa[novo]].push_back(make_pair(mapa[estado_cur], estado_cur[i][0] + estado_cur[i+1][0]));
        }
    }


    return 0;

}