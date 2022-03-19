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
			system("cls");
			cout << "����������� ������ ����������� � ���. ����������" << endl<<endl;
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
	while (true) {
		input_d(m, "������� m");
		while (true) {
			input_d(n, "������� n");
			if (n > 0) break;
			else cout << "n ������ ���� ������ 0\n";
		}
		if (m > n) cout << "m ������ ���� ������ n\n";
		else break;
	}
	cout << "�����: " << m / n;
}

void disp() {

}

void MathAwait() {

}