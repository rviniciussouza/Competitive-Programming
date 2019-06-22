#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int bit[N];

void update(int pos) {
    for ( ; pos < N; pos += (pos &(-pos))) {
        bit[pos]++;
    }
}

int query(int pos){
    int resp = 0;
    for ( ; pos > 0; pos -= (pos & (-pos))) {
        resp += bit[pos];
    }
    return resp;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(i) printf(" ");
        printf("%d", x - query(x));
        update(x);
    }
    printf("\n");
}