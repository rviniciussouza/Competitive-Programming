#include <bits/stdc++.h>
using namespace std;

void fatorar(long long n) {

    int k = 0;
    while(n%2 == 0) {
        if(k > 0) printf(" x ");
        printf("2");
        n /= 2;
        k++;
    }

    for(int i = 3; i <= sqrt(n); i += 2) {
        while(n%i == 0) {
            if(k > 0) printf(" x ");
            printf("%d", i);
            n /= i;
            k++;
        }
    }

    if(n > 2) {
        
        if(k > 0) printf(" x %lld\n", n);
        else printf("%lld\n", n);
    }
    else printf("\n");
}

int main()  {

    long long n;
    while(1) {
        scanf("%lld", &n);
        if(n == 0) break;

        printf("%lld = ", n);

        if(n < 0) {
            printf("-1 x ");
            n = -1 * n;
        }
        fatorar(n);

    }

    return 0;
}