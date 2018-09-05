#include <bits/stdc++.h>
using namespace std;

bool compare(int x, int y)
{
    return (y < x);
}


int main()
{
    int t, n, a[20];

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i < n; ++i)
            scanf("%d", &a[i]);
        
        sort(a, a+n, compare);

        int total = 0;
        for(int i=0; i < n; i+=3)
        {
            if((i + 2) < n)
            total += a[i+2];
        }

        printf("%d\n", total);    
    }

    return 0;
}