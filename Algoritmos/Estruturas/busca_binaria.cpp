int busca_binaria(vector<ii>& v, int n, int key) {
    int x = 0, y = n - 1, z;
    while(x <= y) {
        z = (x + y) / 2;
        if(key == v[z].first) return z;
        if(key < v[z].first) y = z-1;
        else x = z + 1;
    }

    return -1;
}
