#include <bits/stdc++.h>
using namespace std;

int pilha[1010];

int main() {

    int n, p, h, s, q, x;

    while(scanf("%d %d", &n, &p) && n) {
        for(int i = 0; i < p; ++i) {
            scanf("%d", &q);
            pilha[i] = q;
            for(int j = 0; j < q; ++j) {
                scanf("%d", &x);
                if(x == 1) {
                    h = j+1; s = i;
                }
            }
        }

        int custor = 0;
        for(int i = s+1; i < n; ++i) {
            if(pilha[i] >= h) {
                custor += pilha[i] - h + 1; 
            } else break;
        }

        int custol = 0;
        for(int i = s-1; i >= 0; --i) {
            if(pilha[i] >= h) {
                custol += pilha[i] - h + 1; 
            } else break;
        }

        printf("%d\n", pilha[s] - h + min(custol, custor));
    }

    return 0;
}