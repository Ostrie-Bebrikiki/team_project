#include "PolynomialCalc.h"
#include "bebra.h"

//Функции калькулятора многочленов
//Ответственный - Коростелев

bool NumberCorrect(string num)
{
	int countCom = 0;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') num[i] = ',';
		if (num[i] == ',') countCom++;
		if (isdigit(num[i]) == 0 && num[i] != ',') {
			return false;
		}
		else if (countCom > 1) {
			return false;
		}
	}
	return true;
}

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
			printf_s("5: Производная\n");
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
				system("cls");
				return;
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
	string n1, n2;
	int flag1, flag2;
	do {
		printf_s("\tСЛОЖЕНИЕ МНОГОЧЛЕНОВ\n");// Запрос степеней многочленов
		printf_s("Введите степень первого многочлена: "); cin >> n1; //scanf_s("%d", &slag1.n);
		printf_s("Введите степень второго многочлена: "); cin >> n2; //scanf_s("%d", &slag2.n);
		if (NumberCorrect(n1) == false || NumberCorrect(n2) == false) system("cls");
		else {
			slag1.n = stoi(n1);
			slag2.n = stoi(n2);
			if (slag1.n <= 0 || slag2.n <= 0 || slag1.n >= 50 || slag2.n >= 50) system("cls");
		}
	} while (slag1.n <= 0 || slag2.n <= 0 || slag1.n >= 50 || slag2.n >= 50 || NumberCorrect(n1) == false || NumberCorrect(n2) == false);
	
	printf_s("%d", slag1.n);

	do {
		printf_s("Введите константы первого многочлена: \n"); //Ввод констант многочленов
		flag1 = PolynomInput(slag1);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	do {
		printf_s("Введите константы второго многочлена: \n");
		flag2 = PolynomInput(slag2);
		if (flag2 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag2 == false);

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

	system("pause");
	system("cls");
	//funcExit();
}

void PolynomialSubstraction(){
	bool flag1, flag2;
	Polynomial sub1, sub2;
	string n1, n2;
	do {
		printf_s("\tВЫЧИТАНИЕ МНОГОЧЛЕНОВ\n");// Запрос степеней многочленов
		printf_s("Введите степень первого многочлена: "); cin >> n1; //scanf_s("%d", &slag1.n);
		printf_s("Введите степень второго многочлена: "); cin >> n2; //scanf_s("%d", &slag2.n);
		if (NumberCorrect(n1) == false || NumberCorrect(n2) == false) system("cls");
		else {
			sub1.n = stoi(n1);
			sub2.n = stoi(n2);
			if (sub1.n <= 0 || sub2.n <= 0 || sub1.n >= 50 || sub2.n >= 50) system("cls");
		}
	} while (sub1.n <= 0 || sub2.n <= 0 || sub1.n >= 50 || sub2.n >= 50 || NumberCorrect(n1) == false || NumberCorrect(n2) == false);

	do {
		printf_s("Введите константы первого многочлена: \n");
		flag1 = PolynomInput(sub1);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	do {
		printf_s("Введите константы первого многочлена: \n");
		flag2 = PolynomInput(sub2);
		if (flag2 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag2 == false);

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

	system("pause");
	system("cls");
	//funcExit();
}

void PolynomialMulti()
{
	bool flag1, flag2;
	Polynomial fact1, fact2;
	string n1, n2;
	do {
		printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНОВ\n");// Запрос степеней многочленов
		printf_s("Введите степень первого многочлена: "); cin >> n1; //scanf_s("%d", &slag1.n);
		printf_s("Введите степень второго многочлена: "); cin >> n2; //scanf_s("%d", &slag2.n);
		if (NumberCorrect(n1) == false || NumberCorrect(n2) == false) system("cls");
		else {
			fact1.n = stoi(n1);
			fact2.n = stoi(n2);
			if (fact1.n <= 0 || fact2.n <= 0 || fact1.n >= 50 || fact2.n >= 50) system("cls");
		}
	} while (fact1.n <= 0 || fact2.n <= 0 || fact1.n >= 50 || fact2.n >= 50 || NumberCorrect(n1) == false || NumberCorrect(n2) == false);

	//ct1.n = stoi(n1);
	//fact2.n = stoi(n2);

	do {
		printf_s("Введите константы первого многочлена: \n");
		flag1 = PolynomInput(fact1);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	do {
		printf_s("Введите константы первого многочлена: \n");
		flag2 = PolynomInput(fact2);
		if (flag2 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag2 == false);

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

	system("pause");
	system("cls");
	//funcExit();
	//system("cls");
}

void PolynomialMultiNumber()
{
	bool flag1;
	Polynomial pol;
	double number;
	string num;
	int countComma = 0;
	string n1;


	do {
		printf_s("\tУМНОЖЕНИЕ МНОГОЧЛЕНА НА ЧИСЛО\n");// Запрос степеней многочленов
		printf_s("Введите степень многочлена: "); cin >> n1;
		if (NumberCorrect(n1) == false) system("cls");
		else {
			pol.n = stoi(n1);
			if (pol.n <= 0 || pol.n >= 50) system("cls");
		}
	} while (pol.n <= 0 || pol.n >= 50 || NumberCorrect(n1) == false);

	do {
		printf_s("Введите константы многочлена: \n");
		flag1 = PolynomInput(pol);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	printf_s("Введите число : "); cin >> num;

	NumberCorrect(num);

	number = stof(num);

	printf_s("Введенный многочлен: ");
	PolynomOutput(pol);

	printf_s("Введенное число: %.3lf\n", number);

	if (number == 0) {
		printf_s("Результат умножения: 0");
	}
	else {
		for (int i = pol.n; i >= 0; i--) {
			pol.c[i] *= number;
		}
		printf_s("Результат умножения: ");
		PolynomOutput(pol);
	}

	system("pause");
	system("cls");
	//funcExit();
	//system("cls");
}

void PolynomialDerivative()
{
	bool flag1;
	Polynomial pol;
	string n1;

	do {
		printf_s("\tПРОИЗВОДНАЯ ОТ МНОГОЧЛЕНА\n");// Запрос степеней многочленов
		printf_s("Введите степень многочлена: "); cin >> n1;
		if (NumberCorrect(n1) == false) system("cls");
		else {
			pol.n = stoi(n1);
			if (pol.n <= 0 || pol.n >= 25) system("cls");
		}
	} while (pol.n <= 0 || pol.n >= 25 || NumberCorrect(n1) == false);
	//pol.n = stoi(n1);

	do {
		printf_s("Введите константы многочлена: \n");
		flag1 = PolynomInput(pol);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	printf_s("Введенный многочлен: ");
	PolynomOutput(pol);

	Polynomial polDer;
	polDer.n = pol.n - 1;

	for (int i = polDer.n; i >= 0; i--) {
		polDer.c[i] = pol.c[i + 1] * (i + 1);
	}

	printf_s("Производная от многочлена: ");
	PolynomOutput(polDer);

	system("pause");
	system("cls");
	//funcExit();
	//system("cls");
}

void PolynomialDivision()
{
	bool flag1, flag2;
	Polynomial div1, div2;
	string n1, n2;

	do {
		printf_s("\tДЕЛЕНИЕ МНОГОЧЛЕНОВ\n");// Запрос степеней многочленов
		printf_s("Введите степень первого многочлена: "); cin >> n1;
		printf_s("Введите степень второго многочлена: "); cin >> n2;
		if (NumberCorrect(n1) == false || NumberCorrect(n2) == false) system("cls");
		else {
			div1.n = stoi(n1);
			div2.n = stoi(n2);
			if (div1.n <= 0 || div1.n >= 50 || div2.n <= 0 || div2.n >= 50) system("cls");
		}
	} while (div1.n <= 0 || div1.n >= 50 || div2.n <= 0 || div2.n >= 50 || NumberCorrect(n1) == false || NumberCorrect(n2) == false);

	do {
		printf_s("Введите константы первого многочлена: \n");
		flag1 = PolynomInput(div1);
		if (flag1 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag1 == false);

	do {
		printf_s("Введите константы второго многочлена: \n");
		flag2 = PolynomInput(div2);
		if (flag2 == false) {
			printf_s("Было введено некорректное значение\n");
		}
	} while (flag2 == false);

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
	int countComma, countMinus;
	int k = slag.n;
	for (k; k >= 0; k--) {
		countComma = 0;
		countMinus = 0;
		printf_s("c[%d] = ", k); cin >> number;
		for (int i = 0; i < number.length(); i++) {
			if (number[i] == '.') number[i] = ',';
			if (number[i] == ',') countComma++;
			if (isdigit(number[i]) == 0 && number[i] != ',' && number[i] != '-')
				flag = false;
			else if (countComma > 1 || countMinus > 1) flag = false;
			if (flag == false) break;
		}
		if (flag == false) return false;
		else {
			slag.c[k] = stof(number);
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

int Kor(string num)
{
	int countComma = 0;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') num[i] = ',';
		if (num[i] == ',') countComma++;
		if (isdigit(num[i]) == 0 && num[i] != ',') {
			printf_s("Было введено некорректное значение\n");
			return 1;
		}
		else if (countComma > 1) {
			printf_s("Было введено некорректное значение\n");
			return 1;
		}
	}
	return 0;
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



