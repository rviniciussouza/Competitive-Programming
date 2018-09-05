#include <bits/stdc++.h>
using namespace std;

vector<int> rank;
vector<int> parent;


int find(int i) {
    while(i != parent[i]) i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int x = find(i);
    int y = find(j);
    
    if(x == y) return; //isSameSet
    
    if(rank[x] > rank[y]) parent[y] = x;
    else {
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
}