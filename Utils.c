#include "Utils.h"
int*** Arr;

// Функція динамічного виділення пам'яті для масиву

void Arr3DMemory(int P, int M, int N)
{
    Arr = (int***)malloc(P * sizeof(int**));
    for (int k = 0; k < P; k++)
    {
        Arr[k] = (int**)malloc(M * sizeof(int*));
        for (int i = 0; i < M; i++)
            Arr[k][i] = (int*)malloc(N * sizeof(int));
    }
}

// Функція заповняє масив відповідно до параметру sort
// (впорядкований, випадковий, обернено-впорядкований)


void Fill_3D_Arr(int*** Arr, int sort, int P, int M, int N)
{
    int end = P * M * N, start = 1;
    for (int k = 0; k < P; k++)
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
            {
                if (sort == 1)
                    Arr[k][i][j] = start++;
                if (sort == 2)
                    Arr[k][i][j] = rand() % (P * M * N);
                if (sort == 3)
                    Arr[k][i][j] = end--;
            }
}

// Функція заповняє вектор відповідно до параметру sort
// (впорядкований, випадковий, обернено-впорядкований)

void Fill_Vec(int size, int sort)
{
    int end = size, start = 1;
    for (int i = 0; i < size; i++)
    {
        if (sort == 1)
            Vector[i] = start++;
        if (sort == 2)
            Vector[i] = rand() % (size);
        if (sort == 3)
            Vector[i] = end--;
    }
}

// Функція звільнення пам'яті , виділенної під масив

void Free_Memory(int P, int M)
{
    for (int k = 0; k < P; k++)
    {
        for (int i = 0; i < M; i++)
            free(Arr[k][i]);
        free(Arr[k]);
    }
    free(Arr);
}
