#include "Algorithms.h"
#include "Utils.h"
#include "Measurements.h"
#include <math.h>
#include <malloc.h>

// Функція для сортування алгоритмом "Вибір 4 - обмін"
// Першим методом обходу
// Та для підрахунку часу

clock_t Select4Exchange1(int*** Arr, int P, int M, int N)
{
    unsigned int* Vec;
    int L, R, Min, Max, z = 0, k = 0;;
    clock_t time_start, time_stop;
    Vec = (unsigned int*)malloc(P * M * N * sizeof(unsigned int));

    time_start = clock();
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int o = 0; o < N; o++)
            {
                Vec[z] = (int)Arr[i][j][o];
                z++;
            }
        }
    }
    for (int p = 0; p < P; p++)
    {
        L = p * M * N;
        R = M * N * (p + 1) - 1;
        while (L < R)
        {
            for (int j = L; j < R + 1; j++)
            {
                if (Vec[j] < Vec[L])
                {
                    Min = Vec[j];
                    Vec[j] = Vec[L];
                    Vec[L] = Min;
                }
                else if (Vec[j] > Vec[R])
                {
                    Max = Vec[j];
                    Vec[j] = Vec[R];
                    Vec[R] = Max;
                }
            }
            L++;
            R--;
        }
    }
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int o = 0; o < M; o++)
            {
                Arr[i][o][j] = Vec[k];
                k++;
            }
        }
    }
    time_stop = clock();

    free(Vec);
    return time_stop - time_start;
}


// Функція для сортування алгоритмом "Вибір 4 - обмін"
// Другим методом обходу
// Та для підрахунку часу сортуавння цим методом

clock_t Select4Exchange2(int*** Arr, int P, int M, int N)
{
    int L, R, Min, Max, p;
    clock_t time_start, time_stop;

    time_start = clock();
    for (p = 0; p < P; p++) {
        L = 0;
        R = M * N - 1;
        while (L < R) {
            for (int j = L; j < R + 1; j++) {
                if (Arr[p][j % M][j / M] < Arr[p][L % M][L / M]) {
                    Min = Arr[p][j % M][j / M];
                    Arr[p][j % M][j / M] = Arr[p][L % M][L / M];
                    Arr[p][L % M][L / M] = Min;
                }
                else if (Arr[p][j % M][j / M] > Arr[p][R % M][R / M]) {
                    Max = Arr[p][j % M][j / M];
                    Arr[p][j % M][j / M] = Arr[p][R % M][R / M];
                    Arr[p][R % M][R / M] = Max;
                }
            }
            L++;
            R--;
        }
    }
    time_stop = clock();

    return time_stop - time_start;
}

// Функція для сортування алгоритмом "Вибір 4 - обмін"
// Третім методом обходу
// Та для підрахунку часу сортуавння цим методом

clock_t Select4Exchange3(int*** Arr, int P, int M, int N)
{
    int Min, Max;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int p = 0; p < P; p++)
    {
        int L = 0;
        int R = N - 1;
        while (L <= R)
        {
            for (int x = 0; x <= N / 2; x++)
            {
                for (int L1 = 0; L1 < M; L1++)
                {
                    for (int y = 0; y < M; y++)
                    {
                        if (Arr[p][y][x] > Arr[p][L1][L])
                        {
                            Min = Arr[p][y][x];
                            Arr[p][y][x] = Arr[p][L1][L];
                            Arr[p][L1][L] = Min;
                        }
                    }
                }
            }
            L++;
        }
        while (R >= 0)
        {
            for (int x = N - 1; x >= N / 2; x--)
            {
                for (int R1 = M - 1; R1 >= 0; R1--)
                {
                    for (int y = M - 1; y >= 0; y--)
                    {
                        if (Arr[p][y][x] < Arr[p][R1][R])
                        {
                            Max = Arr[p][y][x];
                            Arr[p][y][x] = Arr[p][R1][R];
                            Arr[p][R1][R] = Max;
                        }
                    }
                }
            }
            R--;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

// Функція для сортування алгоритмом "Вибір 4 - обмін"
// Для вектору
// Та для підрахунку часу сортуавння цим методом

clock_t Select4ExchangeVec(int size)
{
    int L, R, Min, Max;
    L = 0;
    R = size - 1;
    clock_t time_start, time_stop;

    time_start = clock();
    while (L < R)
    {
        for (int j = L; j < R + 1; j++)
        {
            if (Vector[j] < Vector[L])
            {
                Min = Vector[j];
                Vector[j] = Vector[L];
                Vector[L] = Min;
            }
            else if (Vector[j] > Vector[R])
            {
                Max = Vector[j];
                Vector[j] = Vector[R];
                Vector[R] = Max;
            }
        }
        L++;
        R--;
    }
    time_stop = clock();

    return time_stop - time_start;
}
