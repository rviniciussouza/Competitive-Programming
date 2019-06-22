// C++ program to demonstrate working of Square Root
// Decomposition.
#include "iostream"
#include "math.h"
using namespace std;

#define MAXN 100010
#define SQRSIZE 350
#define INF 100000

struct bloco{
	int x;
	int y;
	int soma;
};

int arr[MAXN], input[MAXN];			 // original array
bloco block[SQRSIZE];		 // decomposed array
int blk_sz;					 // block size
int blk_idx;



// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
	int sum = 0;
	while (l<r and l%blk_sz!=0 and l!=0)
	{
		// traversing first block in range
		sum += arr[l];
		l++;
	}
	while (l+blk_sz <= r)
	{
		// traversing completely overlapped blocks in range
		sum += block[l/blk_sz];
		l += blk_sz;
	}
	while (l<=r)
	{
		// traversing last block in range
		sum += arr[l];
		l++;
	}
	return sum;
}

// Fills values in input[]
void preprocess(int input[], int n)
{
	// initiating block pointer
	blk_idx = -1;

	// calculating size of block
	blk_sz = sqrt(n);

	int max_atual, max_total, x_temp;
	int maior_elemento, id_maior_elemento;

	for (int i=0; i<n; i++)
	{

		if (i%blk_sz == 0)
		{
			max_atual = 0;
			max_total = -1;
			x_temp = i;
			maior_elemento = -INF;
			blk_idx++;
		}

		max_atual += input[i];
		
		if(max_atual < 0) {
			max_atual = 0;
			x_temp = i+1;
		}

		if(maior_elemento < input[i]) {
			maior_elemento = input[i];
			id_maior_elemento = i;
		}

		if(max_atual > max_total) {
			max_total = max_atual;
			block[blk_idx].soma = max_atual;
			block[blk_idx].y = i;
			block[blk_idx].x = x_temp;			
		}

		if(max_total == 0) {
			block[blk_idx].soma = maior_elemento;
			block[blk_idx].y = id_maior_elemento;
			block[blk_idx].x = id_maior_elemento;
		}
	}
}

// Driver code
int main()
{
	int n, t, q;

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &input[i]);
		}

		preprocess(input, n);

		

		for(int i = 0; i <= blk_idx; ++i) {
			printf("%d %d %d\n", block[i].soma, block[i].x, block[i].y);
		}


		// scanf("%d", &q);

	}


	return 0;
}