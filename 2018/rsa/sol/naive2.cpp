#include <cstring>
#include <iostream>
using namespace std;

int mypow(int base, int exp) {
    return (exp == 0) ? 1 : base * mypow(base, exp - 1);
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    plaintext[0] = mypow(messaggio[0], d) % N;
    plaintext[1] = '\0';
}
