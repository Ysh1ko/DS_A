#include "Measurements.h"
#include "Results.h"
#include "Utils.h"
#include "Algorithms.h"

// Розмірність масиву відповідно до заданих випадків сортування
// P - перерізи, M - рядки, N - стовпчики
// Порядок зберігається

const int Sizes[23][3] = {
    {2, 2, 20000},
    {2, 20, 2000},
    {2, 200, 200},
    {2, 2000, 20},
    {2, 20000, 2},
    {2, 20, 20},
    {4, 20, 20},
    {8, 20, 20},
    {16, 20, 20},
    {32, 20, 20},
    {64, 20, 20},
    {3, 4, 4},
    {3, 8, 8},
    {3, 16, 16},
    {3, 32, 32},
    {3, 64, 64},
    {3, 128, 128},
    {3, 256, 256},
};

// Функція виведення 3Д масиву

void Out_Arr(int*** Arr, int P, int M, int N)
{
    int j, k, i;
    printf("     ======================================");
    for (k = 0; k < P; k++)
    {
        printf("\n\n");
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("\t%4d", Arr[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("     ======================================");
    printf("\n\n");
}

// Функція виведення вектору

void Out_Vec(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", Vector[i]);
    }
    printf("\n\n");
}


// Функція виведення таблиці часу

void Table(float ordered, float random, float reversed, int type)
{
    if (type == 1)
    {
        printf("\nSelect4Exchange (1) ");
    }
    if (type == 2)
    {
        printf("\nSelect4Exchange (2) ");
    }
    if (type == 3)
    {
        printf("\nSelect4Exchange (3) ");
    }
    printf("%7.5f %7.5f %7.5f \n", ordered, random, reversed);
}

// Функція для запуску відповідного алгоритму сортування
// для виводу часу 

void S_Time(int method, int type)
{
    system("cls");
    if (type == 1)
    {
        clock_t(*algorithm_arr[3])(int***, int, int, int) = { Select4Exchange1, Select4Exchange2, Select4Exchange3 };
        int P, M, N, cases = 18, current_case = 0;
        for (current_case; current_case < cases; current_case++)
        {
            P = Sizes[current_case][0];
            M = Sizes[current_case][1];
            N = Sizes[current_case][2];
            printf("\n================================================\n");
            printf("\n\nSizes of array : P = %d, M = %d, N = %d\n\n", P, M, N);
            printf("\t\t    Ordered    Random    Reversed \n");
            Arr3DMemory(P, M, N);
            if (method == 4)
            {
                for (int alg = 0; alg < 3; alg++)
                {
                    MeasurementSort_Arr(algorithm_arr[alg], P, M, N, alg + 1);
                }
            }
            else
            {
                MeasurementSort_Arr(algorithm_arr[method - 1], P, M, N, method);
            }
            Free_Memory(P, M);
        }
        cases = 18;
    }
    else if (type == 2)
    {
        clock_t(*algorithm_vec[1])(int) = { Select4ExchangeVec };
        printf("Length of vector : %d\n", F);
        printf("\t\t    Ordered    Random    Reversed \n");
        MeasurementSort_Vec(algorithm_vec[0], F, method);
    }
}

// Функція для запуску відповідного алгоритму сортування
// для демонстрації роботи сортування

void Sorting(int method, int type)
{
    if (type == 1)
    {
        clock_t(*algorithm_arr)(int***, int, int, int) = Select4Exchange1;
        int P = 3, M = 3, N = 4;
        Arr3DMemory(P, M, N);
        system("cls");
        if (method == 1)
        {
            printf("Select4Exchange1 sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N);
        }
        if (method == 2)
        {
            printf("Select4Exchange2 sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N);
            algorithm_arr = Select4Exchange2;
        }
        if (method == 3)
        {
            printf("Select4Exchange3 sorting for array , sizes : P = %d, M = %d, N = %d\n\n", P, M, N);
            algorithm_arr = Select4Exchange3;
        }
        for (int i = 1; i <= 3; i++)
        {
            Fill_3D_Arr(Arr, i, P, M, N);
            if (i == 1)
                printf("\t\t  Ordered\n");
            if (i == 2)
                printf("\t\t  Random\n");
            if (i == 3)
                printf("\t\t  Reversed\n");
            Out_Arr(Arr, P, M, N);
            algorithm_arr(Arr, P, M, N);
            if (i == 1)
                printf("\t\tOrdered sorted\n");
            if (i == 2)
                printf("\t\tRandom sorted\n");
            if (i == 3)
                printf("\t\tReversed sorted\n");
            Out_Arr(Arr, P, M, N);
        }
        Free_Memory(P, M);
    }
    if (type == 2)
    {
        int size = 10;
        clock_t(*algorithm_vec)(int) = Select4ExchangeVec;
        system("cls");
        printf("Select4Exchange sorting for vector , length : %d\n\n", size);
        for (int i = 1; i <= 3; i++)
        {
            if (i == 1)
                printf("Ordered\n");
            if (i == 2)
                printf("Random\n");
            if (i == 3)
                printf("Reversed\n");
            Fill_Vec(size, i);
            Out_Vec(size);
            algorithm_vec(size);
            if (i == 1)
                printf("Ordered sorted\n");
            if (i == 2)
                printf("Random sorted\n");
            if (i == 3)
                printf("Reversed sorted\n");
            Out_Vec(size);
        }
    }
}
