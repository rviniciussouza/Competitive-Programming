#include <stdio.h>

int main() {
    int d, i, x, f;

    scanf("%d %d %d %d", &d, &i, &x, &f);

    if(d % 2) {
        if(f % 2) printf("%d\n", i+x);
        else printf("%d\n", i);
    }

    else {
        if(f % 2) printf("%d\n", i-x);
        else printf("%d\n", i);
    }

    return 0;

}