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

void menu_ver() {
	char s;
	while (true) {
		while (true) {
			cout << "�������� ������" << endl << "1 - ����������� m/n" << endl << "2 - ��������� ��� ����������� ������������� �������"
				<< endl << "3 - ���. �������� ��� ����������� ������������� �������" << endl << '>';
			s = _getche();
			if (s == '1' || s == '2' || s == '3') break;
			system("cls");
		}
		cout << endl;

		switch (s) {
		case '1':ver();
		case '2':disp();
		case '3':MathAwait();
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
		else cout << "n ������ ���� ������ 0";
	}
}

void disp() {

}

void MathAwait() {

}