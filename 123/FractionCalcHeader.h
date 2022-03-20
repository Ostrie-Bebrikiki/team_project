// Ответственный - Скатенок Илья
#pragma once
#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;



int CheckError(string fraction);

// Ввод и вывод дробей
void EnterFractionStart(string fractionLeft, string fractionRight, int &nums_array, double *Nums);

void EnterFraction(string fraction, double* Nums, int* nums_array);

void ShowFractions(double *Nums, double numerator, double denumerator, char menu);

int IsNullFraction(double numerator, double denumerator);

void Sokr(double a, double b);

void Sravn(double Chisl, double Znamen, double Chisl2, double Znamen2);
//

int FindMaxDeviver(int a, int b);


