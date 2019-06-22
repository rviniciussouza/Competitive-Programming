#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000 + 10

vector<pair<int, int> > pontos(MAXN);
int dp_up[MAXN], dp_down[MAXN];

int main() {

	int x, y, n;

	while(scanf("%d", &n) == 1) {
		for(int i = 0;  i < n; ++i) {
			scanf("%d %d", &x, &y);
			pontos[i] = make_pair(x, y);
		}

		sort(pontos.begin(), pontos.begin() + n);


		// cout << pontos[n-1].first << ' ' << pontos[n-1].second;

		dp_down[0] = 1;
		dp_up[0] = 1;

		for(int i = 1; i < n; ++i) {
			int maxup = 1;
			int maxdown = 1;

			for(int j = 0; j < i; ++j) {
				if(pontos[i].first != pontos[j].first && pontos[i].second - pontos[j].second == 2) {
					maxup = max(maxup, dp_down[j] + 1);
				}

				if(pontos[i].first != pontos[j].first && pontos[j].second - pontos[i].second == 2) {
					maxdown = max(maxdown, dp_up[j] + 1);
				}
			}

			dp_up[i] = maxup;
			dp_down[i] = maxdown;
		}

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			ans = max(ans, dp_up[i]);
			ans = max(ans, dp_down[i]);
		}	

		printf("%d\n", ans);

	}

	return 0;
}