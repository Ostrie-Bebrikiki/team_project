#include "header_ver.h"

void menu_ver() {
	char s;
	while (true) {
		while (true) {
			system("cls");
			cout << "�������� ��������" << endl << "1 - ��������� ����������� m/n" << endl << "2 - ��������� ��������� ��� ����������� ������������� �������"
				<< endl << "3 - ��������� ���. �������� ��� ����������� ������������� �������" << endl <<"0 - ����� � ������� ����" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3' || s == '0') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver(); break;
		case '2':disp(); break;
		case '3':MathAwait(); break;
		case '0': return;
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
	while (true) {
		input_d1(m, "������� m");
		while (true) {
			input_d1(n, "������� n");
			if (n > 0) break;
			else cout << "n ������ ���� ������ 0\n";
		}
		if (m > n)cout << "m �� ����� ���� ������ n\n";
		else break;
	}
	cout << "�����: " << m / n;
}

void disp() {
	int x;
	while (true) {
		input1(x, "������� ���-�� �������");
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
			input_d1(xipi[i], str);
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
		input1(x, "������� ���-�� �������");
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
			input_d1(xipi[i], str);
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

