#include "Measurements.h"
#include "Utils.h"
#include "Results.h"

clock_t Res[measurements_number];

// Функція обробки і усереднення часу роботи алгоритма

float MeasurementProc()
{
    long int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j = 0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;

        for (int i = R - 1; i >= L; i--)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }
    Sum = 0;
    for (
        int i = rejected_number + min_max_number;
        i < measurements_number - min_max_number;
        i++
        )
    {
        Sum = Sum + Res[i];
    }
    AverageValue = (float)Sum / (float)(measurements_number - 2 * min_max_number - rejected_number);
    return AverageValue;
}

// Функція, яка повністю оброблює час сортувань масиву та виводить на екран

void MeasurementSort_Arr(clock_t(*algorithm)(int*** Arr, int P, int M, int N), int P, int M, int N, int type)
{
    float Sorting_time[3];
    srand(time(NULL));
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            Fill_3D_Arr(Arr, j + 1, P, M, N);
            Res[i] = algorithm(Arr, P, M, N);
        }
        Sorting_time[j] = MeasurementProc();
    }

    // Вивід таблиці часу 

    Table(Sorting_time[0], Sorting_time[1], Sorting_time[2], type);
}

// Функція, яка повністю оброблює час сортувань вектору та виводить на екран

void MeasurementSort_Vec(clock_t(*algorithm)(int size), int size, int type)
{
    float Sorting_time[3];
    srand(time(NULL));
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            Fill_Vec(size, j + 1);
            Res[i] = algorithm(size);
        }
        Sorting_time[j] = MeasurementProc();
    }

    // Вивід таблиці часу 

    Table(Sorting_time[0], Sorting_time[1], Sorting_time[2], type);
}
