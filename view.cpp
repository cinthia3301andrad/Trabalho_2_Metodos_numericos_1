#include <iostream>
#include <cmath>
#include <cstdlib>
#include <curses.h>
#include "numerical_methods.hpp"
using namespace std;
#include <iomanip>
void print_option_one(double **matrizPrincipal, double *Fprincipal, int n)
{
    int i = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << fixed << setprecision(6) << "[" << (float)matrizPrincipal[i][j] << fixed << setprecision(6) << "]";
            //std::cout << i << j << std::endl;
        }
        cout << endl;
    }

    i = 0;
    cout << "\033[1;33m       Deslocamento F[]\033[0m\n";
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(6) << "[" << (float)Fprincipal[i] << fixed << setprecision(6) << "]";
    }
    cout << endl;
}
