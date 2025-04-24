#ifndef MEASUREMENTS_INCLUDED_H_
#define MEASUREMENTS_INCLUDED_H_

// ������ �������� �������

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// �������� ������� ����� ���� ������

#define measurements_number 28

// ʳ������ ��������� ���������� �����

#define rejected_number 2

// ʳ������ ��������� ����� � ��������� (��� �������������) ����������

#define min_max_number 3

// ����� � ���������� ���� ������

extern clock_t Res[measurements_number];

// ������� ������� � ����������� ������� �����

float MeasurementProc();

// �������, ��� �������� ��� ��������� ������

void MeasurementSort_Arr(clock_t(*abc)(int*** Arr, int P, int M, int N), int P, int M, int N, int type);

// �������, ��� ������� �������� ��� ��������� �������

void MeasurementSort_Vec(clock_t(*abc)(int size), int size, int type);
#endif 
