/*******************************
* TAG: PD
* sub set sum
* Verifica se um inteiro x, pode ser formado a
* parti da soma dos elementos de um vetor dado
********************************/

bool sum_set_sum(int n, int v[], int c) {
    if(c == 0) return true;
    if(n == 0 && c > 0) return false;
    if(v[n-1] > c) return sub_set_sum(n-1, v, c);
    return sub_set_sum(n-1, v, c) || return sub_set_sum(n-1, v, c - v[n-1]);
}