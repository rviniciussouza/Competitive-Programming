#include <bits/stdc++.h>
using namespace std;

int v[10010];
int t, n;

bool solve(int m, int l1, int l2) {
    if(m == n && abs(l1 - l2) <= 5) return true;
    if(abs(l1 - l2) > 5) return false;
    return solve(m+1, l1 + v[m], l2) || solve(m+1, l1, l2 + v[m]);
}

int main(){

    scanf("%d", &t);

    while(t--) {

        scanf("%d", &n);
        for(int i=0; i < n; ++i)
            scanf("%d", &v[i]);
        
        if(solve(0,0,0)) cout<<"Feliz Natal!"<<endl;
        else cout<<"Ho Ho Ho!"<<endl;
    }

    return 0;
}