#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n = 1000;
    double** a = new double* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    double** b = new double* [n];
    for (int i = 0; i < n; ++i) {
        b[i] = new double[n];
    }

    double** output = new double* [n];
    for (int i = 0; i < n; ++i) {
        output[i] = new double[n];
    }


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = 1.2;
            b[i][j] = 2.5;
            output[i][j] = 0;
        }
    double startTime = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for schedule(static)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                {
                    output[i][j] += a[i][k] * b[k][j];
                }
    }
    double endTime = omp_get_wtime();
    printf("time: %f, %d\n", endTime - startTime, omp_get_thread_num());



    



    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            //cout << " " << output[i][j];
            //if (j == n - 1)
            //    cout << endl;
        }

    return 0;
}