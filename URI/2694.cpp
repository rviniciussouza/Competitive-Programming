#include <string>
#include <iostream>
using namespace std;


int main() {

    int n;

    scanf("%d", &n);

    char buffer[15];
    char numeros[3][15];

    while(n--) {

        scanf(" %s", buffer);

        int j = 0, k = 0; bool flag = false;
        for(int i = 0; i <= 13; ++i) {
            while(buffer[i] >= '0' && buffer[i] <= '9') {
                flag = true;
                numeros[j][k++] = buffer[i++];
            }

            if(flag) {
                numeros[j][k] = '\0';
                flag = false;
                j++;
                k = 0;
            }
        }

        int a, b, c;

        sprintf(numeros[0], "%d", a);
        sprintf(numeros[1], "%d", b);
        sprintf(numeros[2], "%d", c);

        printf("%d\n", a);

    }

    return 0;
}