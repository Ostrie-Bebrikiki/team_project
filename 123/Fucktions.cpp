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
		while (true) {
			if (ch != '1') {
				while (true) {
					input_d(a, "Введите a"); input_d(b, "Введите b"); input_d(c, "Введите c");
					if (ch == '3' && b < 0) cout << "Невозможно построить данный график\n";
					else break;
				}
			}
			else break;
			if (ch == '3' || ch == '5' || ch == '6') {
				input_d(d, "Введите d");
			}
			if (ch == '4' && b <= 0)cout << "Невозможно найти логарифм от числа меньшего или равного нулю"<<endl;
			else break;
		}	
		switch (s) {
		case '1': integral(ch,a,b,c,d); break;
		case '2': graph(ch, a, b, c, d); break;
		case '3': root_f(ch, a, b, c, d); break;
		case '4': extremum(ch, a, b, c, d); break;
		default: break;
		}
		cout << endl << "Продолжить?\nДля выхода введите n: ";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}

void integral(char& ch, double& a, double& b, double& c, double& d) {
	double D1, D2;
	while (true) {
		input_d(D1, "Введите нижний предел интегрирования");
		input_d(D2, "Введите верхний предел интегрирования");
		if (ch == '3' && b == 0 && c == 0) {
			cout << "Нельзя найти интеграл, т.к. 0^0 = неопределённость\n";
			return;
		}
		else if (ch == '4' && (D1 < 0 || D2 < 0)) {
			cout << "Нельзя найти интеграл, т.к. функция существует на (0;+oo)\n";
			return;
	}
		else break;
	}
	if (ch != '1') {
		if(ch=='2') cout << "Ответ: " << f1(ch, (D2 < 0 ? -D2 : D2), (D2 < 0 ? -a : a),b,c,d) - f1(ch,(D1 <0? -D1:D1),(D1 < 0 ? -a : a),b,c,d);
		else if(ch=='3') cout << "Ответ: " << f1(ch, D2, b<0?-a:a, b<0?-b:b, c, d) - f1(ch, D1, b<0?-a:a, b<0?-b:b, c, d);
		else cout << "Ответ: " << f1(ch, D2, a, b, c, d) - f1(ch, D1, a, b, c, d);
		
	}
	else {
		int N;
		double x = D1, x1 = D2;
		while (true) {
			input(N, "Введите степень N");
			if (N < 0) cout << "Степень полинома не может быть меньше нуля" << endl;
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

void graph(char& ch, double& a, double& b, double& c, double& d) {
	const int WIDTH = 1500, HEIGHT = 800;
	const int width = 49 * WIDTH / 50, height = 49 * HEIGHT / 50;
	int colourR = 192, colourG = 0, colourB = 64;
	int j = 0, N;
	double D1, D2;
	double* A = nullptr;
	SDL_Event e;
	bool quit = false;
	double i1, i2, i3, i4;
	if (ch == '1') {
		while (true) {
			input(N, "Введите степень N");
			if (N < 0) cout << "Степень полинома не может быть меньше нуля" << endl;
			else break;
		}
		N++;
		A = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++) {
			string str = "Введите значение a";
			str += to_string(i);
			input_d(A[i], str);
		}
	}
	while (true) {
		input_d(D1, "Введите левую границу");
		input_d(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else if ((abs(D1) > abs(D2) ? 2 * abs(D1) : 2 * abs(D2))> WIDTH/2.0f) cout << "Слишком большой дипазон" << endl;
		else if (ch == '4' && D1 < 0) cout << "Данная функция существует на (0;+оо)" << endl;
		else if (ch == '3' && b < 0 && double((int)c) != c) {
			cout << "Невозможно построить график функции с возведением отрицательного числа в нечетную степень\n";
			return;
		}
		else if (ch == '2' && D1 < 0 && double((int)b) != b) cout << "Данная функция существует на [0;+оо)\n";
		else break;
	}
	double h = abs(D1) > abs(D2) ? 2 * abs(D1) : 2 * abs(D2), hy;
	h = width / h;
	hy = height / 200.0f;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Лучший график в мире",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	unsigned long int scaly = 1, scalx = 1;
	while (h < 5) {
		h *= 10;
		scalx *= 10;
	}
	for (i1 = WIDTH / 2 + h; (float)i1 <= 99.1* WIDTH / 100.0f; i1 += h) {
		SDL_RenderDrawLine(renderer, i1, HEIGHT / 2 - HEIGHT /200, i1, HEIGHT / 2 + HEIGHT / 200);
		j+=scalx;
	}
	i1 -= h;
	DrawBigNum(renderer, j, i1 -3*HEIGHT/100, HEIGHT / 2 + HEIGHT / 30, HEIGHT / 50);
	for (i2 = WIDTH / 2 - h; (float)i2 >= 0.9*WIDTH / 100.0f; i2 -= h) {
		SDL_RenderDrawLine(renderer, i2, HEIGHT / 2 - HEIGHT / 200, i2, HEIGHT / 2 + HEIGHT / 200);
	}
	i2 += h;
	DrawBigNum(renderer, -j, i2, HEIGHT / 2 + HEIGHT / 30, HEIGHT / 50);
	j = 0;
	
	while (hy < 5) {
		hy *= 10;
		scaly *= 10;
	}
	for (i3 = HEIGHT / 2 + hy; (float)i3 <= 99.1*HEIGHT /100.0f; i3 += hy) {
		SDL_RenderDrawLine(renderer, WIDTH / 2 - HEIGHT / 200, i3, WIDTH / 2 + HEIGHT / 200, i3);
		j += scaly;
	}
	i3 -= hy;
	DrawBigNum(renderer, -j, WIDTH / 2 + WIDTH / 100, i3 - HEIGHT / 50, HEIGHT / 50);
	for (i4 = HEIGHT / 2 - hy; (float)i4 >= 0.9*HEIGHT / 100.0f; i4 -= hy) {
		SDL_RenderDrawLine(renderer, WIDTH / 2 - HEIGHT / 200, i4, WIDTH / 2 + HEIGHT / 200, i4);
	}
	i4 += hy;
	DrawBigNum(renderer, j, WIDTH / 2 + WIDTH / 100, i4 - HEIGHT / 400, HEIGHT / 50);
	
	SDL_RenderDrawLine(renderer, i2, HEIGHT / 2, i1, HEIGHT / 2);
	SDL_RenderDrawLine(renderer, WIDTH / 2, i3, WIDTH / 2, i4);
	SDL_SetRenderDrawColor(renderer, colourR, colourG, colourB, 0);
	h = h / scalx;
	hy = hy / scaly;
	double l = D1;
	for (int z = D1 + 1; z <= D2; z++) {
		double i = z;
		if (ch == '1') {
			if ((isinf(PoliF(i, A, N)) || isnan(PoliF(i, A, N))) && l < 0) i -= 0.0001;
			else if ((isinf(PoliF(i, A, N)) || isnan(PoliF(i, A, N))) && i > 0) l += 0.0001;
			if (PoliF(l, A, N) == 0) {
				DrawBigNum(renderer, l, (WIDTH / 2) + (l * h) - (l * h < 0 ? 4 * HEIGHT / 200 : 0), HEIGHT / 2 + 4 * HEIGHT / 200, HEIGHT / 50);
				SDL_RenderDrawLine(renderer, (WIDTH / 2) + (l * h), HEIGHT / 2 - HEIGHT / 100, (WIDTH / 2) + (l * h), HEIGHT / 2 + HEIGHT / 100);
			}
			if (PoliF(l, A, N) * PoliF(i, A, N) < 0) {
				DrawBigNum(renderer, PoliDih(false, l, i, A, N), (WIDTH / 2) + (PoliDih(false, l, i, A, N) * h) - (PoliDih(false, l, i, A, N) * h < 0 ? 4 * HEIGHT / 200 : 0), HEIGHT / 2 + 4 * HEIGHT / 200, HEIGHT / 50);
				SDL_RenderDrawLine(renderer, (WIDTH / 2) + (PoliDih(false, l, i, A, N) * h), HEIGHT / 2 - HEIGHT / 100, (WIDTH / 2) + (PoliDih(false, l, i, A, N) * h), HEIGHT / 2 + HEIGHT / 100);
			}
		}
		else {
			if ((isinf(f(ch, i, a, b, c, d)) || isnan(f(ch, i, a, b, c, d))) && l < 0) i -= 0.0001;
			else if ((isinf(f(ch, l, a, b, c, d)) || isnan(f(ch, l, a, b, c, d))) && i > 0) l += 0.0001;
			if (f(ch, l, a, b, c, d) == 0) {
				DrawBigNum(renderer, l, (WIDTH / 2) + (l * h) - (l * h < 0 ? 4 * HEIGHT / 200 : 0), HEIGHT / 2 + 4 * HEIGHT / 200, HEIGHT / 50);
				SDL_RenderDrawLine(renderer, (WIDTH / 2) + (l * h), HEIGHT / 2 - HEIGHT / 100, (WIDTH / 2) + (l * h), HEIGHT / 2 + HEIGHT / 100);
			}
			if (f(ch, l, a, b, c, d) * f(ch, i, a, b, c, d) < 0) {
				DrawBigNum(renderer, dih(false, ch, l, i, a, b, c, d), (WIDTH / 2) + (dih(false, ch, l, i, a, b, c, d) * h) - (dih(false, ch, l, i, a, b, c, d) < 0 ? 4 * HEIGHT / 200 : 0), HEIGHT / 2 + 4 * HEIGHT / 200, HEIGHT / 50);
				SDL_RenderDrawLine(renderer, (WIDTH / 2) + (dih(false, ch, l, i, a, b, c, d) * h), HEIGHT / 2 - HEIGHT / 100, (WIDTH / 2) + (dih(false, ch, l, i, a, b, c, d) * h), HEIGHT / 2 + HEIGHT / 100);
			}
		}
		l = z;
	}
	if ((ch != '1' && f(ch, D2, a, b, c, d) == 0) || (ch == '1' && PoliF(D2, A, N) == 0)) DrawBigNum(renderer, D2, (WIDTH / 2) + (D2 * h) - (D2 < 0 ? 4 * HEIGHT / 200 : 0), HEIGHT /2 +  4 * HEIGHT / 200, HEIGHT / 100);
	cout << "Цена деления по x = " << scalx << endl << "Цена деления по y = " << scaly << endl;
	if (ch != '1') {
		double y1 = HEIGHT / 2 - f(ch, D1, a, b, c, d) * hy, x1 = (WIDTH / 2) + (D1 * h), y, x;
		if (y1 >= HEIGHT) y1 = HEIGHT + 1;
		else if (y1 <= 0) y1 = -1;
		for (double i = D1; i <= D2; i += 1.0f / h) {
			x = (WIDTH / 2) + (i * h);
			y = HEIGHT / 2 - f(ch, i, a, b, c, d) * hy;
			if (y >= HEIGHT && y1 <= 0) y1 = HEIGHT + 1;
			else if (y <= 0 && y1 >= HEIGHT) y1 = -1;
			if (y >= HEIGHT) y = HEIGHT + 1;
			else if (y <= 0) y = -1;
			SDL_RenderDrawLine(renderer, x1, y1, x, y);
			x1 = x, y1 = y;		
		}
		SDL_RenderPresent(renderer);
	}
	else {
		double y1 = HEIGHT / 2 - PoliF(D1,A,N) * hy, x1 = (WIDTH / 2) + (D1 * h), y, x;
		if (y1 >= HEIGHT) y1 = HEIGHT + 1;
		else if (y1 <= 0) y1 = -1;
		for (double i = D1; i <= D2; i += 1.0f / h) {
			x = (WIDTH / 2) + (i * h);
			y = HEIGHT / 2 - PoliF(i, A, N) * hy;
			if (y >= HEIGHT && y1 <= 0) y1 = HEIGHT + 1;
			else if (y <= 0 && y1 >= HEIGHT) y1 = -1;
			if (y >= HEIGHT) y = HEIGHT + 1;
			else if (y <= 0) y = -1;
			SDL_RenderDrawLine(renderer, x1, y1, x, y);
			x1 = x, y1 = y;
		}
		SDL_RenderPresent(renderer);
	}



	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0);
	SDL_RenderDrawLine(renderer, 0, 0, WIDTH, 0);
	SDL_RenderDrawLine(renderer, 0, HEIGHT, WIDTH, HEIGHT);

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
void root_f(char& ch, double& a, double& b, double& c, double& d) {
	double D1,D2;
	int N;
	double* A = nullptr;
	if (ch == '1') {
		while (true) {
			input(N, "Введите степень N");
			if (N < 0) cout << "Степень полинома не может быть меньше нуля" << endl;
			else break;
		}
		N++;
		A = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++) {
			string str = "Введите значение a";
			str += to_string(i);
			input_d(A[i], str);
		}
	}
	while (true) {
		input_d(D1, "Введите левую границу");
		input_d(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else if (ch == '3' && b < 0 && double((int)c) != c) {
			cout << "Невозможно вычислить корень функции с возведением отрицательного числа в нечетную степень\n";
			return;
		}
		else break;
	}
	double l = D1;
	int u = 0;
	for (int z = D1 + 1; z <= D2; z++) {
		double i = z;
		if (ch == '1') {
			if ((isinf(PoliF(i,A,N)) || isnan(PoliF(i, A, N))) && l < 0) i -= 0.0001;
			else if ((isinf(PoliF(i, A, N)) || isnan(PoliF(i, A, N))) && i > 0) l += 0.0001;
			if (PoliF(l, A, N) == 0) cout << "Корень №" << ++u << " = " << l << endl;
			if (PoliF(l, A, N) * PoliF(i, A, N) < 0) cout << "Корень №"<<++u<<" = " << PoliDih(false, l, i, A, N) << endl;
		}
		else {
			if ((isinf(f(ch, i, a, b, c, d)) || isnan(f(ch, i, a, b, c, d))) && l < 0) i -= 0.0001;
			else if ((isinf(f(ch, l, a, b, c, d)) || isnan(f(ch, l, a, b, c, d))) && i > 0) l += 0.0001;
			if (f(ch, l, a, b, c, d) == 0) cout << "Корень №" << ++u << " = " << l << endl;
			if (f(ch, l, a, b, c, d) * f(ch, i, a, b, c, d) < 0) cout << "Корень №" <<++u << " = " <<dih(false, ch, l, i, a, b, c, d) << endl;
		}
		l = z;
	}
	if ((ch != '1' && f(ch, D2, a, b, c, d) == 0) || (ch == '1' && PoliF(D2, A, N) == 0)) cout << "Корень №" << ++u << " = " << D2 << endl;
	if (!u) cout << "На данном отрезке нет корней\n";

}
void extremum(char &ch, double &a, double &b, double &c, double &d) {
	double D1, D2;
	int N;
	double* A = nullptr;
	if (ch == '1') {
		while (true) {
			input(N, "Введите степень N");
			if (N < 0) cout << "Степень полинома не может быть меньше нуля" << endl;
			else break;
		}
		N++;
		A = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++) {
			string str = "Введите значение a";
			str += to_string(i);
			input_d(A[i], str);
		}
	}
	while (true) {
		input_d(D1, "Введите левую границу");
		input_d(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else break;
	}
	if (ch == '3' && b < 0 && double((int)c) != c) {
		cout << "Невозможно вычислить экстремум функции с возведением отрицательного числа в нечетную степень\n";
		return;
	}
	double l = D1;
	int u = 0;
	for (int z = D1 + 1; z <= D2; z++) {
		double i = z;
		if (ch == '1') {
			if ((isinf(PoliF1(i, A, N)) || isnan(PoliF1(i, A, N))) && l < 0) i -= 0.0001;
			else if ((isinf(PoliF1(i, A, N)) || isnan(PoliF1(i, A, N))) && i > 0) l += 0.0001;
			if (PoliF1(l,A,N) == 0) cout << "Экстремум №" << ++u << " = " << l << endl;
			if (PoliF1(l, A, N) * PoliF1(i, A, N) < 0) cout << "Экстремум №" << ++u << " = " << PoliDih(true, l, i, A, N) << endl;
		}
		else {
			if ((isinf(f2(ch, i, a, b, c, d)) || isnan(f2(ch, i, a, b, c, d))) && l < 0) i -= 0.0001;
			else if ((isinf(f2(ch, l, a, b, c, d)) || isnan(f2(ch, l, a, b, c, d))) && i > 0) l += 0.0001;
			if(f2(ch, l, a, b, c, d) == 0) cout << "Экстремум №" << ++u << " = " << l << endl;
			if (f2(ch, l, a, b, c, d) * f2(ch, i, a, b, c, d) < 0) cout << "Экстремум №" << ++u << " = " << dih(true, ch, l, i, a, b, c, d) << endl;
		}
		l = z;
	}
	if ((ch != '1' && f2(ch, D2, a, b, c, d) == 0) || (ch == '1' && PoliF1(D2, A, N) == 0)) cout << "Экстремум №" << ++u << " = " << D2 << endl;
	if (!u) cout << "На данном отрезке нет экстремумов\n";
}
