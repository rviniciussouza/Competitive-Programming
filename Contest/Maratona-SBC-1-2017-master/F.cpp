#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, min, x, t = 0;
    int p[1010];

    scanf("%d %d", &n, &min);
    memset(p, 0, sizeof(p));

    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        p[x]++;
    }

    for(int i = 1000; i >= 1 && min > 0; i--)
    {
        if(p[i] > 0)
        {
            t+= p[i];
            min = min - p[i];
        }
    }

    printf("%d\n", t);
}