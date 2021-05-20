#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int block = 2;
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

    for (int ii = 0; ii < n; ii += block)
    {
        for (int jj = 0; jj < n; jj += block)
        {
            for (int kk = 0; kk < n; kk += block)
            {
                for (int i = ii; i < ii + block; ++i)
                {
                    for (int j = jj; j < jj + block; ++j)
                    {
                        for (int k = kk; k < kk + block; ++k)
                            output[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
        }
    }




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