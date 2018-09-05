#include <bits/stdc++.h>
using namespace std;

int main(){
    int b;
    scanf("%d", &b);
    char str[1011];

    for(int i=0; i < b; ++i) {
        
        // std::getchar();
        // std::cin>>str;
        scanf(" %[^\n]s", str);

        int abre = 0;
        int diamantes = 0;

        int t = strlen(str);
        for(int j=0; j < t; ++j) {
            if(str[j] == '<') abre++;
            else if(str[j] == '>' && abre) {
                diamantes++;
                abre--;
            }
        }

        printf("%d\n", diamantes);
    
    }

    return 0;
}