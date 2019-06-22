#include <stdio.h>

long long v[4100];

long long ger(int n) {
	
	long long ans = 0, k = 1;
	while(n > 0) {
		ans += (n % 2) * k;
		n /= 2;
		k = k * 10;
	}
	return ans;
}

int main() {
	
	
	for(int i = 1; i < 4096; ++i) {
		v[i] = ger(i);
	}
	
	bool flag;
	for(long long i = 1; i < 1000000000; ++i) {
		flag = false;
		for(int j = 1; j < 4096; ++j) {
			if(i % v[j] == 0) {
				printf("v[%lld] = %lld;\n", i, v[j]);
				flag = true;
				break;
			}
		}
		if(!flag) printf("v[%lld] = -1;", i);
	}
		
	return 0;
}
