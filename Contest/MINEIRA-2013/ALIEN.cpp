#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, ans;
	string dna;
	set<string> S;
	
	while(scanf("%d", &n) == 1 && n != 0) {
		ans = 0;
		for(int i = 0; i < n; ++i) {
			cin >> dna;
			sort(dna.begin(), dna.end());
			if(S.find(dna) == S.end()) {
				ans++;
				S.insert(dna);
			}
		}
		cout << ans << '\n';
		S.clear();
	}
}
