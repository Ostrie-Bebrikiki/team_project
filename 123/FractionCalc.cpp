// Ответственный - Скатенок Илья
#include "bebra.h"
#include "FractionCalcHeader.h"

void MenuFraction()
{
    setlocale(LC_ALL, "Russian");
    char menu;
    do
    {
        string fractionLeft;
        string fractionRight;
        do
        {
            system("cls");
            cout << "1 - Сложение двух дробей" << endl;
            cout << "2 - Вычитание двух дробей" << endl;
            cout << "3 - Умножение двух дробей" << endl;
            cout << "4 - Деление двух дробей" << endl;
            cout << "5 - Сравнение двух дробей" << endl;
            cout << "6 - Сокращение дроби" << endl;
            cout << "7 - Представить дробь в десятичном виде" << endl;
            cout << "8 - Выход в главное меню" << endl;
            menu = _getche();
        } while (menu < '1' || menu > '8');
        double Nums[4] = { 1,1,1,1 };

        double numerator;
        double denumerator;
        int nums_array = 0;
        switch (menu)
        {
        case '1':
        {
            EnterFractionStart(fractionLeft, fractionRight, nums_array, Nums);
            numerator = Nums[0] * Nums[3] + Nums[2] * Nums[1];
            denumerator = Nums[1] * Nums[3];
            ShowFractions(Nums, numerator, denumerator, menu);
        }
        break;
        case '2':
        {
            EnterFractionStart(fractionLeft, fractionRight, nums_array, Nums);
            numerator = Nums[0] * Nums[3] - Nums[2] * Nums[1];
            denumerator = Nums[1] * Nums[3];
            ShowFractions(Nums, numerator, denumerator, menu);
        }
        break;
        case '3':
        {
            EnterFractionStart(fractionLeft, fractionRight, nums_array, Nums);
            numerator = Nums[0] * Nums[2];
            denumerator = Nums[1] * Nums[3];
            ShowFractions(Nums, numerator, denumerator, menu);
        }
        break;
        case '4':
        {
            EnterFractionStart(fractionLeft, fractionRight, nums_array, Nums);
            numerator = Nums[0] * Nums[3];
            denumerator = Nums[1] * Nums[2];
            ShowFractions(Nums, numerator, denumerator, menu);
        }
        break;
        case '5':
        {
            EnterFractionStart(fractionLeft, fractionRight, nums_array, Nums);
            cout << Nums[0] << "/" << Nums[1] << "  " << Nums[2] << "/" << Nums[3] << endl;;
            Sravn(Nums[0], Nums[1], Nums[2], Nums[3]);
            system("pause");
        }
        break;
        case '6':
        {
            system("cls");
            cout << "Введите дробь" << endl;
            EnterFraction(fractionLeft, Nums, &nums_array);
            cout << Nums[0] << "/" << Nums[1] << endl;
            cout << "Результат: "; Sokr(Nums[0], Nums[1]);
            cout << endl;
            system("pause");
        }
        break;
        case '7':
        {
            system("cls");
            cout << "Введите дробь" << endl;
            EnterFraction(fractionLeft, Nums, &nums_array);
            cout << Nums[0] << "/" << Nums[1] << endl;
            cout << "Результат: " << Nums[0] / Nums[1] << endl;
            cout << endl;
            system("pause");
        }
        break;
        }
    } while (menu != '8');
}


int IsNullFraction(double numerator, double denumerator)
{
    int flag = 0;
    if (numerator == 0 && denumerator != 0)
    {
        cout << "Результат: 0" << endl;
        flag = 1;
    }
    if (denumerator == 0)
    {
        cout << "Результат: деление на ноль" << endl;
        flag = 1;
    }
    return flag;
}

