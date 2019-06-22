
#include <bits/stdc++.h>
using namespace std;

int v[1048600];

int main() {

	long long N, C;
	
	cin >> C;
	
	for(int k = 0; k < C; ++k) {
	
		cin >> N;
		
		for(int i = 0; i < N; ++i) {
			cin >> v[i];
		}
		
		int sum = 0, inicio = 0, ans = 0; 
		for(int i = 0; i < N; ++i) {
			if(v[i] + sum == 42) {
				ans++;
				inicio = i + 1;
				sum = 0;
			}
			
			else if(v[i] + sum > 42) {
				while(v[i] + sum > 42) {
					sum -= v[inicio];
					inicio++;
				}
				
				sum += v[i];
				if(sum == 42) {
					ans++;
					inicio = i + 1;
					sum = 0;
				}
			}
			
			else {
				sum += v[i];
			}		
		}
		
		cout << ans << '\n';
	}

	return 0;

}
