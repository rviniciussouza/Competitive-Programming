#include <bits/stdc++.h>
using namespace std;

#define MAXNM 100000 + 10

int data;
int dp_col[MAXNM];
int dp_row[MAXNM];

int main() {

    int n, m;

    while(scanf("%d %d", &n, &m) && (n+m)) {

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {

                scanf("%d", &data);

                if(j == 0) dp_col[j] = data;
                if(j == 1) dp_col[j] = max(dp_col[j-1], data);
                else {
                    dp_col[j] = max(dp_col[j-2] + data, dp_col[j-1]);
                }
            }

            if(i == 0) dp_row[i] = dp_col[m-1];
            if(i == 1) dp_row[i] = max(dp_row[i-1], dp_col[m-1]);
            else {
                dp_row[i] = max(dp_col[m-1] + dp_row[i-2], dp_row[i-1]);
            }
        }

        printf("%d\n", dp_row[n-1]);

    }

    return 0;
}