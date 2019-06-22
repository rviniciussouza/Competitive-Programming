// Program to show segment tree to demonstrate lazy
// propagation
#include <bits/stdc++.h>
using namespace std; 

const int MAX = 400010; 

long long tree[MAX] = {0};
long long lazy[MAX] = {0}; 

void updateRangeUtil(int si, int ss, int se, int us, int ue, long long diff) {
    
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
 
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
 
        lazy[si] = 0;
    }
 
    if (ss>se || ss>ue || se<us)
        return ;
 
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
         if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
 
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
 
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
void updateRange(int n, int us, int ue, long long diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
 
long long getSumUtil(int ss, int se, int qs, int qe, int si)
{

    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se) {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
 
        lazy[si] = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    if (ss>=qs && se<=qe)
        return tree[si];
 
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
long long getSum(int n, int qs, int qe)
{
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
 
int main()
{
 
    int n, op, p, q, t, c;
    long long v;

    scanf("%d", &t);        
    while(t--) {
        scanf("%d %d", &n, &c);

        long long int arr[MAX];
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);

        // constructST(arr, n);    

        while(c--) {
            scanf("%d", &op);

            if(op == 0) {
                scanf("%d %d %lld", &p, &q, &v); p--; q--;
                    updateRange(n, p, q, v);    
            }

            else {
                scanf("%d %d", &p, &q); p--; q--;
                printf("%lld\n", getSum(n, p, q));
            }
        }
    }
 
    return 0;
}