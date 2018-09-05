#include <bits/stdc++.h>
using namespace std;

/*
 * Segmet Tree para consultas RMQ E RSQ com
 * lazy propagation
 * github @rviniciusouza
 */

#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

typedef vector<int> vv;

vv st, lazy, arr;

void buildUtil(int si, int l, int r) {
    if(l == r) st[si] = arr[r];
    else {
        buildUtil(left(si), l, (l + r) / 2);
        buildUtil(right(si), (l + r) / 2 + 1, r);
        // st[si] = st[left(si)] + st[right(si)];
        st[si] = max(st[left(si)] , st[right(si)]);
    }
}

void build(int n) {
    st.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    buildUtil(1, 0, n-1);
}

void update(int si, int l, int r, int a, int b, int value) {
    if(lazy[si] != 0) {
        // st[si] += (r - l + 1) * lazy[si];
        st[si] +=  lazy[si];
        if(l != r) {
            lazy[left(si)] += lazy[si];
            lazy[right(si)] += lazy[si];
        }
        lazy[si] = 0;
    }
    
    if(a > r || b < l) return;

    if(l >= a && r <= b) {
        // st[si] += (r -l + 1) * value;
        st[si] += value;
        if(l != r) {
            lazy[left(si)] += value;
            lazy[right(si)] += value;
        }
    }

    else {
        update(left(si), l, (l + r) / 2, a, b, value);
        update(right(si), (l + r) / 2 + 1, r, a, b, value);
        // st[si] = st[left(si)] + st[right(si)];
        st[si] = max(st[left(si)], st[right(si)]);
    }
}

int getSum(int si, int l, int r, int a, int b) {
    if(lazy[si] != 0) {
        // st[si] += (r - l + 1) * lazy[si];
        st[si] += lazy[si];
        if(l != r) {
            lazy[left(si)] += lazy[si];
            lazy[right(si)] += lazy[si];
        }
        lazy[si] = 0;
    }    

    if(l >= a && r <= b) return st[si];
    if(a > r || l > b) return 0;
    return max(getSum(left(si), l, (l + r) / 2, a, b),
           getSum(right(si), (l + r) / 2 + 1, r, a, b));
}

int main() {
    
    int n;
    cin >> n;
    for(int i=0; i < n; ++i) {
        arr.push_back(0);
    }

    build(n);

    update(1, 0, n - 1, 0, 4, 1);
    update(1, 0, n - 1, 2, 4, 10);

    cout << getSum(1, 0, n - 1, 0, 1) << '\n';
    
    return 0;
}