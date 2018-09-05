#include <bits/stdc++.h>

#define MAX 51

using namespace std;
int n, c, time_s, visit[MAX];
vector<int> ADJ[MAX]; 

int dfs(int u, int pai, vector<pair<int,int> >& ans){  
    int menor = visit[u] = time_s++;
    int filhos = 0;
    for(int i = 0; i<ADJ[u].size(); i++){
       if(visit[ADJ[u][i]]==0){
          filhos++;
          int m = dfs(ADJ[u][i], u, ans);
          menor = min(menor,m);
          if(visit[u]<m){
              ans.push_back(make_pair(u, ADJ[u][i]));
          }
       }else if(ADJ[u][i]!=pai){
          menor = min(menor, visit[ADJ[u][i]]);
       }
    } 
    return menor;      
}

vector<pair<int,int> > get_articulacoes(){
    vector<pair<int,int> > ans;
    time_s = 1;
    memset(visit, 0, n*sizeof(int));
    dfs(0,-1,ans);
    return ans;
}

int main() {
    while(scanf("%d %d", &n, &c) != EOF) {
        for(int i=0; i < c; ++i) {
            scanf("%d %d", &u, &v);
            ADJ[u].push_back(v);
        }

        cout<<get_articulacoes()<<endl;
    }
}