#include <cmath>
#include <iostream>
using namespace std;

void inline Permute(int n, double **A, double *p, int k, int r)
{
    double aux = p[k];
    p[k] = p[r];
    p[r] = aux;
    for (int j = 0; j < n; j++)
    {
        aux = A[k][j];
        A[k][j] = A[r][j];
        A[r][j] = aux;
    }
}
void inline Pivot(int n, double **A, int k, int &r, double &pv)
{
    pv = fabs(A[k][k]);
    r = k;
    for (int i = k + 1; i < n; i++)
    {
        if (fabs(A[i][k]) > pv)
        {
            pv = (fabs(A[i][k]));
            r = i;
        }
    }
}
void inline SucessiveSubstitution_mod(int n, double **A, double *B, double *X)
{

    for (int i = 0; i < n; i++)
    {
        double soma = 0;
        for (int j = 0; j < i; j++)
        {

            soma += A[i][j] * X[j];
        }
        X[i] = (B[i] - soma);
    }
}

void inline RetroactiveSubstitution(int n, double **A, double *B, double *X)
{
    X[n] = B[n] / A[n][n];
    for (int i = n - 1; i >= 0; --i)
    {
        double soma = 0;
        for (int j = i + 1; j < n; j++)
        {
            soma += A[i][j] * X[j];
        }
        X[i] = (B[i] - soma) / A[i][i];
    }
}

void LU(int n, double **A, double *b, double *x, double *y)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         std::cout << "[" << (float)A[i][j] << "]";
    //         //std::cout << i << j << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    //Inicializa P
    double p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int r;
    double pv;

    //Faz o LU
    for (int k = 0; k < n - 1; k++)
    {
        Pivot(n, A, k, r, pv);
        if (pv = 0)
        {
            return;
        }
        if (r != k)
        {

            Permute(n, A, p, k, r);
        }

        for (int i = k + 1; i < n; i++)
        {
            double m = ((double)A[i][k] / A[k][k]);
            A[i][k] = m;
            for (int j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - m * A[k][j];
            }
        }
    }
    // std::cout << std::endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         std::cout << "[" << (float)A[i][j] << "]";
    //         //std::cout << i << j << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    double blin[n];

    for (int i = 0; i < n; i++)
    {
        r = p[i];
        blin[i] = b[r];
    }

    SucessiveSubstitution_mod(n, A, blin, y);

    RetroactiveSubstitution(n, A, y, x);
}

void LDP(int n, double **A, double *b, double *x, double *y)
{
    double *l[n];
    for (int i = 0; i < n; i++)
    {
        l[i] = new double[n];
    }
    int i = 0, j = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            l[i][j] = A[i][j];
        }
    }

    double *u[n];
    for (int i = 0; i < n; i++)
    {
        u[i] = new double[n];
    }
    i = 0, j = 0;

    double p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int r;
    double pv;
    double list_piv[n];
    //Init LDP

    double *P[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = new double[n];
    }
    double *D[n];
    for (int i = 0; i < n; i++)
    {
        D[i] = new double[n];
    }

    double *L[n];
    for (int i = 0; i < n; i++)
    {
        L[i] = new double[n];
    }

    for (int k = 0; k < n - 1; k++)
    {
        Pivot(n, l, k, r, pv);

        if (pv = 0)
        {
            return;
        }
        if (r != k)
        {

            Permute(n, l, p, k, r);
        }

        for (int i = k + 1; i < n; i++)
        {
            double m = ((double)l[i][k] / l[k][k]);
            l[i][k] = m;
            L[i][k] = m;
            for (int j = k + 1; j < n; j++)
            {
                float temp = l[i][j] - m * l[k][j];

                l[i][j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        D[i][i] = l[i][i];
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            P[a][b] = l[a][b] / D[a][a];
        }
    }

    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << l[a][b] << " ";
    //     }
    //     cout << endl;
    // }
    // std::cout << "L:" << std::endl;
    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << L[a][b] << " ";
    //     }
    //     cout << endl;
    // }
    // std::cout << "D:" << std::endl;
    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << D[a][b] << " ";
    //     }
    //     cout << endl;
    // }
    // std::cout << "P:" << std::endl;
    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << P[a][b] << " ";
    //     }
    //     cout << endl;
    // }

    double *U[n];
    for (int i = 0; i < n; i++)
    {
        U[i] = new double[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double num = 0;
            for (int k = 0; k < n; k++)
            {
                num += D[i][k] * P[k][j];
            }

            U[i][j] = num;
        }
    }
    // std::cout << "U:" << std::endl;
    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << U[a][b] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            A[i][j] = L[i][j] + U[i][j];
        }
    }
    // std::cout << "A:" << std::endl;
    // for (int a = 0; a < n; a++)
    // {
    //     for (int b = 0; b < n; b++)
    //     {
    //         cout << " " << A[a][b] << " ";
    //     }
    //     cout << endl;
    // }

    double blin[n];

    for (int i = 0; i < n; i++)
    {
        r = p[i];
        blin[i] = b[r];
    }

    SucessiveSubstitution_mod(n, A, blin, y);

    RetroactiveSubstitution(n, A, y, x);
    // ================================================================================================================

    // ================================================================================================================
}
