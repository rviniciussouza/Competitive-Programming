#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> ii;

bool compare(ii a, ii b) {
    if(a.first.size() > b.first.size()) return true;
    if(a.first.size() == b.first.size()) {
        if(a.second < b.second) return true;
    }
    return false; 
}

int main(){

    int n, j;
    string line, word;
    
    cin >> n;
    cin.ignore();
    
    while(n--) {
        getline(cin, line);
        stringstream ss(line);

        vector<ii> v;
        int j = 1;
        while(ss >> word) v.push_back(ii(word, j++));
        
        sort(v.begin(), v.end(), compare);

        for(int i=0; i < v.size(); i++) {
            cout<<v[i].first;
            if(i + 1 == v.size()) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}