#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, v[55];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	
	int ant = v[n-1], ans = 1;
	for(int i = n-2; i >= 0; i--) {
		if(v[i] < ant) {
			ans++; 
		}
		
		ant = v[i];
	}
	
	printf("%d\n", ans);

	return 0;
}
