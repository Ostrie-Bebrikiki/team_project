#include "Functions.h"

double f(char ch, double x, double a, double b, double c, double d) {
	switch (ch) {
	case '2': return a * pow(x, (float) b) + c;
	case '3': return a * pow(b, c * x) + d;
	case '4': return a * log(b * x) + c;
	case '5': return a * sin(b * x + c) + d;
	case '6': return a * cos(b * x + c) + d;
	default: return 0;
	}
}
void choose(char &s) {
	while (true) {
		std::cout << "�������� �������" << endl << "1 - ������� ������� N: a0+a1**x+a2*x^2+...+aN*x^N" << endl
			<< "2 - ���������: a*x^b+c" << endl << "3 - �������������: a*b^(c*x)+d" << endl << "4 - ���������������: a*ln(b*x)+c" << endl
			<< "5 - ���������: a*sin(b*x+c)+d" << endl << "6 - �����������: a*cos(b*x+c)+d" <<endl<<"0 - �����" << endl << '>';
		s = _getche();
		if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6') break;
	}
}



void menu_Func() {
	char s, ch;
	
	while (true) {
		while (true) {
			system("cls");
			cout << "�������� ��������" << endl << "1 - ���������� ������������� ���������" << endl << "2 - ���������� ������� �������"
				<< endl << "3 - ����� ����� ��� Y = 0 �� �������" << endl << "4 - ����� ����������� �� �������" 
				<< endl << "0 - ����� � ������� ����" << endl << '>';
			s = _getche();
			if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		cout << pow(3, 3.2);
		if (s == '0') return;
		cout << endl;
		choose(ch);
		cout << endl;
		if (ch == '0') continue;
		double a = 0, b = 0, c = 0, d = 0;
		if (ch != '1') {
			input_d(a, "������� a"); input_d(b, "������� b"); input_d(c, "������� c");
		}
		if (ch == '3' || ch == '5' || ch == '6') {
			input_d(d, "������� d");
		}
		switch (s) {
		case '1': integral(ch,a,b,c,d); break;
		case '2': graph(ch, a, b, c, d); break;
		case '3': root_f(ch, a, b, c, d); break;
		case '4': extremum(ch, a, b, c, d); break;
		default: break;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
}

void integral(char ch, double a, double b, double c, double d) {
	double D1, D2, eps;
	while (true) {
		input_d(D1, "������� ����� �������");
		input_d(D2, "������� ������ �������");
		if (D2 < D1) cout << "����� ������� �� ����� ���� ������ ������" << endl;
		else break;
	}
	if (ch != '1') {
		while (true) {
			input_d(eps, "������� �����������");
			if (eps > 1 || eps <= 0) cout << "����������� �� ����� ���� ������ ��� ����� ���� � �� ����� ���� ������ 1" << endl;
			else break;
		}
		double I = eps + 1, I1 = 0;
		for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
		{
			double h, sum2 = 0, sum4 = 0, sum = 0;
			h = (D2 - D1) / (2 * N);
			for (int i = 1; i <= 2 * N - 1; i += 2)
			{
				sum4 += f(ch, D1 + h * i, a, b, c, d);
				sum2 += f(ch, D1 + h * (i + 1), a, b, c, d);
			}
			sum = f(ch, D1, a, b, c, d) + 4 * sum4 + 2 * sum2 - f(ch, D2, a, b, c, d);
			I = I1;
			I1 = (h / 3) * sum;
			cout << I1 << ' ';
		}
		cout << "�����: " << I1;
	}
	else {
		int N;
		double x = D1, x1 = D2;
		while (true) {
			input(N, "������� ������� N");
			if (N < 0) cout << "N >=0" << endl;
			else break;
		}
		N += 1;
		double sum = 0,sum1 = 0, a0;
		for (int i = 0; i < N; i++, x *= D1, x1 *= D2) {
			string str = "������� �������� a";
			str += to_string(i);
			input_d(a0, str);
			sum += ((a0 / (i + 1)) * x);
			sum1 += ((a0 / (i + 1)) * x1);
		}
		cout << "�����: " << sum1 - sum;
	}
}
void graph(char ch, double a, double b, double c, double d) {

}
void root_f(char ch, double a, double b, double c, double d) {

}
void extremum(char ch, double a, double b, double c, double d) {

}
