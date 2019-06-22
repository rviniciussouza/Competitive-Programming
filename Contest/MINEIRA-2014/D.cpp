#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, L, G;

    char msg[180];
    pair<int, int> A[4100];

    while(scanf("%d %d %d", &N, &L, &G) && N != 0) {

        int qtd_msgs_A = 0;
        int qtd_msgs_B = 0;

        for(int i = 0; i < N; ++i) {

            scanf(" %[^\n]s", msg);
            if(msg[7] == ':') {
                A[i] = make_pair(0, strlen(msg) - 8);
                qtd_msgs_A++;
            }
            else {
                A[i] = make_pair(1, strlen(msg) - 7);
                qtd_msgs_B++;
            }
        }

        int ant = -1, t = 0, qtdA = 0, qtdB = 0;
        for(int i = 0; i < N; ++i) {
            if(A[i].first == ant) {
                if(t + A[i].second < 160) t += A[i].second + 1;
                else {
                    t = A[i].second;
                    if(ant == 0) qtdA++;
                    else qtdB++;
                }
            }
            else {
                t = A[i].second;
                if(A[i].first == 0) {
                    qtdA++;
                    ant = 0;
                }
                else {
                    qtdB++;
                    ant = 1;
                }
            }
        }

        printf("%d %d\n", (qtd_msgs_B - qtdB) * L, (qtd_msgs_A - qtdA) * G);

    }

    return 0;

}