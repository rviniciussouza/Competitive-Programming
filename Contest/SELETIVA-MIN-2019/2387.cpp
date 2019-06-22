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

const long long MN = 1010;
const long long INF = 10000000001110;

int main() {

    
    int n, x, y;

    cin >> n;

    ii v[n];

    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        v[i] = make_pair(y, x);
    }

    sort(v, v + n);

    int ant = -1, ans = 0;
    for(int i = 0; i < n; ++i) {
        if(v[i].second >= ant) { //inicio > ant
            ans++;
            ant = v[i].first; //ant = final
        }
    }

    cout << ans << '\n';

    return 0;
}