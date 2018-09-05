#include <bits/stdc++.h>
using namespace std;

/*
 * Segmet Tree para consultas RMQ E RSQ
 * github @rviniciusouza
 */

#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

typedef vector<int> vv;

vv st, arr;

void buildUtil(int si, int l, int r) {
    if(l == r) st[si] = arr[r];
    else {
        buildUtil(left(si), l, (l + r) / 2);
        buildUtil(right(si), (l + r) / 2 + 1, r);
        st[si] = st[left(si)] + st[right(si)];
    }
}

void build(int n) {
    st.resize(4 * n);
    buildUtil(1, 0, n-1);
}

void update(int si, int l, int r, int a, int b, int value) {
    if(a > r || b < l) return;
    if(l == r) {
        printf("%d\n", r);
        st[si] += value;
    }

    else {
        update(left(si), l, (l + r) / 2, a, b, value);
        update(right(si), (l + r) / 2 + 1, r, a, b, value);
        st[si] = st[left(si)] + st[right(si)];
    }
}

int getSum(int si, int l, int r, int a, int b) {
    if(l >= a && r <= b) return st[si];
    if(a > r || l > b) return 0;
    return getSum(left(si), l, (l + r) / 2, a, b) +
           getSum(right(si), (l + r) / 2 + 1, r, a, b);
}

int main() {
    
    int n;
    cin >> n;
    for(int i=0; i < n; ++i) {
        arr.push_back(i);
    }

    build(n);

    update(1, 0, n - 1, 0, 10, 1);

    cout << getSum(1, 0, n - 1, 0, 5) << '\n';
    
    return 0;
}