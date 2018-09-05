#include <bits/stdc++.h>
using namespace std;


int a[20010];
int b[20010];


int main()
{
    bool fail;
    int n, m, t;
    while(scanf("%d %d", &n, &m) && n)
    {
        for(int i=0; i < n; ++i) scanf("%d", &a[i]);
        for(int i=0; i < m; ++i) scanf("%d", &b[i]);

        sort(a, a+n);
        sort(b, b+m);

        fail = false;
        t = 0;

        for(int i=0, j = 0; i < n; ++i)
        {
            while(j < m && a[i] > b[j]) ++j;

            if(j == m) fail = true;
            else t += b[j++];
        }

        if(fail) printf("Loowater is doomed!\n");
        else printf("%d\n", t);

    }

    return 0;
}