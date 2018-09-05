#include <bits/stdc++.h>
using namespace std;

int compare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int c, s, w, caso = 1;
    while(scanf("%d %d", &c, &s) != EOF)
    {
        w = (2 * c) - 1;
        int massa[w+1];
        double imbalance, A;
        imbalance = A = 0.0;

        memset(massa, 0, sizeof massa);

        for(int i=0; i < s; ++i)
        {
            scanf("%d", &massa[i]);
            A += massa[i];
        }

        A /= c;

        qsort(massa, 2*c, sizeof(int), compare);
    
        printf("Set #%d\n", caso++);
        for(int i=0, j = w; i < c; ++i, --j)
        {
            printf(" %d:", i);
            if(massa[j])
                printf(" %d", massa[j]);

            if(massa[i])
                printf(" %d", massa[i]);                
            
            imbalance += fabs((massa[j] + massa[i]) - A);
            printf("\n");
        }

        printf("IMBALANCE = %.5lf\n\n", imbalance);
    
    }

    return 0;
}