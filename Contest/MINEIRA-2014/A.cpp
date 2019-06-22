#include <stdio.h>
// #include <algorithm>

int main( ) {

    int n, u, v[1010], ans;

    while(true) {
        scanf("%d", &n);

        if(n == 0) break;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }


        bool flag = false;
        for(int i = 200; i >= 0; --i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(v[j] >= i) cnt++;
                if(cnt == i) {
                    ans = i;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        printf("%d\n", ans);

    }

    return 0;
}