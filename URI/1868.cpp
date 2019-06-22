#include <stdio.h>

char M[30][30];

void print(int N, int x, int y) {

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; j++) {
            if(i == x && y == j) printf("X");
            else printf("O");
        } printf("\n");
    }
    printf("@\n");    

}

int main() {

    int N;

    while(scanf("%d", &N) && N != 0) {

        int x = N/2 + 1;
        int y = N/2 + 1;
        
        print(N, x, y);
        for(int i = 1; i <= N; ++i) {

            if(i % 2) {  /* ESQ E PARA CIMA */

                for(int j = 1; j <= i && y < N; ++j) {
                    y += 1;
                    print(N, x, y);
                }

                if(x == N) break;

                for(int j = 1; j <= i; ++j) {
                    x -= 1;
                    print(N, x, y);
                }
            }

            else {
                for(int j = 1; j <= i; ++j) {
                    y -= 1;
                    print(N, x, y);
                }
                

                for(int j = 1; j <= i; ++j) {
                    x += 1;
                    print(N, x, y);
                }
            }
        }
    }

    return 0;
}