#include <bits/stdc++.h>
using namespace std;

#define max_n 100000

typedef struct {
    char p[210];
}numero;

numero v[max_n];

int compare(const void *a, const void *b) {
    numero x = *(numero*)a;
    numero y = *(numero*)b;
    return strcmp(x.p, y.p);
}

int main() {
    int n;

    while(scanf("%d", &n) != EOF) {
        for(int i=0; i < n; ++i)
            scanf(" %[^\n]s", v[i].p);

        qsort(v, n, sizeof(numero), compare);
    
        int ans = 0;
        numero cur = v[0];
        for(int i=1; i < n; ++i) {
            for(int j=0; j < strlen(v[i].p); ++j) {
                if(cur.p[j] != v[i].p[j]) {
                    cur = v[i];
                    break;
                }
                else ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}