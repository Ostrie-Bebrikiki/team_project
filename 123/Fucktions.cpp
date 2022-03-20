#include "Functions.h"

void menu_Func() {
	char s, ch;
	
	while (true) {
		while (true) {
			system("cls");
			cout << "Выберите действие" << endl << "1 - Вычисление определенного интеграла" << endl << "2 - Построение графика функции"
				<< endl << "3 - Поиск корня при Y = 0 на отрезке" << endl << "4 - Поиск экстремумов на отрезке" 
				<< endl << "0 - Выход в главное меню" << endl << '>';
			s = _getche();
			if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4') break;
			system("cls");
		}
		if (s == '0') return;
		cout << endl;
		choose(ch);
		cout << endl;
		if (ch == '0') continue;
		double a = 0, b = 0, c = 0, d = 0;
		if (ch != '1') {
			input_d(a, "Введите a"); input_d(b, "Введите b"); input_d(c, "Введите c");
		}
		if (ch == '3' || ch == '5' || ch == '6') {
			input_d(d, "Введите d");
		}
		switch (s) {
		case '1': integral(ch,a,b,c,d); break;
		case '2': graph(ch, a, b, c, d); break;
		case '3': root_f(ch, a, b, c, d); break;
		case '4': extremum(ch, a, b, c, d); break;
		default: break;
		}
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}

void integral(char ch, double a, double b, double c, double d) {
	double D1, D2, eps;
	while (true) {
		input_d(D1, "Введите левую границу");
		input_d(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else if(ch == '2' && D1 < 0 && double((int)b) != b) cout << "Нельзя найти интеграл при основании меньше нуля и нецелой степенью\nДля выхода введите 0 0\n";
		else if(ch == '3' && b < 0 && (double((int)c*D1) != c*D1 || double((int)c * D2) != c * D2)) cout << "Нельзя найти интеграл при основании меньше нуля и нецелой степенью\nДля выхода введите 0 0\n";
		else if(ch == '4' && D1 <= 0) cout << "Нельзя найти интеграл при границе меньше либо равной нулю\nДля выхода введите 0 0\n";
		else break;
	}
	if (ch != '1') {
		while (true) {
			input_d(eps, "Введите погрешность");
			if (eps > 1 || eps <= 0) cout << "Погрешность не может быть меньше или равна нулю и не может быть больше 1" << endl;
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
		}
		cout << "Ответ: " << I1;
	}
	else {
		int N;
		double x = D1, x1 = D2;
		while (true) {
			input(N, "Введите степень N");
			if (N < 0) cout << "N >=0" << endl;
			else break;
		}
		N += 1;
		double sum = 0,sum1 = 0, a0;
		for (int i = 0; i < N; i++, x *= D1, x1 *= D2) {
			string str = "Введите значение a";
			str += to_string(i);
			input_d(a0, str);
			sum += ((a0 / (i + 1)) * x);
			sum1 += ((a0 / (i + 1)) * x1);
		}
		cout << "Ответ: " << sum1 - sum;
	}
}
void graph(char ch, double a, double b, double c, double d) {
	const int WIDTH = 800, HEIGHT = 600;
	const int width = 49 * WIDTH / 50, height = 49 * HEIGHT / 50;
	int i1, i2;
	SDL_Event e;
	bool quit = 0;
	int D1, D2;
	while (true) {
		input(D1, "Введите левую границу");
		input(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else break;
	}
	int h = width / (abs(D1) > abs(D2)? abs(2 * D1): abs(2 * D2));

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Леееееее",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawLine(renderer, WIDTH / 2, HEIGHT / 100, WIDTH / 2, 99 * HEIGHT / 100);
	for (i1 = WIDTH / 2 + h; i1 <= 99 * WIDTH / 100; i1 += h) {
		
		SDL_RenderDrawLine(renderer, i1, HEIGHT / 2 - HEIGHT / 100, i1, HEIGHT / 2 + HEIGHT / 100);
	}
	for (i2 = WIDTH / 2 - h; i2 >= WIDTH / 100; i2 -= h) {
		
		SDL_RenderDrawLine(renderer, i2, HEIGHT / 2 - HEIGHT / 100, i2, HEIGHT / 2 + HEIGHT / 100);
	}
	i2 += h, i1 -= h;
	SDL_RenderDrawLine(renderer, i2, HEIGHT / 2, i1, HEIGHT / 2);
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(200);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void root_f(char ch, double a, double b, double c, double d) {

}
void extremum(char ch, double a, double b, double c, double d) {

}
