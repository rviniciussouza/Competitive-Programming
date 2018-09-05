#include <bits/stdc++.h>

bool check(int n, int m)
{
    int P[10], c;
    memset(P, 0, sizeof P);
    for(int i=0; i < 5; ++i)
    {
        c = (int)(n / pow(10, i)) % 10;
        if(P[c])
            return false;
        P[c] = 1;
    }
    
    for(int i=0; i < 5; ++i)
    {
        c = (int)(m / pow(10, i)) % 10;      
        if(P[c])
            return false;
        P[c] = 1;
    }

    return true;
}

int main()
{
    int n, t, count = 0;
    while(scanf("%d", &n), n){

    count++;
	if (count > 1)
		printf("\n");

    bool found = false;
    for(int i=1234; i * n < 98765; ++i)
    {
        t = i * n;
        if(check(i, t))
        {
            printf("%05d / %05d = %d\n", t, i, n);
			found = true;
        }
    }

    if(!found)
        printf("There are no solutions for %d.\n", n);
    
    }

    return 0;
}