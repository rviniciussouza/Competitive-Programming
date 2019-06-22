#include <stdio.h>
#include <iostream>
using namespace std;

int b[1000010];

void pre(string pattern) {

    b[0] = -1;
    int n = pattern.size();

    for(int i = 0, j = -1; i < n;) {
        while(j >= 0 && pattern[i] != pattern[j]) j = b[j];
        b[++i] = ++j;
    }

}

int main() {

    string text, pattern;

    while(true) {

        cin >> pattern;
        if(pattern == ".") break;

        pre(pattern);
        int n = pattern.size();

        if(n % (n - 1- b[n-1]) == 0) {
            printf("%d\n", n / (n - 1 - b[n-1]));
        }
        else printf("1\n");

    }

    return 0;
}