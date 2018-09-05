#include <bits/stdc++.h>
using namespace std;

#define MAX_n 1005

int n, m, t;
char g[MAX_n][MAX_n];
int c[MAX_n][MAX_n];
int novinhas[MAX_n * MAX_n];
vector<pair<int, int> > lugar;

int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};

int verify(int x, int y)
{
	return x >=0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y)
{
	c[x][y] = t;
	novinhas[t]++;

	for(int k=0; k < 4; ++k)
	{
		int i = x + dX[k];
		int j = y + dY[k];

		if(verify(i, j))
			if(g[i][j] == 'n' && !c[i][j])
				dfs(i, j);
	}
}

int vemNovinha(int x, int y)
{
	set<int> s;

	for(int k=0; k < 4; ++k)
	{
		int i = x + dX[k];
		int j = y + dY[k];

		if(verify(i, j))
			if(g[i][j] == 'n') s.insert(c[i][j]);
	}

	int sum = 0;
	for(int k : s)
		sum+= novinhas[k];
	
	return sum;

}

int main()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	scanf("%d %d", &n, &m);

	for(int i=0; i < n; ++i)
	{
		for(int j=0; j < m; ++j)
		{
			scanf(" %c", &g[i][j]);
			if(g[i][j] == '*') lugar.push_back(make_pair(i, j));
		}
	}

	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			if(!c[i][j] && g[i][j] == 'n') {
				t++;
				dfs(i, j);
			}
	
	int maior = -1; int Px, Py, p;
	for(int i=0; i < lugar.size(); ++i)
	{
		p = vemNovinha(lugar[i].first, lugar[i].second);
		if(p > maior)
		{
			maior = p;
			Px = lugar[i].first;
			Py = lugar[i].second;
		}
	}

	printf("%d,%d\n", Px+1, Py+1);

	return 0;
}
