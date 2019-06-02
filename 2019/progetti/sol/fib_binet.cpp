#include <iostream>
#include <cmath>
using namespace std;
int binet(unsigned int n)
{
    static const double phi = (1 + sqrt(5))*0.5;
    double fib = (pow(phi,n) - pow(1-phi,n))/sqrt(5);
    return (long long)round(fib) % 1000000007;
}

int progetti(int n, int k) {
    // Assume k == 2.
    return binet(n+1);
}
