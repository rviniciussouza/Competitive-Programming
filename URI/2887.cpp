#include <bits/stdc++.h>
using namespace std;
 
#define left(x) (x << 1)
#define right(x) (x << 1) + 1
#define parent(x) (x >> 1)
 
const int MN = 100010;
int first[MN], vis[MN], S[MN], height[MN];
vector<int> G[MN], euler, st;
 
void init() {
    st.resize(euler.size() * 4);
}
 
void build(int s, int l, int r) {
 
    if(l == r) st[s] = euler[l];
    else {
        int media = ((l + r) >> 1);    
        build(left(s), l, media);
        build(right(s), media + 1, r);
 
        int L = st[left(s)];
        int R = st[right(s)];
        st[s] = height[L] < height[R] ? L : R;
    }
 
}
 
int query(int s, int l, int r, int a, int b) {
    
    if(a > r || b < l) return -1;
    if(l >= a && r <= b) return st[s];
    int media = ((l + r) >> 1);
    int L = query(left(s), l, media, a, b);
    int R = query(right(s), media + 1, r, a, b);
    if(L == -1) return R;
    if(R == -1) return L;
    return height[L] < height[R] ? L : R;
}
 
int LCA(int n, int a, int b) {
 
    a = first[a]; b = first[b];
    if(b < a) swap(a, b);
    return query(1, 0, euler.size() - 1, a, b); 
 
}
 
 
void dfs(int u, int h) {
 
    vis[u] = true;
    height[u] = h;
    first[u] = euler.size();
    euler.push_back(u);
 
    for(auto to : G[u]) {
        if(!vis[to]) {
            dfs(to, h+1);
            euler.push_back(u);
        }
    }
}

int dist(int n, int u, int v) {
	int anc = LCA(n, u, v);
	return (height[u] - height[anc]) + (height[v] - height[anc]);
}
 
 
 
int main() {
 
    int n, u, v, a, b, q;
 
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i < n - 1; ++i) {
	
		scanf("%d %d", &u, &v);
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
	
	dfs(0, 0);
	init();
    build(1, 0, euler.size() -1);
	
	for(int i = 0; i < q; ++i) {
	
		scanf("%d %d %d %d", &u, &v, &a, &b);
		int X = dist(n, u-1, v-1) + dist(n, a-1, b-1);
		int Y = min(dist(n, u-1, a-1) + dist(n, v-1, b-1), dist(n, v-1, a-1) + dist(n, u-1, b-1)); 
				
		if(Y > X) puts("0");
		else printf("%d\n", (X - Y)/ 2 + 1);
	}
	
    return 0;
} 
