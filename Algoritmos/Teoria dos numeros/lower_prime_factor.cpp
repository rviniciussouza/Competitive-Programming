#include <bits/stdc++.h>

/************************
 * Retorna o menor fator
 * primo de um inteiro n
 * **********************/

int solve(int n)
{
    vector<int> least(n+1, 0);
    least[1] = 1;

    for(int i = 2; i <= n; ++i) {
        if(least[i] == 0) {
            least[i] = i;
            for(int j=i * 2; j <= n; j += i)
                if(least[j] == 0) least[j] = j;
        }
    }

    return least[n];
}