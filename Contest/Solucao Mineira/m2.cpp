#include <bits/stdc++.h>

using namespace std;

int cor[400];
string transf[400];
string dp[400];

int dfs(char i) {
    if (cor[i] == 1 || cor[i] == 3) { return 3; }
    if (cor[i] == 2) { return 2; }
    
    cor[i] = 1;
    int aeho = 2;
    for (int j=0;j<transf[i].size();j++){
        aeho = max(aeho, dfs(transf[i][j]));
    }
    return cor[i] = aeho;
}

string f(char c) {
    if (dp[c] != "") return dp[c];
    if (transf[c] == "" || transf[c] == "" + c) { return (dp[c] += c); }

    dp[c] = "";
    for (int i=0;i<transf[c].size();i++)
        dp[c] += f(transf[c][i]);
    return dp[c];
}

main() {
    int n;
    cin >> n;
    
    for (char i='a'; i<='z'; i++) transf[i] = dp[i] = "";
    for (int i=0;i<n;i++) {
        string a, b;
        
        cin >> a >> b;
        if (a == b) continue;
        transf[a[0]] = b;
    }
    for (char i='a'; i<='z'; i++) {
        if (!cor[i]) dfs(i);
    }
    int m;
    string s;
    cin >> m >> s;
    
    bool ok = 1;
    string ans = "";
    for (int i=0;i<s.size();i++) {
        if (cor[s[i]] == 3) ok = 0;
        else ans += f(s[i]);
        // printf("aeho %c %d\n", s[i], cor[s[i]]);
    }
        
    if (!ok) cout << "-1\n";
    else cout << ans << "\n";
}
