#include <stdio.h>
#include <string.h>

const int SIZE = 1000010;

char s[SIZE];
int f[SIZE];

int main() {
	while (scanf("%s", s) == 1 && strcmp(s, ".") != 0) {
		int n = strlen(s);
		int i, j;
 
        f[0] = -1;
        for(i = 1, j = -1; s[i]; i++)
        {
            while(j >= 0 && s[j+1] != s[i])
                j = f[j];
    
            if(s[j+1] == s[i])
                j++;
    
            f[i] = j;
        }

		for (int i = 0; i <= n; ++ i) {
            printf("%d\n", f[i]);
        }
	}
    
	return 0;
}