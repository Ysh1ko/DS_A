#ifndef UTILS_INCLUDED_H_
#define UTILS_INCLUDED_H_

// ������ �������� �������

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

// ���������� ������ �������

#define F 40000

// ���������� ����������� ������

int*** Arr;

// ���������� ������������ ������ ���������� ������

int Vector[F];

// ������� ���������� �������� ���'�� ��� ������

void Arr3DMemory(int P, int M, int N);

// ������� �������� ����� �������� �� ��������� sort
// (�������������, ����������, ��������-�������������)

void Fill_3D_Arr(int*** Arr, int order, int P, int M, int N);

// ������� �������� ������ �������� �� ��������� sort
// (�������������, ����������, ��������-�������������)

void Fill_Vec(int size, int order);

// ������� ��������� ���'�� , �������� �� �����

void Free_Memory(int P, int M);
#endif 
