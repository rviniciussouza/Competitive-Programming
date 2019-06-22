#include <bits/stdc++.h>

using namespace std;

const int MN = 1000040;
const int M = 1000000;
long long lazy[4 * MN], st[4 * MN];
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

/* Funcao para atualizar */
void update(long long s, long long l, long long r, long long x, long long y, long long w) {

    if(lazy[s] != 0) {

        st[s] += (r - l + 1) * lazy[s];
        if(l != r) {
            lazy[left(s)] += lazy[s];
            lazy[right(s)] += lazy[s];
        }
        lazy[s] = 0;
    }

    if(l > y || r < x || l > r) return;
    
    if(l >= x && r <= y) {
        
        st[s] += (r - l + 1) * w;        
        if(l != r) {
            lazy[left(s)] += w;
            lazy[right(s)] += w;
        }
        return;
    }

    long long mid = (l + r) / 2;
    update(left(s), l, mid, x, y, w);
    update(right(s), mid + 1, r, x, y, w);
    st[s] = st[left(s)] + st[right(s)];
}

long long query(long long s, long long l, long long r, long long x, long long y) {

    if(lazy[s] != 0) {

        st[s] += (r - l + 1) * lazy[s];
        if(l != r) {
            lazy[left(s)] += lazy[s];
            lazy[right(s)] += lazy[s];
        }
        lazy[s] = 0;
    }

    if(l > y || r < x || l > r) return 0;
    
    if(l >= x && r <= y) {
        return st[s];
    }

    long long esq = query(left(s), l, (l + r) / 2, x, y);
    long long dir = query(right(s), (l + r) / 2 + 1, r, x, y);
    return esq + dir;
}

int main() {

    long long T, N, C, u, v, w, op;
    
    while(true) {
		
		scanf("%lld", &N);
		if(N == 0) break;
		
		memset(lazy, 0LL, sizeof lazy);
		memset(st, 0LL, sizeof st);
		
		printf("MENSAGEM: [");
		
		bool flag = false;
		for(int i = 0; i < N; ++i) {
			
			scanf("%lld", &op);
			
			if(flag) continue;
			
			if(op == 18) {
				scanf("%lld %lld %lld", &u, &v, &w);
				i += 3;
				update(1, 0, M - 1, u, v, w);
			}
			
			else if(op == 42) {
				scanf("%lld", &u);
				i += 1;
				long long p = query(1, 0, M - 1, u, u);
				long long q = query(1, 0, M - 1, u-1, u-1);
				if(p - q < 0) printf(" ");
				else {
					int k = (p - q) % 26;
					char c = 'A';
					c = c + k;
					printf("%c", c);
				}
			}
			
			else {
				flag = true;
			}
		}
		printf("]\n");
	}

    return 0;

}
