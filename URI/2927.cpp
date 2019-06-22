#include <bits/stdc++.h>
using namespace std;

string f(int l) {
    string str = "a";
    for(int i = 2; i <= l; ++i) {
        str = str + "a";
    }
    return str;
}

int main() {
    int a, c, x, y;
    cin >> a >> c >> x >> y;
    if(a <= (c-x-y-1)) cout << "Igor feliz!"  << '\n';
    else cout << "Igor bolado!" << '\n';
    return 0;

}