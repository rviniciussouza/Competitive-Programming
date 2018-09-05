#include <bits/stdc++.h>
using namespace std;

/*MO's query */

typedef pair<int, int> ii;
int block;

bool compare(ii x, ii y)
{
	if (x.first/block != y.first/block)
		return x.first/block < y.first/block;

	return x.second < y.second;
}


void queryResults(int a[], int n, ii q[], int m)
{
	block = (int)sqrt(n);

	sort(q, q + m, compare);

	int currL = 0, currR = 0;
	int currSum = 0;

	for (int i=0; i<m; i++)
	{
		int L = q[i].first, R = q[i].second;
		
		while (currL < L) {
			currSum -= a[currL];
			currL++;
		}

		while (currL > L) {
			currSum += a[currL-1];
			currL--;
		}

		while (currR <= R)
		{
			currSum += a[currR];
			currR++;
		}

		while (currR > R+1)
		{
			currSum -= a[currR-1];
			currR--;
		}

		// Print sum of current range
		cout << "Sum of [" << L << ", " << R
			<< "] is " << currSum << endl;
	}
}

// Driver program
int main()
{
	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);
	ii q[] = {ii(0, 4), ii(1, 3), ii(2, 4)};
	int m = sizeof(q)/sizeof(q[0]);
	queryResults(a, n, q, m);
	return 0;
}
