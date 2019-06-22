#include <stdio.h>

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int main() {

    long long n, a, b;
    while(true) {
        scanf("%lld %lld %lld", &n, &a, &b);
        if(!n) break;

        long long lcm =  (a * b) / gcd(a, b);
        long long ans =  n / a;
        ans += n / b;
        ans -= n / lcm;
        printf("%lld\n", ans);

    }
    return 0;
}