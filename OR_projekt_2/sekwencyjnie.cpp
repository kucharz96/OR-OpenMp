#include <iostream>
#include <chrono>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{

    int n = atoi(argv[1]);



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
            a[i][j] = 3.2;
            b[i][j] = 4.7;
            output[i][j] = 0;
        }




    double startTime = omp_get_wtime();
    // Multiplying matrix a and b and storing in array mult.
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
            {
                output[i][j] += a[i][k] * b[k][j];
            }


    double endTime = omp_get_wtime();
    double elapsed = (endTime - startTime);
    long aa = (2 * (n * n * n));

    cout << "N = " << n << " Time = " << elapsed;






    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cout << " " << output[i][j];
            if (j == n - 1)
                cout << endl;
        }

    return 0;
}