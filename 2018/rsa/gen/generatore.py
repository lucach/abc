#!/usr/bin/env python

from limiti import *
from random import sample, seed, randint, shuffle, random
from sys import argv
import time

usage="""Generatore di "rsa".

Parametri:
* N (max fattori per generare N)
* L (lunghezza messaggio)
* d (se positivo, fissa il valore di d nella chiave privata)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= L <= %d
""" % (MAXN, MAXL)

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def run(N, L, d):
    done = False
    while not done:
        seed(time.time())
        # Trovo i numeri primi fino a N
        isprime = [True for _ in xrange(N+1) ]
        isprime[1] = False
        primes = []
        for i in xrange(2, N+1):
            j = i*i
            while j <= N:
                isprime[j] = 0
                j += i
        for i in xrange(2, N + 1):
            if isprime[i]:
                primes.append(i)

        p_idx = randint(5, len(primes) - 1)
        q_idx = randint(5, len(primes) - 1)
        while q_idx == p_idx:
            q_idx = randint(2, len(primes) - 1)
        p = primes[p_idx]
        q = primes[q_idx]
        realN = p * q
        phi = (p-1)*(q-1)

        try:
            if d < 0:
                e = 65537
                d = modinv(e, phi)
            else:
                e = modinv(d, phi)
            #plaintext = "a" * L
            plaintext = "t"
            encrypted = []
            for c in plaintext:
                encrypted.append(pow(ord(c), e, realN))
            print realN, d, len(encrypted)
            for c in encrypted:
                print c,
            print
            done = True
        except:
            pass
        

if __name__ == "__main__":
    if len(argv) != 5:
        print(usage)
        exit(1)

    N, L, d, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= L <= MAXL)
    seed(S)
    run(N, L, d)

