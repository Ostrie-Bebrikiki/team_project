#pragma once

//������������ ���� ��� ������������ �����������
//������������� - ����������

struct Polynomial { //��������� ��� ����������
	double c[50] = { 0 }; //������ ��� �������� �������� ����������
	int n; //������������ ������� ����������
};

void PolynomialMenu(); //����
void PolynomialSum(); //��������
void PolynomialSubstraction(); //���������
void PolynomialMulti(); //���������
void PolynomialMultiNumber(); //��������� �� �����
void PolynomialDerivative(); //�����������
void PolynomialDivision(); //�������	

void PolynomInput(Polynomial &slag); //���� ����������
void PolynomOutput(Polynomial& slag); //����� ����������

void funcExit(); //����� �� �������