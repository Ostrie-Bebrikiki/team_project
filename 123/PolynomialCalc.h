#pragma once

//Заголовочный файл для калькулятора многочленов
//Ответственный - Коростелев

struct Polynomial { //Структура для многочлена
	double c[50] = { 0 }; //Массив для хранения констант многочлена
	int n; //Максимальная степень многочлена
};

void PolynomialMenu(); //Меню
void PolynomialSum(); //Сложение
void PolynomialSubstraction(); //Вычитание
void PolynomialMulti(); //Умножение
void PolynomialMultiNumber(); //Умножение на число
void PolynomialDerivative(); //Производная
void PolynomialDivision(); //Деление	

void PolynomInput(Polynomial &slag); //Ввод многочлена
void PolynomOutput(Polynomial& slag); //Вывод многочлена

void funcExit(); //Выход из функции