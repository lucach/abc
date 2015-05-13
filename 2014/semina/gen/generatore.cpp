#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/**
Parametri speciali:
-1 genera solo negativi
-2 genera solo positivi
*/

int main(int argc, char* argv[])
{
    srand (time(NULL));
    int val = 0, N = 10;
    if (argc == 3)
    {
        N = atoi(argv[1]);
        val = atoi(argv[2]);
    }
    else
        return 1;
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        int xi, yi, xf, yf;
        do
        {
            xi = rand() % 199 - 99;
            yi = rand() % 199 - 99;
            xf = rand() % 199 - 99;
            yf = rand() % 199 - 99;
            if (val == -1)
            { xi = -abs(xi); yi = -abs(yi); xf = -abs(xf); yf = -abs(yf); }
            else if (val == -2)
            { xi = abs(xi); yi = abs(yi); xf = abs(xf); yf = abs(yf); }
        } while (!(xi < xf && yf < yi));
        cout << xi << " " << yi << " " << xf << " " << yf << endl;
    }
}
