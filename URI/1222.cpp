#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, c, len;
    string palavra;
    while(scanf("%d %d %d", &n, &l, &c) != EOF) {
        int carac = 0, p = 0;
        int linhas = 0;
        for(int i=0; i < n; ++i) {
            cin>>palavra;
            carac += palavra.size();

            if(carac == c) {
                linhas++;
                carac = 0;
            } 

            else if(carac > c) {
                carac = palavra.size() + 1;
                linhas++;
            }

            else if(i < n) {
                carac++;

                if(carac == c) {
                    carac = 0;
                    linhas++;
                }
            }

            if(linhas == l) {
                linhas = 0;
                p++;
            }
        }

        if(linhas || carac) p++;
        cout<<p<<endl;
    }

    return 0;
}