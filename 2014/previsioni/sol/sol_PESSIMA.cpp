
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/**
Anche questa soluzione non è poi così male...
È leggermente peggiore di quella "ufficiale", ma
comunque risponde bene fino a N ~ 10^8.
Il problema è che consuma un po' troppa memoria
e dopo un po' l'operatore new ritorna std::bad_alloc().
Vogliamo porre un limite sulla memoria?
Cambiare il testo?
*/

/* Compute the length of S(k) */
int len(int k)
{
  int x;
  if (k==-1) return 0;
  x = len(k-1);
  return x + k+3 + x;
}

void costruisci(int k, char* risultato)
{
  if (k == 0) { risultato[0] = 'P'; risultato[1] = risultato[2] = 'S'; return; }
  int l = 2*len(k-1)+1+k+2;
  int l1 = len(k-1);
  char* tmp = new char [l1];
  assert (tmp != NULL);
  costruisci(k-1, tmp);
  strncpy(risultato, tmp, l1);
  risultato[l1] = 'P';
  for (int i = 0; i < k + 2; i++)
    risultato[l1+i+1] = 'S';
  strncpy(risultato+l1+1+k+2, tmp, l1);
  delete [] tmp;
}

int main()
{
  int n;
  scanf ("%d", &n);
  /** Aumento k finché la stringa non è lunga abbastanza */
  int k = -1;
  do { k++; } while (len(k) < n);
  char* risultato = new char[2*len(k)+1+k+2];
  assert (risultato != NULL);
  /** Calcolo la stringa completa della previsione */
  costruisci(k, risultato);
  /** Stampo il carattere */
  printf ("%c\n", risultato[n-1]);
  delete [] risultato;
  return 0;
}
