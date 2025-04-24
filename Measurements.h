#ifndef MEASUREMENTS_INCLUDED_H_
#define MEASUREMENTS_INCLUDED_H_

// Імпорт потрібних бібліотек

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Загальна кількість вимірів часу роботи

#define measurements_number 28

// Кількість відкинутих початкових вимірів

#define rejected_number 2

// Кількість відкинутих вимірів з мінімільними (або максимальними) значеннями

#define min_max_number 3

// Масив зі значеннями часу роботи

extern clock_t Res[measurements_number];

// Функція обробки і усереднення значень вимірів

float MeasurementProc();

// Функція, яка оброблює час сортувань масиву

void MeasurementSort_Arr(clock_t(*abc)(int*** Arr, int P, int M, int N), int P, int M, int N, int type);

// Функція, яка повністю оброблює час сортувань вектора

void MeasurementSort_Vec(clock_t(*abc)(int size), int size, int type);
#endif 
