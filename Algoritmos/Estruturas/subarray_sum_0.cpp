#include <bits/stdc++.h>
using namespace std;

/*Find if there is a subarray with 0 sum */


bool find_array(int v[], int n) {
    
    unordered_map<int, bool> mapa;

    int sum = 0;
    for(int i=0; i < n; ++i) {
        sum = sum + v[i];
        if(sum == 0 || mapa[sum] == true) return true;
        mapa[sum] = true;
    }

    return false;
}

int main(){

    int n;

    cin >> n;
    int v[n];
    for(int i=0; i < n; ++i) cin >> v[i];
    if(find_array(v, n)) cout << "YES" << '\n';

    return 0;
}