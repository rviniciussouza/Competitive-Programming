#include <bits/stdc++.h> 
using namespace std; 

const long long MN = 100010;

long long BITree[MN], v[MN];

long long getSum(long long index) 
{ 
	long long sum = 0;
	index = index + 1; 
	while (index>0) {  
		sum += BITree[index];  
		index -= index & (-index); 
	} 
	return sum; 
} 
 
void updateBIT(long long n, long long index, long long val) 
{
	index = index + 1;  
	while (index <= n)  { 
		BITree[index] += val;  
		index += index & (-index); 
	} 
} 
 
int main() 
{ 

	long long N, valor;
	
	while(scanf("%lld", &N) != EOF) {
		
		
		for(long long i = 0; i <= N; ++i) BITree[i] = 0LL;
		
		for(long long i = 0; i < N; ++i) {
			scanf("%lld", &valor);
			v[valor-1] = i;
			updateBIT(N, i, 1);
		}
	
		/*
		printf longf("%d\n", getSum(BIT, N-1));
		printf longf("%d\n", getSum(BIT, N-1) - getSum(BIT, 2));
		printf longf("%d\n", getSum(BIT, N-1)); */
			
		long long ans = 0;
		for(long long i = 0; i < N; ++i) {
			ans += getSum(N-1) - getSum(v[i] - 1) - 1;
			updateBIT(N, v[i], -1);
		}

		printf("%lld\n", ans);
	}

	return 0; 
} 
