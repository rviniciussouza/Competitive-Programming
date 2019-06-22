#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define maxn 100005
#define PI acos(-1)

bool aberto[maxn];

struct pv {
    int id;
    ll x, y;
    pv (ll x, ll y, int id) {
        this->x = x;
        this->y = y;
        this->id = id;
    }   
};

vector<pv> pts;

ll cross (const pv a, const pv b) {
    return a.x * b.y - a.y * b.x;
}

ll norm (const pv a) {
    return (a.x) * (a.x) + (a.y) * (a.y);
}

ll dot (const pv a, const pv b) {
    return a.x * b.x + a.y * b.y;
}

double angulo(const pv a, const pv b) {
    //~ cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << endl;
    //~ cout << acos(dot(a, b) / (sqrt(dot(a, a)) * sqrt(dot(b, b)))) << endl;
    if (cross(a, b) > 0)
        return PI * 2.0 - acos(dot(a, b) / (sqrt(norm(a)) * sqrt(norm(b))));
    return acos(dot(a, b) / (sqrt(norm(a)) * sqrt(norm(b))));
}

bool compare (const pv a, const pv b) {
    ll current = cross(a, b);
    if (current > 0)
        return true;
    if (current < 0)
        return false;
    if ((a.x < 0 and b.x >= 0) or (a.x >= 0 and b.x < 0))
        return a.x < b.x;
    if ((a.y < 0 and b.y >= 0) or (a.y >= 0 and b.y < 0))
        return a.y < b.y;
    return norm(a) < norm(b);
}

main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i=0;i<n;i++) {
        ll x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        
        if (x1==x2 && y1==y2) continue;
        
        pts.push_back(pv(x1, y1, i));
        pts.push_back(pv(x2, y2, i));
    }
    
    sort(pts.begin(), pts.end(), compare);
    //~ for (auto i : pts)
        //~ cout << i.x << ' ' << i.y << ' ' << i.id << endl;
    
    pts.push_back(pv(pts[0].x, pts[0].y, n));

    int last = -1;
    int cont = 0;
    double ans = 0;
    for (int i=0;i<pts.size();i++) {
        if (pts[i].id == n) {
            if (cont >= k) {
                ans += angulo(pts[last], pts[i]);
                //~ cout << "ang " << last << " " << i << " = " << angulo(pts[last], pts[i]) << endl;
            }
            continue;
        }
        if (aberto[pts[i].id]) {
            //~ printf("fechou %d\n", pts[i].id);
            aberto[pts[i].id] = 0;
            cont--;
            if (cont == k-1) {
                ans += angulo(pts[last], pts[i-1]);
                //~ cout << "ang " << last << " " << i << " = " << angulo(pts[last], pts[i]) << endl;
            }
        } else {
            //~ printf("abriu %d\n", pts[i].id);
            aberto[pts[i].id] = 1;
            cont++;
            if (cont == k) {
                last = i;
            }
        }
    }
    
    printf("%.10lf\n", ans*180 / (PI*360) );
}