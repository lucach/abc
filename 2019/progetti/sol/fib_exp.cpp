#include <iostream>
using namespace std;
int fib(int n) {
    if (n <= 1) return 1;
    return fib(n-1) + fib(n-2) % 1000000007;
}
int progetti(int n, int k) {
    // Assume K == 2.
    return fib(n);
}
