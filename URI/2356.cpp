#include <bits/stdc++.h>
using namespace std;

char P[110]; //PATTERN
char T[110]; //TEXT
int  b[110];
int m;

void kmp() {
    b[0] = -1;
    m = strlen(P);
    for(int i=0, j = -1; i < m;) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

bool match() {
    int n = strlen(T);
    for(int i=0, j=0; i < n;) {
        while(j >=0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m) {
            return true;
        }
    }
    return false;    
}
int main() {

    while(scanf("%s %s", T, P) == 2) {    

        kmp();
        if(match()) printf("Resistente\n");
        else printf("Nao resistente\n");

    }

    return 0;
}