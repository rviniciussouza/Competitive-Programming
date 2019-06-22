#include <bits/stdc++.h>
using namespace std;

typedef long long LLi;
typedef pair<string, int> ii;
const LLi INF = 1000000000000; 

bool compare(ii a, ii b) {
    return a.first.size() > b.first.size();
}

int main() {

    int t, n;
    cin >> t;
    for(int k = 1; k <= t; ++k) {

        cin >> n;

        vector<string> v(n);
        vector<pair<string, int> > ger;

        for(int j = 0; j < n; ++j) {
            cin >> v[j];
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < v[i].size(); ++j) {
                ger.push_back(make_pair(v[i].substr(j, v[i].size() - j + 1), i));
            } 
        }

        int cnt = 0, ant, ans = 0;
        set<string> used;

        sort(ger.begin(), ger.end(), compare);

        bool mark[n];
        memset(mark, false, sizeof mark);

        for(int i = 0; i < ger.size(); ++i) {
            cnt = 0;
            if(used.find(ger[i].first) != used.end() or mark[ger[i].second]) continue;

        // printf("%d\n", ans);
                    
            // cout << ger[i].first <<   '\n';

            for(int j = i + 1; j < ger.size(); ++j) {
                // cout << "------" << ger[j].first <<   '\n';
                
                if(ger[i].first == ger[j].first && mark[ger[j].second] == false) {
                    cnt++;   
                    ant = ger[j].second;
                    break;
                }
            }

            if(cnt >= 1) {
                ans += 2;
                used.insert(ger[i].first);
                mark[ger[i].second] = true;
                mark[ant] = true;
            } 
        }

        printf("Case #%d: %d\n", k, ans);

    }
    

    return 0;
}