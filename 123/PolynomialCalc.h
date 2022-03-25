#pragma once
#ifndef PolynomialCalc
#define PolynomialCalc

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

bool PolynomInput(Polynomial &slag); //���� ����������
void PolynomOutput(Polynomial& slag); //����� ����������


//bool funcExit(); //����� �� �������

#endif PolynomialCalc