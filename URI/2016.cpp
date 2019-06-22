#include <stdio.h>
using namespace std;

int carta[] = {10000, 1000, 100, 10, 1};

int main() {

    int n, m, d, a, b, sum, ans ,sumb;

    scanf("%d %d", &n, &m);

    ans = 0, sumb = 0;
    for(int i = 0; i < m; ++i) {

        scanf("%d", &d);
        scanf("%d", &b);
        
        sum = 0;
        for(int j = 1; j < n; ++j) {
            scanf("%d", &a);
            sum += a;
        }

        if(sum + b <= d) sumb += b; 
        
        for(int j = 0; j < 5; ++j) {
            if(sum + carta[j] <= d) {
                ans += carta[j];
                break;
            }
        }   
    }

    printf("%d\n", ans - sumb);

    return 0;
}