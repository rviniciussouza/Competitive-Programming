#include <stdio.h>

int main() {
    int l, c, a, b;

    scanf("%d %d %d %d", &l, &c, &a, &b);

    if(((a * c) + b + 1) % 2 == 1) {
        printf("Direita\n");
    }

    else {
        printf("Esquerda\n");
    }
    
    return 0;

}