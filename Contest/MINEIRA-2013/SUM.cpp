#include <bits/stdc++.h>
using namespace std;

long long todec(char N[]) {
	
	int t = strlen(N);
	long long number = 0;
	for(int i = t - 1, j = 0; i >= 0; i--, ++j) {
		if(N[i] >= '0' && N[i] <= '9')
			number += (N[i]-'0') * pow(36, j);
		else {
			number += (N[i]-'A'+10) * pow(36, j);
		}
	}

	return number;
}

vector<char> to_base36(long long N) {
	
	vector<char> ans;
	int resto;
	
	while(N > 0) {
		resto = N % 36;
		N = N/36;
		if(resto <= 9) ans.push_back(resto + '0');
		else ans.push_back(resto + ('A' - 10));
	}
	return ans;
}

int main() {
	
	char A[10], B[10];
	
	while(true) {
	
		scanf("%s %s", A, B);
		if(A[0] == '0' && B[0] == '0') break;
	
		long long sum = todec(A) + todec(B);
		vector<char> ans = to_base36(sum);
		
		reverse(ans.begin(), ans.end());
		
		for(int i = 0; i < ans.size(); ++i) {
			cout << ans[i];
		}
		cout << '\n';
		
	}
	
	return 0;
}
