#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
    vector<vector<int> > notas(12, vector<int>(12, 0));
    int n, x, i, j;
    vector<int> m;

    string c[13] = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si","desafinado"};

    ios_base :: sync_with_stdio(0); cin.tie(0);

    for(i=0; i < 12; i++)
    {
        for(j=0; j < 3; j++)
            notas[i][(i + (j * 2)) % 12] = 1;

        notas[i][(i+5) % 12] = 1;

        for(j=3; j < 6; j++)
            notas[i][(i + 2 * j + 1) % 12] = 1;
    }

    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>x;
        m.push_back((x - 1) % 12);
    }

    for(i=0; i < 12; i++)
    {
        for(j=0; j < n; j++)
        {
            if(notas[i][m[j]] == 0)
                break;
        }

        if(j == n)
            break;
    }

    cout<<c[i]<<endl;

    return 0;
}