#include "PolynomialCalc.h"
#include "bebra.h"

//Функции калькулятора многочленов
//Ответственный - Коростелев

void PolynomialMenu()
{
	char choose;
	bool flag = false;
	do {
		do {
			system("cls");
			printf_s("\tКАЛЬКУЛЯТОР МНОГОЧЛЕНОВ\n");
			printf_s("Выберите действие:\n");
			printf_s("1: Сложение\n");
			printf_s("2: Вычитание\n");
			printf_s("3: Умножение\n");
			printf_s("4: Умножение на число\n");
			printf_s("5: Производная\"\n");
			printf_s("6: Деление\n");
			printf_s("0: Выйти\n");
			printf_s("Выбрано: "); choose = _getche();
			if (choose < '0' || choose > '6') {
				system("cls");
			}
			else flag = true;
		} while (flag == false);

		system("cls");

		switch (choose) {
		case '1': PolynomialSum(); break;
		case '2': PolynomialSubstraction(); break;
		case '3': PolynomialMulti(); break;
		case '4': PolynomialMultiNumber(); break;
		case '5': PolynomialDerivative(); break;
		case '6': PolynomialDivision(); break;
		case '0': {
			do {
				printf_s("Вы точно хотите выйти?\ny - Да\nn - Нет\nВыбрано: "); choose = _getche();
				if (choose == 'y') return;
				else if (choose == 'n') {
					system("cls");
					break;
				}
				else system("cls");
			} while (choose != 'y' || choose != 'n');
		}; break;
		default: break;
		}
	} while (choose != '0');
	system("cls");
}

