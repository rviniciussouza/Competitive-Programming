#include <bits/stdc++.h>

#define max_n 1000
int v[max_n];

/* subsequencia de valor maximo */

int kadane(int n){
    int soma, ans;
    soma = ans = 0;

    for(int i=0; i < n; ++i) {
        soma = soma + v[i];
        ans = std::max(ans, soma);
        if(soma < 0) soma = 0;
    }

    return ans;
}

int main(){
    int n;
    std::cin>>n;
    for(int i=0; i < n; ++i) std::cin>>v[i];
    std::cout<<kadane(n)<<std::endl;

    return 0;
}