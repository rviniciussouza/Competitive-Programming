#include <set>
#include <iostream>
using namespace std;


int main() {

    set<int> T;
    T.insert(11);
    T.insert(9);
    T.insert(3);
    T.insert(0);
    T.insert(10);
    T.insert(6);
    T.insert(18);
    T.insert(5);

    for(set<int>::iterator it = T.begin(); it != T.end(); it++) {
        cout << *it << '\n';
    }

}