int CheckError(string fraction)
{
    int error = 0;
    int CountSlash = 0;
    int CountPoint = 0;
    for (int i = 0; i < fraction.length(); i++)
    {
        if (isspace(fraction[i]) || isalpha(fraction[i]) || (ispunct(fraction[i]) && fraction[i] != '/' && fraction[i] != ','))
        {
            error = 1;
            break;
        }
        if (fraction[i] == '/')
        {
            CountSlash++;
        }
    }
    if (CountSlash != 1)
    {
        error = 1;
    }
    int j = 0;
    while (j < fraction.length())
    {
        if (fraction[j] == ',')
        {
            CountPoint++;
        }
        if ((j == fraction.length()) || (ispunct(fraction[j]) && fraction[j] != ','))
        {
            if (CountPoint > 1)
            {
                error = 1;
                break;
            }
            CountPoint = 0;
        }
        if (fraction[0] == '/' || fraction[fraction.length()] == '/')
        {
            error = 1;
        }
        j++;
    }
    if (error == 1)
    {
        cout << "Совершена ошибка при вводе формулы. Повторите ввод." << endl;
    }
    return error;
}


void EnterFractionStart(string fractionLeft, string fractionRight, int& nums_array, double* Nums)
{
    system("cls");
    cout << "Введите первую дробь: ";
    EnterFraction(fractionLeft, Nums, &nums_array);
    cout << "Введите вторую дробь: ";
    EnterFraction(fractionRight, Nums, &nums_array);
}

void EnterFraction(string fraction, double* Nums, int* nums_array)
{
    int ERRORnull;
    do
    {
        ERRORnull = 0;
        do
        {
            getline(cin, fraction);
            system("cls");
        } while (CheckError(fraction));
        for (int i = 0; i < fraction.length(); i++)
        {

            int tmpi = i;
            while (fraction[i] != '/' && i != fraction.length())
            {
                i++;
            }
            if (tmpi != i && *nums_array < 4)
            {
                Nums[*nums_array] = stod(fraction.substr(tmpi, i--));
                (*nums_array)++;
            }
        }
        if (Nums[1] == 0 || Nums[3] == 0)
        {
            ERRORnull++;
            cout << "Программа не может работать с дробями, у которых в знаменателе ноль." << endl << "Повторите Ввод" << endl;
            (*nums_array)--;
            (*nums_array)--;
        }
    } while (ERRORnull != 0);
}

void ShowFractions(double* Nums, double numerator, double denumerator, char operation)
{
    switch (operation)
    {
    case '1':
        operation = '+';
        break;
    case '2':
        operation = '-';
        break;
    case '3':
        operation = '*';
        break;
    case '4':
        operation = '/';
        break;
    }
    cout << Nums[0] << "/" << Nums[1] << " " << operation << " " << Nums[2] << "/" << Nums[3] << endl;
    if (!(IsNullFraction(numerator, denumerator)))
    {
        cout << "Результат: " << numerator << "/" << denumerator << endl;
        cout << "Запись в десятичном виде: " << numerator / denumerator << endl;
        cout << "Cокращенная дробь: "; Sokr(numerator, denumerator); cout << endl;
    }
    system("pause");
}

int FindMaxDeviver(int a, int b)
{
    int MOD = 1;

    a = abs(a);
    b = abs(b);

    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        MOD = a;
        a = b;
        b = MOD;
    }

    if (b == 0)
    {
        return a;
    }

    while (MOD)
    {
        MOD = a % b;
        if (MOD)
        {
            a = b;
            b = MOD;
        }
    }

    return b;
}

void Sokr(double a, double b)
{
    int MOD = FindMaxDeviver(a, b);
    if (a / MOD == a)
    {
        cout << "Сократить дробь нельзя" << endl;
    }
    else
    {
        cout << a / MOD;
        if (b / MOD != 1)
        {
            cout << "/" << b / MOD << endl;
        }
    }
}

void Sravn(double Chisl, double Znamen, double Chisl2, double Znamen2)
{
    double left = Chisl / Znamen;
    double right = Chisl2 / Znamen2;
    cout << left;
    if (left == right)
    {
        cout << "=";
    }
    else if (left > right)
    {
        cout << ">";
    }
    else
    {
        cout << "<";
    }
    cout << right << endl;
}