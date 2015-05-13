#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/**
Da chiamare con:
    N M S MINIMORANDOM MASSIMORANDOM EVPARAMETRO

    L'ultimo parametro è -1 o -2 a seconda di come si vuole
    far fallire il programma (=>NO)
*/
int main(int argc, char* argv[])
{
    if(argc < 6)
    {
        cout << "Parametri mancanti";
        return 1;
    }
    srand(time(NULL));
    int NSTUD = atoi(argv[1]), NBUG = atoi(argv[2]), MAX = atoi(argv[3]);
    int mi = atoi(argv[4]), ma = atoi(argv[5]);
    cout << NSTUD << " " << NBUG << " " << MAX << endl;
    int mass = -1, tmp;
    for(int i = 0; i < NBUG; i++)
    {
        if(ma == mi) tmp = ma;
        else
            tmp = rand() % (ma - mi) + mi;
        cout << tmp << " ";
        mass = max(mass, tmp);
    }
    cout << endl;
    for(int i = 0; i < NSTUD; i++)
    {
        if(ma == mi) tmp = ma;
        else
            tmp = rand() % (ma - mi) + mi;
        if(argc > 6 && atoi(argv[6]) == -1)
            while(tmp >= mass)
            {
                tmp = rand() % (ma - mi) + mi;
            }
        cout << tmp << " ";
    }
    cout << endl;
    int pos = rand()%NSTUD;
    for(int i = 0; i < NSTUD; i++)
    {
        if(ma == mi) tmp = ma;
        else
            tmp = rand() % (ma - mi) + mi;
        if(argc > 6 && atoi(argv[6]) == -2 && i == pos)
            tmp = MAX + 1;
        cout << tmp << " ";
    }
    cout << endl;

}
