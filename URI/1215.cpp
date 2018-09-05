#include <bits/stdc++.h>
using namespace std;

int main(){

    char s[205];
    char *pch;
    int len;

    set<string> ss;

    while(scanf("%s", s) == 1) {

        getchar();

        if(!(len = strlen(s))) continue;

        for(int i=0; i < len; ++i) {
            s[i] = tolower(s[i]);
            if(s[i] < 'a' || s[i] > 'z') s[i] = 32;
        }

        pch= strtok(s, " ");
        while(pch != NULL) {
            if(strlen(pch)) ss.insert(pch);
            pch = strtok(NULL, " ");
        }
    }

    set<string>::iterator it;
    for(it = ss.begin(); it != ss.end(); it++) {
        printf("%s\n", (*it).c_str());
    }

    return 0;
}