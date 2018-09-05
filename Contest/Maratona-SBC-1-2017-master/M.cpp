#include <stdio.h>

int main(void)
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    int ans = 10000000;

    if((B * 2 + C * 4) < ans)
        ans = B * 2 + C * 4;

    if((A * 2 + C * 2) < ans)
        ans = A * 2 + C * 2;
    
    if((B * 2 + A * 4) < ans)
        ans = B * 2 + A * 4;

    printf("%d\n", ans);
    return 0;
}