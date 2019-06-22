#include <vector>
#include <iostream>
#include <utility>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<long long> vi;

const long long MN = 110;
const long long INF = 1000110;

int G[MN][1100];

int main() {

    int n;

    cin >> n; 
    
    for(int i = 0; i < n; ++i) {
        cin >> G[i][0];
        for(int j = 1; j <= G[i][0]; ++j) {
            cin >> G[i][j];
        }
    }   

    long long best = INF;
    long long pos;
    for(int i = 0; i < n; ++i) {
        int m = G[i][0];

        long long sum = 0L;
        long long ant = INF;
        for(int j = 1; j <= m; ++j) {
            if(G[i][j] > ant) sum += (G[i][j] - ant);
            ant = G[i][j];
        }

        // printf("%lld\n", sum);

        if(sum < best) {
            best = sum;
            pos = i;
        }

        ant = INF, sum = 0L;
        for(int j = m; j >= 1; --j) {
            if(G[i][j] > ant) sum += (G[i][j] - ant);
            ant = G[i][j];
        }

        // printf("%lld\n", sum);

        if(sum < best) {
            best = sum;
            pos = i;
        }

    }

    printf("%lld\n", pos + 1);


    return 0;
}