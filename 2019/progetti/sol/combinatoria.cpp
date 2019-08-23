/*
	Author: Fabio Marchesi.
	Complexity: O(log(N)(log(N)+k^2)).
	Description:
Possiamo immaginare gli N progetti come un tassello 1XN, e dobbiamo riempirla utilzzando dei tasselli più piccoli.
Quando svolgiamo 1 progetto in un giorno usiamo un 1x1,, quando ne svogliamo 2 usiamo un tassello 1x2 quando ne svogliamo K 
usiamo un tassello 1xK.
Quello che viene richiesto è il numero di modi differenti con cui comporre la nostra righa 1xN usando i tasselli 1x1...1xK.
Nel caso di esempio N=4, K=2 i modi che abbiamo sono
1: 1x1 1x1 1x1 1x1
2: 1x2     1x1 1x1
3: 1x1 1x2     1x1
4: 1x1 1x1 1x2
5: 1x2     1x2	
Definamo dunque f(n) il modo in cui puoi comporre una riga grande n con pezzi larghi al più K
Abbiamo che f(0)=1 ed f(1)=1, mentre f(x) con x<0 vale 0:non c'è nesuno modo.
Per calcolare f(n) possiamo innanzittutto contare i modi in cui puoi comporlo unendo pezzi larghi n/2
Possiamo quindi settare res=f(n/2)+f((n+1)/2), quindi quei pezzi larghi N che sono "rotti" al centro.
Nel caso di esempio abbiamo res=f(2)*f(2): f(2)=2 ->1x1 1x1 | 1x2 quindi res=4:
1: 1x1 1x1 | 1x1 1x1
2: 1x2     | 1x1 1x1
3: 1x1 1x1 | 1x2
3: 1x2     | 1x2
Al momento abbiamo contato questi casi, ma manca 1x1 1x2 1x1 in quanto non deriva dall'unione di 2 pezzi 1x2.
Quello che dobbiamo fare è prendere i pezzi 1x2, 1x3, .. 1xK e provarli a posizionarli al centro della nostra sequenza.
In questo caso K=2, e quindi proviamo ad aggiungere al centro un 1x2. C'è un unico modo per metterlo al centro della sequenza, 
questo modo lascia uno spazio di 1 a sinistra ed uno spazio di 1 a destra: dei 4 spazi i 2 al centro sono occupati dall'1x2, quindi 
aggiungiamo a res f(1)*f(1)=1 ed otteniamo res=5.


Esempio 
N=4 K=3 f(N)=7
per comodità rivelo che f(2)=2 con K=3 1x1 1x1 oppure 1x2
Come prima calcoliamo inizalmente i pezzi rotti al centro, che sono gli stessi 4 di prima.
res=4:
1: 1x1 1x1 | 1x1 1x1
2: 1x2     | 1x1 1x1
3: 1x1 1x1 | 1x2
3: 1x2     | 1x2
 Ora aggiungiamo i pezzi al centro:
 Il primo modo è sempre quello di prima quindi aggiungere l'1x2 nelle celle 1 e 2 res+= f(1)*f(1)=1, res=5
 Ora aggiungiamo i 2 modi per aggiungere un 1x3:
 Quindi:

 1x3         1x1 [rotto al centro] res+=  f(0)*f(1)=1 res=6
 1x1 1x3         [rotto al centro] res+=  f(1)*f(0)=1 res=7
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<int,int> M;
int const MOD=1000000007;
int K;
int comb(int n){
    if(n<0) return 0;
	if(M[n]) return M[n];
	int fhalf=n/2, shalf=(n+1)/2; //first half, second half
	int res=((ll)comb(fhalf)*comb(shalf))%MOD;
	for(int length=2;length<=K;length++)
		for(int offset=1; offset<length; offset++){
			res=(res+((ll)comb(fhalf-offset)*comb(shalf-length+offset))%MOD)%MOD;
		}
	return M[n]=res;
}
int progetti(int N, int K){
    ::K=K;
    M[0]=1;
    M[1]=1;
   	return comb(N);
}
