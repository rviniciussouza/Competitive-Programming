#include <bits/stdc++.h>
using namespace std;

long double dist(int xi, int yi, int xr, int yr) {

    return sqrt(pow(xi-xr,2) + pow(yi - yr, 2));

}

int main() {

    int xi, yi, xr, yr, V, xl, yl, xf, yf;


    while(cin >> xi >> yi >> xf >> yf >> V) {
        cin >> xl >> yl >> xr >> yr;

        long double ans1 = (dist(xi, yi, xl, yl) + dist(xr, yl, xf, yf) + xr-xl) ;
        long double ans2 = (dist(xi, yi, xl, yr) + dist(xr, yr, xf, yf) + xr-xl) ;

        printf("%.1LF\n", min(ans1/V, ans2/V));
    }

    return 0;
}