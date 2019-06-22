#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int mat[N][N];

int main()
{
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%d", &mat[i][j]);
        }
    }   
    
    bool flag_ant = false, flag = false, resp = true;
    for (int j=0; j<m; j++){
        flag = false;
        for (int i=0; i<n; i++){
            if(mat[i][j] != 0) flag = true;
        }
        if(flag == true && flag_ant == true) resp = false;
        flag_ant = flag;
    }
    
    //~ cout << resp << endl;
    
    int last1, last2;
    for (int j=0; j<m; j++)
    {
        last1 = -1, last2 = -1;
        for (int i=0; i<n; i++){
            if(mat[i][j] == 1){
                if(last1 != -1 && i - last1 - 1 < c) resp = false;
                last1 = i;
            }
            if(mat[i][j] == 2){
                if(last2 != -1 && i - last2 - 1 < c) resp = false;
                last2 = i;
            }
        }
    }
    puts((resp) ? "S" : "N");
}