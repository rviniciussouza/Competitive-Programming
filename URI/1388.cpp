#include <bits/stdc++.h> 
using namespace std; 

const long long MN = 100010;

long long BIT[MN], v[MN];

long long getSum(long long index) 
{ 
	long long sum = 0;
	index = index + 1; 
	while (index>0) {  
		sum += BIT[index];  
		index -= index & (-index); 
	} 
	return sum; 
} 
 
void updateBIT(long long n, long long index, long long val) 
{
	index = index + 1;  
	while (index <= n)  { 
		BIT[index] += val;  
		index += index & (-index); 
	} 
} 


int main() {

    long long N, M, x;

    memset(BIT, 0LL, sizeof BIT);
	
    scanf("%lld %lld", &N, &M);
    for(int i = 1; i <= M; ++i) {
        scanf("%lld", &x);
        int pos = getSum(N-1) - get(i-1);
        
    }

    return 0;

}