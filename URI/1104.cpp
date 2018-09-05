#include <bits/stdc++.h>

int main()
{
    int a, b, valor;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(!a && !b) break;

        bool AA[10000], BB[10000];
        std::memset(AA, false, sizeof AA);
        std::memset(BB, false, sizeof BB);

        for(int i=0; i < a; ++i) {
            scanf("%d", &valor);
            AA[valor] = true;
        }

        for(int i=0; i < b; ++i) {
            scanf("%d", &valor);
            BB[valor] = true;
        }

        int cnt = 0;
        for(int i=0; i < 10000; ++i) {
            if(AA[i] != BB[i]) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}