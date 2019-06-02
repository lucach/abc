#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* S;
static int res;

// Declaring functions
int riassumi(int N, int M, int* A, int* B, int* S);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %d", &N, &M);
	A = (int*)malloc(M * sizeof(int));
	B = (int*)malloc(M * sizeof(int));
    S = (int*)malloc(10 * sizeof(int));
	for (i0 = 0; i0 < M; i0++) {
	    fscanf(fr, "%d %d", &A[i0], &B[i0]);
	}

	// Calling functions
	res = riassumi(N, M, A, B, S);

	// Writing output
	fprintf(fw, "%d\n", res);
    for (i0 = 0; i0 < res; i0++) {
        fprintf(fw, "%d ", S[i0]);
    }
	
	fclose(fr);
	fclose(fw);
	return 0;
}
