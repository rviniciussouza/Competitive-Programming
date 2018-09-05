#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main()
{
    int n, t = 0;
    while(scanf("%d", &n) && n)
    {
        if(t == 1) printf("\n"); //Essa verificacao é necessaria para dar quebra de linha entre os casos de teste
        t = 1;

        for(int i=0; i < n; ++i)
            scanf("%d", &a[i]);

        sort(a, a+n);
        
        int bolsaLivre = 1; //Numero de bolsas iguais até encontrar uma maior
        int minBolsa = 0; //Minimo de bolsas
        a[n] = -1; //Se caso a ultima bolsa for livre
        for(int i=1; i <= n; ++i)
        {
            if(a[i] == a[i-1]) bolsaLivre++;
            else
            {
                if(bolsaLivre > minBolsa) minBolsa = bolsaLivre;
                bolsaLivre = 1;            
            }     
        }

        printf("%d\n", minBolsa);
        for(int i=0; i < minBolsa; ++i)
        {
            printf("%d", a[i]);
            for(int j=i+minBolsa; j < n; j+=minBolsa)
                printf(" %d", a[j]);
            printf("\n");
        }
    }

    return 0;
}