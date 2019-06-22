#include <bits/stdc++.h>
using namespace std;

int main( ) {
	
	int C, u, v;
	
	cin >> C;
	
	for(int i = 0; i < C; ++i) {
	
		cin >> u >> v;
		int ans = 0;
		if(u < 0) {
			if(v < 0) {
				ans = (v * -1) - ( u * -1);
				ans *= -1;
			}
			
			else {
				ans = u * (-1);
				ans += v - 1;
			}
		}
		
		else {
			ans = v - u;
		}
		
		
		cout << ans << '\n';
		
	}
		
	
	
	return 0;
}
