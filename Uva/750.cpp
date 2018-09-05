#include <bits/stdc++.h>
using namespace std;

bool square(int queenPos[])
{
    for(int i=0; i < 8; ++i)
        for(int j=0; j < i; ++j)
            if(i + queenPos[i] == j + queenPos[j] || i - queenPos[i] == j - queenPos[j])
                return false;
}


int main()
{
    int t, r, c, linha;
    scanf("%d", &t);

    string newLine = "";

    while(t--)
    {
        cout<<newLine;
        newLine = "\n";

        scanf("%d %d", &r, &c);
        --c;

        int queenPos[8] = {1,2,3,4,5,6,7,8};

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        linha = 1;
        do {
            if(queenPos[c] == r && square(queenPos))
            {
                cout<<setw(2)<<linha++<<"     ";

                for(int i=0; i < 8; ++i)
                    printf(" %d", queenPos[i]);
                printf("\n");
            }
        }

        while(next_permutation(queenPos, queenPos+8));

    }

    return 0;
}