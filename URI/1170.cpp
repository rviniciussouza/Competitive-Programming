#include <stdio.h>

int main()
{
    int n, c;
    double kg;

    scanf("%d", &n);

    while(n--) {
        scanf("%lf", &kg);
        c = 0;

        while(kg > 1) {
            kg = kg / 2;
            ++c;
        }

        printf("%d dias\n", c);

    }

    return 0;
}