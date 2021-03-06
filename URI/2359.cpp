#include <vector> // para o uso de vector
#include <iostream>
#include <algorithm>
using namespace std;

// neste código, irei definir INF como 1 bilhão
#define INF 1000000000

// função merge_sort que ordena um vector v
long long merge_sort(vector<long long> &v){
	
	// declaro inv, o total de inversões
	long long inv=0;
	
	// se o tamanho de v for 1, não há inversões
	if(v.size()==1) return 0;
	
	// se não
	
	// declaro os vetore u1 e u2
	vector<long long> u1, u2;
	
	// e faço cada um receber uma metade de v
	for(long long i=0;i<v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(long long i=v.size()/2;i<v.size();i++){
	 	u2.push_back(v[i]);
	}	
	// ordeno u1 e u2
	// e adiciono a inv as inversões de cada metade do vetor
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	// e adiciono INF ao final de cada um deles
	u1.push_back(INF);
	u2.push_back(INF);
	
	// declaro ini1 e ini2 com valore inicial zero
	long long ini1=0, ini2=0;
	
	// percorro cada posição de v
	for(long long i=0;i<v.size();i++){
		
		// se o menor não usado de u1 for menor o mesmo em u2
		if(u1[ini1]<=u2[ini2]){
			
			// então o coloco em v
			v[i]=u1[ini1];
			
			// e incremento o valor de ini1
			ini1++;
		}
		
		// caso contrário, faço o análogo com u2 e ini2
		else{
			
			v[i]=u2[ini2];
			ini2++;
			
			// não se esquecendo de adicionar o número de elementos em u1
			// ao total deinversões em v
			inv+=u1.size()-ini1-1;
		}
	}
	
	// por fim, retorno a quantidade de inversões
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
