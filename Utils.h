#ifndef UTILS_INCLUDED_H_
#define UTILS_INCLUDED_H_

// Імпорт потрібних бібліотек

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

// Оголошення розміру вектору

#define F 40000

// Оголошення тривимірного масиву

int*** Arr;

// Оголошення одновимірного масиву відповідного розміру

int Vector[F];

// Функція динамічного виділення пам'яті для масиву

void Arr3DMemory(int P, int M, int N);

// Функція заповняє масив відповідно до параметру sort
// (впорядкований, випадковий, обернено-впорядкований)

void Fill_3D_Arr(int*** Arr, int order, int P, int M, int N);

// Функція заповняє вектор відповідно до параметру sort
// (впорядкований, випадковий, обернено-впорядкований)

void Fill_Vec(int size, int order);

// Функція звільнення пам'яті , виділенної під масив

void Free_Memory(int P, int M);
#endif 
