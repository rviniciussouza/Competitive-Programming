#include <bits/stdc++.h>
using namespace std;

//with range update and queries

class FenwickTree {
    private:
        vector<int> BT1, BT2;
        int rsq(vector<int>& BT1, int i) {
            int sum = 0;
            while(i > 0) {
                sum += BT1[i];
                i -= (i & -i);
            }
            return sum;
        }

        void update(vector<int>& BT1, int i, int v) {
            while(i < (int)BT1.size()) {
                BT1[i] += v;
                i += (i & -i);
            }
        }

    public:
        FenwickTree(int n) {
            BT1.assign(n+1, 0);
            BT2.assign(n+1, 0);
        }

        void update(int i, int j, int v) {
            update(BT1, i, v);
            update(BT1, j+1, -v);
            update(BT2, i, v * (i-1));
            update(BT2, j+1, -v*j);
        }

        int rsq(int i) {
            return rsq(BT1, i) * i - rsq(BT2, i);
        }

        int rsq(int i, int j) {
            return rsq(j) - rsq(i-1);
        }

};

int main() {
    return 0;
}