#include <iostream>
#include <omp.h>
using namespace std;

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    omp_set_num_threads(t);
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
    int i, j, k;
#pragma omp parallel default(none) shared(n) private(i,j,k)
    {
#pragma omp for schedule(guided) 
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                for (k = 0; k < n; ++k)
                {
                    output[i][j] += a[i][k] * b[k][j];
                }
    }
    double endTime = omp_get_wtime();
    double elapsed = (endTime - startTime);
    long aa = (2 * (n * n * n));

    cout << "Threads =" << t << " N = " << n << " Time = " << elapsed;


    



    //// Displaying the multiplication of two matrix.
    //cout << endl << "Output Matrix: " << endl;
    //for (int i = 0; i < n; ++i)
    //    for (int j = 0; j < n; ++j)
    //    {
    //        //cout << " " << output[i][j];
    //        //if (j == n - 1)
    //        //    cout << endl;
    //    }

    return 0;
}