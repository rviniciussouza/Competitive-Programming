#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, d, n, x, y, p;
    scanf("%d", &t);

    while(t--)
    {

        vector<vector<int> > grid(1024, vector<int>(1024, 0));

        scanf("%d", &d);
        scanf("%d", &n);

        for(int i=0; i < n; ++i)
        {
            scanf("%d %d %d", &x, &y, &p);

            for(int j=x-d; j <= x+d; ++j)
                if(j >= 0 && j < 1024)
                    for(int k=y-d; k <= y+d; ++k)
                        if(k >= 0 && k < 1024)
                            grid[j][k] += p;
        }

        long max = LONG_MIN;
        for(int j=0; j < 1024; ++j) {
            for(int k=0; k < 1024; ++k) {
                if(grid[j][k] > max) {
                    x = j;
                    y = k;
                    max = grid[j][k];
                }
            }
        }

        printf("%d %d %ld\n", x, y, max);
    }

    return 0;
}