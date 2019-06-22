#include <stdio.h>

int main() {

    int n, c, i;

    while(true) {
        scanf("%d %d %d", &n, &c, &i);
        if(n == 0) break;

        for(int j = 0; j < i; ++j) {
            c = c * 2;
            c = c % (n+1); 
        }


        printf("%d\n", c);

    }

    return 0;

}