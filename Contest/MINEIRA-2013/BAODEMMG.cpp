#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	int t, k, valor;
	cin >> t;
	for(int i = 0; i < t; ++i) {
	
		int qtd = 0;
		
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> valor;
			qtd += valor * 3;
		}
		
		if(k * 3 >= qtd) {
			puts("nao precisa");
		}
		else {
			puts("precisa");
		}
	}
		
	

}
	