void PolynomialSum()
{
	Polynomial slag1, slag2;
	do {
		printf_s("\tСЛОЖЕНИЕ МНОГОЧЛЕНОВ\n");
		printf_s("Введите степень первого многочлена: "); scanf_s("%d", &slag1.n); // Запрос степеней многочленов
		printf_s("Введите степень второго многочлена: "); scanf_s("%d", &slag2.n);
		if (slag1.n <= 0 || slag2.n <= 0) system("cls");
	} while (slag1.n <= 0 || slag2.n <= 0 || slag1.n >= 50 || slag2.n >= 50);

	printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
	if (PolynomInput(slag1) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Введите константы второго многочлена: \n");
	if (PolynomInput(slag2) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Первый многочлен: "); // Вывод первого многочлена
	PolynomOutput(slag1);

	printf_s("Второй многочлен: "); // Вывод первого многочлена
	PolynomOutput(slag2);

	int max;

	if (slag1.n > slag2.n) max = slag1.n;
	else max = slag2.n;

	Polynomial sumPolynom;

	sumPolynom.n = max;

	for (int i = max; i >= 0; i--) {
		sumPolynom.c[i] = slag1.c[i] + slag2.c[i];
	}

	printf_s("Сумма многочленов: ");
	PolynomOutput(sumPolynom);

	funcExit();
}

void PolynomialSubstraction(){
	Polynomial sub1, sub2;
	do {
		printf_s("\tВЫЧИТАНИЕ МНОГОЧЛЕНОВ\n");
		printf_s("Введите степень первого многочлена: "); scanf_s("%d", &sub1.n); // Запрос степеней многочленов
		printf_s("Введите степень второго многочлена: "); scanf_s("%d", &sub2.n);
		if (sub1.n <= 0 || sub2.n <= 0) system("cls");
	} while (sub1.n <= 0 || sub2.n <= 0 || sub1.n >= 50 || sub2.n >= 50);

	printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
	if (PolynomInput(sub1) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Введите константы второго многочлена: \n");
	if (PolynomInput(sub2) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Первый многочлен: "); // Вывод первого многочлена
	PolynomOutput(sub1);

	printf_s("Второй многочлен: "); // Вывод первого многочлена
	PolynomOutput(sub2);

	int max;

	if (sub1.n > sub2.n) max = sub1.n;
	else max = sub2.n;

	Polynomial subPolynom;
	subPolynom.n = max;

	for (int i = max; i >= 0; i--) {
		subPolynom.c[i] = sub1.c[i] - sub2.c[i];
	}

	printf_s("Разность многочленов: "); 
	PolynomOutput(subPolynom); //вывод


	funcExit();
	//system("cls");
}

void PolynomialMulti()
{
	Polynomial fact1, fact2;
	do {
		printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНОВ\n");
		printf_s("Введите степень первого многочлена: "); scanf_s("%d", &fact1.n); // Запрос степеней многочленов
		printf_s("Введите степень второго многочлена: "); scanf_s("%d", &fact2.n);
		if (fact1.n <= 0 || fact2.n <= 0 || fact1.n >= 25 || fact2.n >= 25) system("cls");
	} while (fact1.n <= 0 || fact2.n <= 0 || fact1.n >= 25 || fact2.n >= 25);

	printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
	if (PolynomInput(fact1) == false) {
		printf_s("Было введено некорректное значение");
		if (funcExit() == true) return;
	}

	printf_s("Введите константы второго многочлена: \n");
	if (PolynomInput(fact2) == false) {
		printf_s("Было введено некорректное значение");
		if (funcExit() == true) return;
	}

	printf_s("Первый многочлен: "); // Вывод первого многочлена
	PolynomOutput(fact1);

	printf_s("Второй многочлен: "); // Вывод первого многочлена
	PolynomOutput(fact2);

	int maxN = fact1.n + fact2.n;
	Polynomial Multi;
	Multi.n = maxN;

	for (int i = fact1.n; i >= 0; i--) {
		for (int k = fact2.n; k >= 0; k--) {
			Multi.c[i + k] += fact1.c[i] * fact2.c[k];
		}
	}

	printf_s("Произведение многочленов:");
	PolynomOutput(Multi);


	funcExit();
	//system("cls");
}

void PolynomialMultiNumber()
{
	Polynomial pol;
	double number;
	string num;
	int countComma = 0;

	do {
		printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНА НА ЧИСЛО\n");
		printf_s("Введите степень многочлена: "); scanf_s("%d", &pol.n); // Запрос степеней многочленов
		if (pol.n <= 0 || pol.n > 50) system("cls");
	} while (pol.n <= 0 || pol.n >= 50);

	printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
	if (PolynomInput(pol) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	do {
		printf_s("Введите число (кроме 0): "); cin >> num;
		if (stoi(num) == 0) system("cls");
	} while (stoi(num) == 0);

	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') num[i] = ',';
		if (num[i] == ',') countComma++;
		if (isdigit(num[i]) == 0 && (ispunct(num[i]) == 0 && num[i] != ',')) {
			printf_s("Было введено некорректное значение\n");
			if (funcExit() == true) return;
		}
		else if (countComma > 1) {
			printf_s("Было введено некорректное значение\n");
			if (funcExit() == true) return;
		}
	}

	number = stof(num);

	printf_s("Введенный многочлен: ");
	PolynomOutput(pol);

	printf_s("Введенное число: %.3lf\n", number);

	for (int i = pol.n; i >= 0; i--) {
		pol.c[i] *= number;
	}

	printf_s("Результат умножения: ");
	PolynomOutput(pol);


	funcExit();
	//system("cls");
}

void PolynomialDerivative()
{
	Polynomial pol;

	do {
		printf_s("\tПРОИЗВОДНАЯ ОТ МНОГОЧЛЕНА\n");
		printf_s("Введите степень многочлена: "); scanf_s("%d", &pol.n); // Запрос степеней многочленов
		if (pol.n <= 0 || pol.n > 50) system("cls");
	} while (pol.n <= 0 || pol.n >= 50);

	printf_s("Введите константы многочлена:\n");
	if (PolynomInput(pol) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Введенный многочлен: ");
	PolynomOutput(pol);

	Polynomial polDer;
	polDer.n = pol.n - 1;

	for (int i = polDer.n; i >= 0; i--) {
		polDer.c[i] = pol.c[i + 1] * (i + 1);
	}

	printf_s("Производная от многочлена: ");
	PolynomOutput(polDer);


	funcExit();
	//system("cls");
}

void PolynomialDivision()
{
	Polynomial div1, div2;
	do {
		printf_s("\tДЕЛЕНИЕ МНОГОЧЛЕНОВ\n");
		printf_s("Введите степень первого многочлена: "); scanf_s("%d", &div1.n); // Запрос степеней многочленов
		printf_s("Введите степень второго многочлена: "); scanf_s("%d", &div2.n);
		if (div1.n <= 0 || div2.n <= 0 || div1.n > 50 || div2.n > 50 || div2.n > div1.n) system("cls");
	} while (div1.n <= 0 || div2.n <= 0 || div1.n > 50 || div2.n > 50 || div2.n > div1.n);

	printf_s("Введите константы первого многочленена:\n");
	if (PolynomInput(div1) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Введите константы второго многочленена:\n");
	if (PolynomInput(div2) == false) {
		printf_s("Было введено некорректное значение\n");
		if (funcExit() == true) return;
	}

	printf_s("Первый многочлен: ");
	PolynomOutput(div1);

	printf_s("Второй многочлен: ");
	PolynomOutput(div2);

	Polynomial res, temp;
	temp.n = div1.n;
	res.n = div1.n - div2.n;

	bool flag = true;
	double mn;
	int endofMassive = 0;
	int k = 0;

	while (flag) {
		//if (div1.n > div2.n) {
			for (int i = div1.n, j = div2.n; i >= 0; i--, j--)
				if (j < 0)
					temp.c[i] = 0;
				else
					temp.c[i] = div2.c[j];
		//}

		mn = div1.c[div1.n] / temp.c[div1.n];
		res.c[res.n - k] = mn;
		k++;

		for (int i = 0; i <= div1.n; i++)
			temp.c[i] *= mn;
		for (int i = 0; i <= div1.n; i++)
			div1.c[i] -= temp.c[i];

		div1.n--;
		if (div2.n > div1.n) flag = false;
	}

	printf_s("Результат деления: ");
	PolynomOutput(res);

	funcExit();

	//system("cls");
}

bool PolynomInput(Polynomial &slag)
{
	bool flag = true;
	string number;
	int k, countDots, countComma;
	for (int j = slag.n; j >= 0; j--) {
		countComma = 0;
		printf_s("c[%d] = ", j); cin >> number;
		for (int i = 0; i < number.length(); i++) {
			if (number[i] == '.') number[i] = ',';
			if (number[i] == ',') countComma++;
			if (isdigit(number[i]) == 0 && (ispunct(number[i]) == 0 && number[i] != ','))
				flag = false;
			else if (countComma > 1) flag = false;
			if (flag == false) break;
		}
		if (flag == false) return false;
		else {
			slag.c[j] = stof(number);
		}
	}
	return true;
}

void PolynomOutput(Polynomial& slag)
{
	if (slag.c[slag.n] == 1) printf_s("x^%d", slag.n);
	else if (slag.c[slag.n] > 1 || slag.c[slag.n] < 0) printf_s("%.3lfx^%d", slag.c[slag.n], slag.n);

	for (int i = slag.n - 1; i >= 2; i--) {
		if (slag.c[i] > 1) printf_s("+%.3lfx^%d", slag.c[i], i);
		else if (slag.c[i] == 1) printf_s("+x^%d", i);
		else if (slag.c[i] < 0) printf_s("%.3lfx^%d", slag.c[i], i);
	}

	if (slag.c[1] > 1) printf_s("+%.3lfx", slag.c[1]);//Для x^1
	else if (slag.c[1] == 1) printf_s("+x");
	else if (slag.c[1] < 0) printf_s("%.3lfx", slag.c[1]);

	if (slag.c[0] > 1) printf_s("+%.3lf\n", slag.c[0]);//Для x^0
	else if (slag.c[0] == 1) printf_s("+1\n");
	else if (slag.c[0] < 0) printf_s("%.3lf\n", slag.c[0]);
}

bool funcExit()
{
	char choose;
	do {
		printf_s("Выйти в меню?\ny - Да\nВыбрано: "); choose = _getche();
		if (choose == 'y') return true;
		else system("cls");
	} while (choose != 'y');
}



