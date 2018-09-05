#include <bits/stdc++.h>
using namespace std;

char P[255];
char T[255];
int  b[255];
int m;

void kmp() {
    b[0] = 0;
    m = strlen(P);
    for(int i=0, j = 0; i < m;) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

vector<int> match() {
    int n = strlen(T);
    vector<int> ans;
    for(int i=0, j=0; i < n;) {
        while(j >=0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m) {
            ans.push_back(i-j);
            j = b[j];
        }
    }
    return ans;
}
int main() {

    scanf("%s", P);
    scanf("%s", T);

    kmp();
    vector<int>  ans = match();

    for(int i=0; i < m; ++i) {
        printf("%c ", P[i]);
    }
    printf("\n");
    for(int i=0; i < m; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    for(int i=0; i < (int)ans.size(); ++i) {
        printf("%d", ans[i]);
    }

    return 0;
}