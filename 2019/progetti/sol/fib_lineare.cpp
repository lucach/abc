#include <iostream>
using namespace std;
int progetti(int n, int k) {
    // Assume K == 2.
    int a, b, c;
    a = b = c = 1;
    for (int i = 2; i <= n; i++) {
        c=(a+b)%1000000007;
        a=b;
        b=c;
    }
    return c;
}
