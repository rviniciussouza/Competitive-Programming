#define left(x) (x << 1)
#define right(x) (x << 1) + 1
#define parent(x) (x >> 1)
 
const int MN = 1010;
int first[MN], vis[MN], height[MN];
vector<int> G[MN], euler, st;
 
void init() {
    st.resize(euler.size() * 4);
}
 
void build(int s, int l, int r) {
 
    if(l == r) st[s] = euler[l];
    else {
 
        build(left(s), l, (l+r)/2);
        build(right(s), (l+r)/2 + 1, r);
 
        int L = st[left(s)];
        int R = st[right(s)];
        st[s] = height[L] < height[R] ? L : R;
    }
 
}
 
int query(int s, int l, int r, int a, int b) {
    
    if(a > r || b < l) return -1;
    if(l >= a && r <= b) return st[s];
    int L = query(left(s), l, (l + r)/ 2, a, b);
    int R = query(right(s), (l + r)/ 2 + 1, r, a, b);
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
 
