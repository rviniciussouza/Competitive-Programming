#include <btis/stdc++.h>
using namespace std;

int bfs(int x, int y, int h) {

    if(vis[x][y] != 0) return 0;
    if(x < 0 or x >= n) return 0;
    if(y < 0 or y >= m) return 0;
    
    int ans = 0;
    ans = max(ans, BFS(x+1, y, h+1));
    ans = max(ans, BFS(x-1, y, h+1));
    ans = max(ans, BFS(x,y+1, h+1));
    ans = max(ans, BFS(x+1,y-1,h+1));

    return max(ans, h);
}

int main() {

    int n, m, k, ans;

    cin >> k;

    while(k--) {

        cin >> n >> m;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cin >> x >> y;

        memset(vis, 0, sizeof vis);

        cout << bfs(x, y, 1) << '\n';

    }

    return 0;
}