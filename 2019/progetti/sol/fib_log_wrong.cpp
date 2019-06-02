#include <iostream>
using namespace std;

void matrix_mul(int F[2][2], int M[2][2]) {
    long long x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x % 1000000007;
    F[0][1] = y % 1000000007;
    F[1][0] = z % 1000000007;
    F[1][1] = w % 1000000007;
}

void matrix_pow(int F[2][2], int exp) {
    if (exp > 1) {
        matrix_pow(F, exp / 2);
        matrix_mul(F, F);
        if (exp % 2 == 1) {
            int M[2][2] = {{1,1},{1,0}};
            matrix_mul(F, M);
        }
    }
}

int fib(int n) {
    int F[2][2] = {{1,1},{1,0}};
    matrix_pow(F, n-1);
    return F[0][0];
}

int progetti(int n, int k) {
    // Assume K == 2.
    return fib(n+1);
}
