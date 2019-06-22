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
    int l;
    cin >> l;
    cout << "Ent" + f(l) + "o eh N" + f(l) + "t" + f(l) + "l!" << '\n';

}