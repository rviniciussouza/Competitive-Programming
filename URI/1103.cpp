#include <bits/stdc++.h>
using namespace std;

int main() {

    int h1, h2, m1, m2, tempo;

    while(1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if(!h1 && !m1 && !h2 && !m2) return 0;

        if(h1 < h2) {
            tempo = (h2 - h1) * 60;
            tempo = (tempo - m1) + m2;
            printf("%d\n", tempo);
        }

        else if(h1 == h2) {
            if(m1 <= m2) printf("%d", m2 - m1);
            else {
                tempo = 1440 - (m1 - m2);
                printf("%d\n", tempo);            
            }
        }

        else{
            tempo = ((24 - h1) + h2) * 60;
            tempo = (tempo - m1) + m2;
            printf("%d\n", tempo);            
        }
    }

    return 0;
}