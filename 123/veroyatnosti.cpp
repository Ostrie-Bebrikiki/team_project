#include "header_ver.h"

void input_d(double& a, string str) {
	while (true) {
		std::cout << str<<": ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������ �����" << std::endl;
		}
		else {
			break;
		}
	}
}
void input(int& a, string str) {
	while (true) {
		std::cout << str << ": ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������ �����" << std::endl;
		}
		else {
			break;
		}
	}
}


void menu_ver() {
	char s;
	while (true) {
		while (true) {
			system("cls");
			cout << "�������� ��������" << endl << "1 - ��������� ����������� m/n" << endl << "2 - ��������� ��������� ��� ����������� ������������� �������"
				<< endl << "3 - ��������� ���. �������� ��� ����������� ������������� �������" << endl <<"4 - ����� � ������� ����" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver(); break;
		case '2':disp(); break;
		case '3':MathAwait(); break;
		case '4': return;
		default: break;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
}

void ver() {
	double m, n;
	input_d(m, "������� m");
	while (true) {
		input_d(n, "������� n");
		if (n > 0) break;
		else cout << "n ������ ���� ������ 0\n";
	}
	cout << "�����: " << m / n;
}

void disp() {
	int x;
	while (true) {
		input(x, "������� ���-�� �������");
		if (x <= 0) cout << "���-�� ������ ���� ������ ����" << endl;
		else break;
	}
	x *= 2;
	double* xipi = (double*)malloc(x * sizeof(double));
	while (true) {
		double sum = 0;
		for (int i = 0; i < x; i++) {
			string str = "������� ";
			str += (i % 2 == 0 ? "�������� " : "��� ");
			str += "� ";
			str += to_string((i + 2) / 2);
			input_d(xipi[i], str);
			sum += i % 2 != 0 ? xipi[i] : 0;
		}
		if (sum != 1) cout << "��������� ����������� ������ ��������� 1" << endl;
		else break;
	}
	double x2p = 0, xp = 0;
	for (int i = 0; i < x; i+=2) {
		x2p += xipi[i] * xipi[i] * xipi[i + 1];
		xp += xipi[i] * xipi[i + 1];
	}
	free(xipi);
	xp *= xp;
	cout << "�����: " << x2p - xp;
}

void MathAwait() {
	int x;
	while (true) {
		input(x, "������� ���-�� �������");
		if (x <= 0) cout << "���-�� ������ ���� ������ ����" << endl;
		else break;
	}
	x *= 2;
	double* xipi = (double*)malloc(x * sizeof(double));
	while (true) {
		double sum = 0;
		for (int i = 0; i < x; i++) {
			string str = "������� ";
			str += (i % 2 == 0 ? "�������� " : "��� ");
			str += "� ";
			str += to_string((i + 2) / 2);
			input_d(xipi[i], str);
			sum += i % 2 != 0 ? xipi[i] : 0;
		}
		if (sum > 1) cout << "��������� ����������� ������ ��������� 1"<<endl;
		else break;
	}
	double xp = 0;
	for (int i = 0; i < x; i += 2) {
		xp += xipi[i] * xipi[i + 1];
	}
	free(xipi);
	cout << "�����: " << xp;
}