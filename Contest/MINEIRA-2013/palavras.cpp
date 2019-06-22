#include <bits/stdc++.h>
using namespace std;
bool ordenada(char *s,int tam)
{
	for(int i=tam-1;i>0;i--)
	{
		if(s[i]<=s[i-1])return false;
	}
	return true;
}
int main()
{
	int x,i;
	char s[44];
	cin>>x;
	for(i=0;i<x;i++)
	{
		scanf("%s",s);
		for(int j=0;j<strlen(s);j++)
		{
			if(s[j]>='A' && s[j]<='Z')
				s[j]+=32;
		}
		//cout<<s<<endl;
		if(ordenada(s,strlen(s)))
		cout<<s<<": O"<<endl;
		else cout<<s<<": N"<<endl;
	}

	return 0;
}
