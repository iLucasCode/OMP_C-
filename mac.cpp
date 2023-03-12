#include "mac.h"


int test(double** Matrix1, double** Matrix2, double** Matrix3)
{
    int i, j, k, chk = 0;
    double tmp, ** Mtest;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            tmp = 0;
            for (k = 0; k < N; k++)
            {
                tmp += Matrix1[i][k] * Matrix2[k][j];
            }
            if (Matrix3[i][j] != tmp)
            {
                printf("Error in element %d,%d!\n", i, j);
                chk = 1;
            }
        }
    }
    return chk;
}

int mac(void)
{
    double** A, ** B, ** C;
    int i, j, k, chk;
    double start, stop;
    double sum = 0;
    A = (double**)malloc(N * sizeof(double*));
    B = (double**)malloc(N * sizeof(double*));
    C = (double**)malloc(N * sizeof(double*));

    for (i = 0; i < N; i++)
    {
        A[i] = (double*)malloc(N * sizeof(double));
        B[i] = (double*)malloc(N * sizeof(double));
        C[i] = (double*)malloc(N * sizeof(double));
    }
    srand(time(NULL));

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            A[i][j] = rand() % 1001 / 1000. * 1000;
            B[i][j] = rand() % 1001 / 1000. * 1000;
        }

    start = omp_get_wtime();

    //fragment for paralelization
    //#pragma omp parallel for private(j) 
    #pragma omp parallel for private(j,k) reduction(+:sum)
    for (i = 0; i < N; i++)
    {
        //#pragma omp parallel for private(k) reduction(+:sum)
        for (j = 0; j < N; j++)
        {
            sum = 0;
            //#pragma omp parallel for 
            for (k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    stop = omp_get_wtime();
    printf("Time of matrix multiplification = %lf\n", stop - start);

    chk = test(A, B, C);
    if (chk == 1)
        printf("Program exited with errors\n");

}


