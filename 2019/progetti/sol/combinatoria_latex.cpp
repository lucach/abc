#include<bits/stdc++.h>

std::unordered_map<int,int> M;
const int MOD = 1000000007;
int K;

int comb(int n) {
    if (n < 0)
       return 0;
    if (M[n])
        return M[n];
    int meta_sx = n/2, meta_dx = (n+1)/2;
    int risposta = ((long long)comb(meta_sx) * comb(meta_dx)) % MOD;
    for (int lunghezza = 2; lunghezza <= K; lunghezza++)
        for (int offset = 1; offset < lunghezza; offset++) {
            long long altre = (long long)comb(meta_sx - offset) *
                                         comb(meta_dx - lunghezza + offset);
            risposta = (risposta + altre) % MOD;
        }
    M[n] = risposta;
    return risposta;
}
int progetti(int N, int K) {
    ::K = K;
    M[0] = 1;
    M[1] = 1;
    return comb(N);
}
