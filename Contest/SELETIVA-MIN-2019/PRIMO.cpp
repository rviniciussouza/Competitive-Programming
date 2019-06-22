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

const long long MN = 100010;
const long long INF = 10000000001110;

int main() {

    long long n;

    cin >> n;

    bool flag = false;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            flag = true;
            break;
        }
    }

    if(flag) printf("nao\n");
    else printf("sim\n");

    return 0;
}
