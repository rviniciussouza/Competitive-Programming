#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;
int A[MN], B[MN];


int main() {

    int n;
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        for(int i = 0; i < n; ++i) {
            scanf("%d", &B[i]);
        }

        int ida = -1, volta = -1;

        bool flag;
        for(int i = 0, w = 0; i < n; ++i) {
            flag = false;
            for(int j = i, k = 0; k < n; j = (j+1)%n, k++) {
                w += A[j];
                w -= B[j];
                if(w < 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                ida = i; 
                break;
            }
        }

        for(int i = 0, w = 0; i < n; ++i) {
            flag = false;
            for(int j = i, k = 0; k < n; j = (j-1+n-1)%n, k++) {
                w += A[j];
                w -= B[j];
                if(w < 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                volta = i; 
                break;
            }
        }

        if(ida != -1) ida++;
        if(volta != -1) volta++;
        printf("%d %d\n", ida, volta);
    }
}