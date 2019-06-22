#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MN = 1000010;

bool primo[MN];
int ans[MN];

void crivo() {

    primo[0] = false;
    primo[1] = false;
    for(int i = 2; i * i <= MN; i++) {
        if(primo[i])
            for(int j = i * 2; j <= MN; j += i)
                primo[j] = false;
    }

}


int main() {
    int q, x, y, a, b;

    scanf("%d", &q);

    memset(primo, true, sizeof primo);
    // memset(ans, 0, sizeof ans);
    crivo();

    for(int i = 3; i <= MN; ++i) {
        ans[i] = ans[i-1];
        if(primo[i] && (primo[i-2] || primo[i+2])) ans[i] += 1;
    }

    while(q--) {
        scanf("%d %d", &x, &y);
        a = std::min(x, y);
        b = std::max(x, y);
        printf("%d\n", ans[b] - ans[a-1]);
    }

    return 0;

}