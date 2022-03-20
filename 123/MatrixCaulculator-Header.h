#pragma once
//Матричный калькулятор (Кривоносиков Александр)
#include <iostream>
#include <locale.h>
using namespace std;

void Enter(int& n, int& m);
void SetMatrix(int n, int m, double** A);
void OutputMatrix(int n, int m, double** A);
void GetMatr(double** A, double** p, int i, int j, int m);
double Determinant(double** A, int m);
void TransponMtx(double** A, double** tA, int n, int m);
void DiffMatrix(int n, int m, double** A);
void SummMartrix(int n, int m, double** A);
void MultiplMatrix(int n, int m, double** A);
void MultiplNumber(int n, int m, double** A);
void SummNumber(int n, int m, double** A);
void inversionMatrix(double** A, int n);
