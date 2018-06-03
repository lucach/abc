#include <cstring>
#include <iostream>
using namespace std;

int rsa(int N, int d, int c) {
    // Decifra c calcolando c^d mod N
    long long risultato = 1;
    for (int i = 0; i < d; i++) {
        risultato *= c;
        risultato %= N;
    }
    return risultato;

}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for (int i = 0; i < L; i++) {
        plaintext[i] = (char)rsa(N, d, messaggio[i]);
    }
    plaintext[L] = '\0';
}
