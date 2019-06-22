#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli MN = 112345;
#define INF 1000000000


lli merge_sort(vector<pair<lli, lli> > &v){
	
	// declaro inv, o total de inversões
	lli inv=0;
	
	// se o tamanho de v for 1, não há inversões
	if(v.size()==1) return 0;
	
	// se não
	
	// declaro os vetore u1 e u2
	vector<pair<lli, lli> > u1, u2;
	
	// e faço cada um receber uma metade de v
	for(lli i=0;i<v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(lli i=v.size()/2;i<v.size();i++){
	 	u2.push_back(v[i]);
	}	
	// ordeno u1 e u2
	// e adiciono a inv as inversões de cada metade do vetor
	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	// e adiciono INF ao final de cada um deles
	u1.push_back(make_pair(INF, INF));
	u2.push_back(make_pair(INF, INF));
	
	// declaro ini1 e ini2 com valore inicial zero
	lli ini1=0, ini2=0;
	
	// percorro cada posição de v
	for(lli i=0;i<v.size();i++){
		
		// se o menor não usado de u1 for menor o mesmo em u2
		if(u1[ini1].second <= u2[ini2].second){
			
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

    lli X, Y, H, V, u, v;

    cin >> X >> Y;
    cin >> H >> V;

	vector<pair<lli, lli> > tipo1;
	vector<pair<lli, lli> > tipo2;

    for(lli i = 0; i < H; ++i) {
        cin >> u >> v;
        tipo1.push_back(make_pair(u, v));
    }

    for(lli i = 0; i < V; ++i) {
        cin >> u >> v;
        tipo2.push_back(make_pair(u, v));
    }

    sort(tipo1.begin(), tipo1.end());
    sort(tipo2.begin(), tipo2.end());

    lli ans = (H + 1) * (V + 1);
    ans += merge_sort(tipo1);
    ans += merge_sort(tipo2);
    cout << ans << '\n';

    return 0;

}
