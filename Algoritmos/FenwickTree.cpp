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

    long long N, valor;
    memset(BIT, 0LL, sizeof BIT);
	scanf("%lld", &N);
    
    updateBIT(N, 0, 1);
    updateBIT(N, 1, 2);
    updateBIT(N, 2, 3);
    cout << getSum(2) - getSum(0)<< '\n';

    return 0;

}