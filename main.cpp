
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip> // std::setfill, std::setw

using namespace std;
#include <iomanip>
#include "numerical_methods.hpp"
#include "view.hpp"
int main(int argc, char **argv)
{
    int option;

    cout << "\033c";
    system("clear");
    cout << "|===========================================================================|\n";
    cout << "                  Métodos Numéricos - Trabalho 2 \n \n \n ";
    cout << "                        Tema 1 - Foguete Espacial\n";
    cout << "|===========================================================================|\n";
    // Calibrar sistema desenvolvido usando o padrão pedido na letra C
    int n = 3;
    double *matrizPrincipalLU[3];
    matrizPrincipalLU[0] = new double[3]{3, -2, 1};
    matrizPrincipalLU[1] = new double[3]{1, -3, 4};
    matrizPrincipalLU[2] = new double[3]{9, 4, -5};

    double *matrizPrincipalLDP[3];
    matrizPrincipalLDP[0] = new double[3]{3, -2, 1};
    matrizPrincipalLDP[1] = new double[3]{1, -3, 4};
    matrizPrincipalLDP[2] = new double[3]{9, 4, -5};

    double FprincipalLDP[3] = {8, 6, 11};
    double XprincipalLDP[3] = {0, 0, 0}; //F
    double YprincipalLDP[3] = {0, 0, 0}; //ALGUMA COISA

    double FprincipalLU[3] = {8, 6, 11};
    double XprincipalLU[3] = {0, 0, 0};
    double YprincipalLU[3] = {0, 0, 0};
    LU(n, matrizPrincipalLU, FprincipalLU, XprincipalLU, YprincipalLU);

    LDP(n, matrizPrincipalLDP, FprincipalLDP, XprincipalLDP, YprincipalLDP);
    int i = 0;

    //LOOP PRINCIPAL DO PROGRAMA
    while (option != 3)
    {

        cout << "---------------------------------------------------" << endl;
        cout << "Digite um número correspondente ao que deseja fazer:" << endl;
        cout << "---------------------------------------------------" << endl;

        cout << "\033[1;34m 1 \033[0m- Calcular com valores padrão A[], F[]" << endl;
        cout << "\033[1;34m 2 \033[0m- Quadro resposta com valores personalizados" << endl;
        cout << "\033[1;34m 3 \033[0m- Quadro comparativo com valores fixos" << endl;
        cout << "\033[1;34m 4 \033[0m- Sair" << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> option;

        // OPÇÃO 1 QUE MOSTRA OS VALORES PADRÃO
        system("clear");
        if (option == 1)
        {
            cout << "\033[1;33m       MATRIZ A[] - Método LU\033[0m\n";
            print_option_one(matrizPrincipalLU, XprincipalLU, 3);
            cout << endl;
            cout << "\033[1;33m       MATRIZ A[] - Método LDP \033[0m\n";
            print_option_one(matrizPrincipalLDP, XprincipalLDP, 3);
        }
        // OPÇÃO 2 QUE MOSTRA OS VALORES PERSONALIZADOS

        if (option == 2)
        {
            int n_ordemDaMatriz = 0;
            cout << "Escolha um valor de n para a matriz NxN" << endl;
            cin >> n_ordemDaMatriz;

            double *MatrizPersonalizadaLU[n_ordemDaMatriz];
            double FpersonalizadoLU[n_ordemDaMatriz];
            double XpersonalizadoLU[n_ordemDaMatriz];
            double YpersonalizadoLU[n_ordemDaMatriz];

            double *MatrizPersonalizadaLDP[n_ordemDaMatriz];
            double FpersonalizadoLDP[n_ordemDaMatriz];
            double XpersonalizadoLDP[n_ordemDaMatriz];
            double YpersonalizadoLDP[n_ordemDaMatriz];

            for (int i = 0; i < n; i++)
            {
                MatrizPersonalizadaLU[i] = new double[n_ordemDaMatriz];
                MatrizPersonalizadaLDP[i] = new double[n_ordemDaMatriz];
            }
            for (int i = 0; i < n_ordemDaMatriz; i++) //linha
            {
                for (int j = 0; j < n_ordemDaMatriz; j++) //coluna
                {
                    int novoValor;
                    cout << "Digite um valor para a linha " << i << " da coluna " << j << endl;
                    cin >> novoValor;
                    MatrizPersonalizadaLU[i][j] = novoValor;
                    MatrizPersonalizadaLDP[i][j] = novoValor;
                }
            }
            for (int i = 0; i < n_ordemDaMatriz; i++) //coluna
            {
                int novoValor;
                cout << "Digite o valor" << i << " do vetor F " << endl;
                cin >> novoValor;
                FpersonalizadoLU[i] = novoValor;
                FpersonalizadoLDP[i] = novoValor;
                XpersonalizadoLU[i] = 0;
                XpersonalizadoLDP[i] = 0;
                YpersonalizadoLU[i] = 0;
                YpersonalizadoLDP[i] = 0;
            }
            cout << "\033[1;33m       MATRIZ A[] - Método LU\033[0m\n";
            LU(n_ordemDaMatriz, MatrizPersonalizadaLU, FpersonalizadoLU, XpersonalizadoLU, YpersonalizadoLU);
            print_option_one(MatrizPersonalizadaLU, FpersonalizadoLU, n_ordemDaMatriz);
            cout << "\033[1;33m       MATRIZ A[] - Método LDP \033[0m\n";
            LDP(n_ordemDaMatriz, MatrizPersonalizadaLDP, FpersonalizadoLDP, XpersonalizadoLDP, YpersonalizadoLDP);
            print_option_one(MatrizPersonalizadaLDP, FpersonalizadoLDP, n_ordemDaMatriz);
        }

        // OPÇÃO 3 QUE MOSTRA OS VALORES PERSONALIZADOS

        // if (option == 3)
        // {
        //     int n_ordemDaMatriz = 3;
        //     double *MatrizPersonalizadaLU[3];
        //     MatrizPersonalizadaLU[0] = new double[3]{1, 2, 3};
        //     MatrizPersonalizadaLU[1] = new double[3]{3, -1, 2};
        //     MatrizPersonalizadaLU[2] = new double[3]{2, 1, 1};

        //     double *MatrizPersonalizadaLDP[3];
        //     MatrizPersonalizadaLDP[0] = new double[3]{1, 2, 3};
        //     MatrizPersonalizadaLDP[1] = new double[3]{3, -1, 2};
        //     MatrizPersonalizadaLDP[2] = new double[3]{2, 1, 1};

        //     double FpersonalizadoLDP[3] = {1, 0, 2};
        //     double XpersonalizadoLDP[3] = {0, 0, 0}; //F
        //     double YpersonalizadoLDP[3] = {0, 0, 0}; //ALGUMA COISA

        //     double FpersonalizadoLU[3] = {1, 0, 2};
        //     double XpersonalizadoLU[3] = {0, 0, 0};
        //     double YpersonalizadoLU[3] = {0, 0, 0};

        //     cout << "\033[1;33m       MATRIZ A[] - Método LU\033[0m\n";
        //     LU(n_ordemDaMatriz, MatrizPersonalizadaLU, FpersonalizadoLU, XpersonalizadoLU, YpersonalizadoLU);
        //     print_option_one(MatrizPersonalizadaLU, FpersonalizadoLU, n_ordemDaMatriz);
        //     cout << "\033[1;33m       MATRIZ A[] - Método LDP \033[0m\n";
        //     LDP(n_ordemDaMatriz, MatrizPersonalizadaLDP, FpersonalizadoLDP, XpersonalizadoLDP, YpersonalizadoLDP);
        //     print_option_one(MatrizPersonalizadaLDP, FpersonalizadoLDP, n_ordemDaMatriz);

        //     // for (int geral = 0; geral < 3; geral++)
        //     // {
        //     //     cout
        //     //         << "entrou"
        //     //         << "\n";
        //     //     double *MatrizPersonalizadaLU[n_ordemDaMatriz];
        //     //     double FpersonalizadoLU[n_ordemDaMatriz];
        //     //     double XpersonalizadoLU[n_ordemDaMatriz];
        //     //     double YpersonalizadoLU[n_ordemDaMatriz];

        //     //     double *MatrizPersonalizadaLDP[n_ordemDaMatriz];
        //     //     double FpersonalizadoLDP[n_ordemDaMatriz];
        //     //     double XpersonalizadoLDP[n_ordemDaMatriz];
        //     //     double YpersonalizadoLDP[n_ordemDaMatriz];
        //     //     //ALOCAÇÃO DAS MATRIZES
        //     //     for (int i = 0; i < n; i++)
        //     //     {
        //     //         MatrizPersonalizadaLU[i] = new double[n_ordemDaMatriz];
        //     //         MatrizPersonalizadaLDP[i] = new double[n_ordemDaMatriz];
        //     //     }
        //     //     for (int i = 0; i < n_ordemDaMatriz; i++) //linha
        //     //     {
        //     //         for (int j = 0; j < n_ordemDaMatriz; j++) //coluna
        //     //         {

        //     //             int novoValor = geral + i + j - 5;
        //     //             cout
        //     //                 << "AQUI OW" << novoValor << "\n";

        //     //             MatrizPersonalizadaLU[i][j] = novoValor;
        //     //             MatrizPersonalizadaLDP[i][j] = novoValor;
        //     //         }
        //     //     }
        //     //     for (int i = 0; i < n_ordemDaMatriz; i++) //coluna
        //     //     {

        //     //         int novoValor = geral + i + -3;
        //     //         FpersonalizadoLU[i] = novoValor;
        //     //         FpersonalizadoLDP[i] = novoValor;
        //     //         XpersonalizadoLU[i] = 0;
        //     //         XpersonalizadoLDP[i] = 0;
        //     //         YpersonalizadoLU[i] = 0;
        //     //         YpersonalizadoLDP[i] = 0;
        //     //     }
        // }
    }
}
