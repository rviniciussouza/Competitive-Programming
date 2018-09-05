#include <bits/stdc++.h>
using namespace std;

typedef pair<string, float> ii;

int main() {
    int n, t, q, qtd;    
    string fruta;
    float preco, compra;
    cin >> t;
    while(t--) {
        cin >> n;
        map<string, float> mapa;
        for(int i=0; i < n; ++i) {
            cin >> fruta >> preco;
            mapa.insert(ii(fruta, preco));
        }

        cin >> q;
        compra = 0.0;
        for(int i=0; i < q; ++i) {
            cin >> fruta >> qtd;
            compra += mapa.find(fruta)->second * qtd;
        }

        cout << fixed;
        cout << "R$ " << setprecision(2) << compra << '\n';
    }
    return 0;
}