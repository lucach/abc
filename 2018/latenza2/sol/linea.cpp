#include <algorithm>

using namespace std;

int latenza(int N, int M, int A[], int B[], int L[])
{
    return accumulate(L, L + M, 0);
}
