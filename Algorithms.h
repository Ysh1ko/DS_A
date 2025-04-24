#ifndef ALGORITHMS_INCLUDED_H_
#define ALGORITHMS_INCLUDED_H_
#include "Measurements.h"

// Сортування алгоритмом "Вибір 4 - обмін", перший метод обходу

clock_t Select4Exchange1(int*** Arr, int P, int M, int N);

// Сортування алгоритмом "Вибір 4 - обмін", другий метод обходу

clock_t Select4Exchange2(int*** Arr, int P, int M, int N);

// Сортування алгоритмом "Вибір 4 - обмін", третій метод обходу

clock_t Select4Exchange3(int*** Arr, int P, int M, int N);

// Сортування алгоритмом "Вибір 4 - обмін", для вектора

clock_t Select4ExchangeVec(int size);

#endif 
