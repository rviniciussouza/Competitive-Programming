#include <bits/stdc++.h>
using namespace std;

/*
 * Segmet Tree para consultas RMQ E RSQ com
 * lazy propagation
 * github @rviniciusouza
 */

#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

const int MN = 400010;
long long st[MN], lazy[MN];

void update(int si, int l, int r, int a, int b, int value) {
    if(lazy[si] != 0) {
        st[si] += (r - l + 1) * lazy[si];
        // st[si] +=  lazy[si];
        if(l != r) {
            lazy[left(si)] += lazy[si];
            lazy[right(si)] += lazy[si];
        }
        lazy[si] = 0;
    }
    
    if(a > r || b < l) return;

    if(l >= a && r <= b) {
        st[si] += (r -l + 1) * value;
        // st[si] += value;
        if(l != r) {
            lazy[left(si)] += value;
            lazy[right(si)] += value;
        }
    }

    else {
        update(left(si), l, (l + r) / 2, a, b, value);
        update(right(si), (l + r) / 2 + 1, r, a, b, value);
        st[si] = st[left(si)] + st[right(si)];
        // st[si] = max(st[left(si)], st[right(si)]);
    }
}

long long getSum(int si, int l, int r, int a, int b) {
    if(lazy[si] != 0) {
        st[si] += (r - l + 1) * lazy[si];
        // st[si] += lazy[si];
        if(l != r) {
            lazy[left(si)] += lazy[si];
            lazy[right(si)] += lazy[si];
        }
        lazy[si] = 0;
    }    

    if(l >= a && r <= b) return st[si];
    if(a > r || l > b) return 0;
    // return max(getSum(left(si), l, (l + r) / 2, a, b),
        //    getSum(right(si), (l + r) / 2 + 1, r, a, b));
    return getSum(left(si), l, (l + r) / 2, a, b) + 
           getSum(right(si), (l + r) / 2 + 1, r, a, b);
}

int main() {
    
    int n, op, p, q, t, c;
    long long v;

    scanf("%d", &t);        
    while(t--) {
        scanf("%d %d", &n, &c);

        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);

        while(c--) {
            scanf("%d", &op);

            if(op == 0) {
                scanf("%d %d %lld", &p, &q, &v); p--; q--;
                    update(1, 0, n - 1, p - 1, q - 1, v);    
            }

            else {
                scanf("%d %d", &p, &q);
                printf("%lld\n", getSum(1, 0, n - 1, p - 1, q - 1));
            }
        }
    }

    return 0;
}