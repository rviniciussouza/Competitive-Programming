#include <vector> // para o uso de vector
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

long long merge_sort(vector<long long> &v){
	
	long long inv=0;	
	if(v.size()==1) return 0;
	vector<long long> u1, u2;
	for(long long i=0;i<v.size()/2;i++)
		u1.push_back(v[i]);
	for(long long i=v.size()/2;i<v.size();i++)
	 	u2.push_back(v[i]);
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	u1.push_back(INF);
	u2.push_back(INF);
	long long ini1=0, ini2=0;
	for(long long i=0;i<v.size();i++){
		// Comparacao da ordenacao
        if(u1[ini1]<=u2[ini2]){
			v[i]=u1[ini1];
			ini1++;
		}
		else{
			v[i]=u2[ini2];
			ini2++;
			inv+=u1.size()-ini1-1;
		}
	}
	return inv;
}

int main() {

	long long N, valor;
	while(scanf("%lld", &N) == 1) {
	
		vector<long long> v;
		
		for(long long i = 0; i < N; ++i) {
			scanf("%lld", &valor);
			v.push_back(valor);
		}
		
		reverse(v.begin(), v.end());
		
		printf("%lld\n", merge_sort(v));
	}
	return 0;
}
