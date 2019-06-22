// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    string number;

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> number;

        string A, B;
        int ult;

        for(int j = number.size()-1;  j >= 0; j--) {

            int alg = number[j] - '0';
            if(alg == 4) {
                A.insert(0,1,'2');
                B.insert(0,1,'2');
                ult = j;
            }

            else {
                A.insert(0,1,number[j]);
                B.insert(0,1,'0');
            }
        }

        B.erase(B.begin(), B.begin()+ult);
        
        cout << "Case #" << i << ": " << A << " " << B << '\n';

    }

    return 0;
}