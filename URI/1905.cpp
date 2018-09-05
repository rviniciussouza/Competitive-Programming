#include <bits/stdc++.h>
using namespace std;

int v[5][5];

bool busca(int r, int c) {
    if(c > 4 || r > 4) return false;
    if(v[c][r] == 1) return false;
    if(r == 4 && c == 4) return true;
    return busca(r, c+1) || busca(r+1, c);
}

int main()
{
    int n;
    cin >> n;

    while(n--) {

        for(int i=0; i < 4; ++i)
            for(int j=0; j < 4; ++j)
                cin >> v[i][j];

        if(busca(0,0)) cout << "COPS" << '\n';
        else cout << "ROBBERS" << '\n';
    }

    return 0;
}