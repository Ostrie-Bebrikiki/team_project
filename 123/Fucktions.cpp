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
				if (ch == '3' && b < 0) cout << "Невозможно построить данный график";
				else break;
				}
			}
			else while (true) {
					input_d(a, "Введите степень N");
					if (double((int)a) != a) cout << "Степень полинома не может быть нецелой" << endl;
					else if (a < 0) cout << "Степень полинома не может быть меньше нуля" << endl;
					else break;
				}
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
		cout << endl << "Продолжить?";
		s = tolower(_getche());
		if (s == 'n' || s == 'т') break;
		system("cls");
	}
}

void integral(char ch, double a, double b, double c, double d) {
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
			if (N < 0) cout << "Степень полинома не иожет быть меньше нуля" << endl;
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
	const int WIDTH = 1500, HEIGHT = 800;
	const int width = 49 * WIDTH / 50, height = 49 * HEIGHT / 50;
	int colourR = 192, colourG = 0, colourB =64;
	int i1, i2, i3, i4,j=0;
	SDL_Event e;
	bool quit = 0;
	int D1, D2,chert = 10;
	double h = 0, hy;
	if (ch == '1')double* A = (double*)malloc(a * sizeof(double));
	for (int i = 0; i < a; i++) {

	}
	while (true) {
		input(D1, "Введите левую границу");
		input(D2, "Введите правую границу");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if (D2 < D1) cout << "Левая граница не может быть больше правой" << endl;
		else if (D2 > 1000 || D1 > 1000) cout << "Слишком большой дипазон" << endl;
		else if (ch == '4' && D1 < 0) cout << "Данная функция существует на (0;+оо)" << endl;
		else if (ch == '3' && b < 0 && double((int)c) != c) {
			cout << "Невозможно построить график функции с возведением отрицательного числа в нечетную степень\n"; 
			return;
		}
		else if (ch == '2' && D1 < 0 && double((int)b) != b) cout << "Данная функция существует на [0;+оо)\n";
		else break;
	}
	if (ch == '3' && b < 0 && double((int)c) != c && D1 < 0)D1 = 0;
	h = (abs(D1) > abs(D2) ? abs(2 * D1) : abs(2 * D2));
	h = double((int)(width / h));
	double fy1 = f(ch, D1, a, b, c, d), fy2 = f(ch, D2, a, b, c, d);
	fy1 = fy1 < 0 ? -fy1 : fy1;
	fy2 = fy2 < 0 ? -fy2 : fy2;
	if(ch=='2'){
		hy = fy1 > fy2 ? 2 * fy1 : 2 * fy2;
		hy = abs(c) > hy ? c : hy;
		if (b < 0) {
			hy = 2000;
		}
	}else hy = fy1 > fy2 ? 2*fy1 : 2*fy2;
	if (isinf(hy))hy = 2000;
	if (ch == '4' && hy == 2000)hy = 200;
	hy = (height / hy);
	if (hy <= 0)hy=1;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Леееееее",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for (i1 = WIDTH / 2 + h; i1 <= 99 * WIDTH / 100; i1 += h) {
		SDL_RenderDrawLine(renderer, i1 , HEIGHT / 2 - HEIGHT / 100, i1, HEIGHT / 2 + HEIGHT / 100);
		j++;
	}
	i1 -= h;
	DrawBigNum(renderer, j, i1 +1, HEIGHT / 2 - HEIGHT / 40, HEIGHT / 100);
	for (i2 = WIDTH / 2 - h; i2 >= WIDTH / 100; i2 -= h) {
		SDL_RenderDrawLine(renderer, i2, HEIGHT / 2 - HEIGHT / 100, i2, HEIGHT / 2 + HEIGHT / 100);
	}
	i2 += h;
	DrawBigNum(renderer, -j, i2 - 1, HEIGHT / 2 - HEIGHT / 40, HEIGHT / 100);
	j = 0;
	if (hy <= 4) {
		for (i3 = HEIGHT / 2 + height / 20; i3 <= 99 * HEIGHT / 100; i3 += height/20) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i3, WIDTH / 2 + WIDTH / 400, i3);
		}
		for (i4 = HEIGHT / 2 - height / 20; i4 >= HEIGHT / 100; i4 -= height / 20) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i4, WIDTH / 2 + WIDTH / 400, i4);
		}
		i3 -= height / 20, i4 += height / 20;
		DrawBigNum(renderer, -1000, WIDTH / 2 + WIDTH / 100, i3 - HEIGHT / 50, HEIGHT / 50);
		DrawBigNum(renderer, 1000, WIDTH / 2 + WIDTH / 100, i4 -HEIGHT / 400, HEIGHT / 50);
	}
	else {
		for (i3 = HEIGHT / 2 + hy; i3 <= 99 * HEIGHT / 100; i3 += hy) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i3, WIDTH / 2 + WIDTH / 400, i3);
			j++;
		}
		i3 -= hy;
		DrawBigNum(renderer, -j, WIDTH / 2 + WIDTH / 100, i3 - HEIGHT / 50, HEIGHT / 50);
		for (i4 = HEIGHT / 2 - hy; i4 >= HEIGHT / 100; i4 -= hy) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i4, WIDTH / 2 + WIDTH / 400, i4);
		}
		i4 += hy;
		DrawBigNum(renderer, j, WIDTH / 2 + WIDTH / 100, i4 - HEIGHT / 400, HEIGHT / 50);
	}
	

	
	SDL_RenderDrawLine(renderer, i2, HEIGHT / 2, i1, HEIGHT / 2);
	SDL_RenderDrawLine(renderer, WIDTH/2, i3, WIDTH/2, i4);
	double y,y1 = HEIGHT / 2 - f(ch, D1, a, b, c, d) * hy,x1 = (WIDTH / 2) + (D1 * h);
	SDL_SetRenderDrawColor(renderer, colourR, colourG, colourB, 0);
	if (y1 < 0) y1 = 0;
	else if(y1 > HEIGHT)y1 = HEIGHT;
	if (ch != '1') {
		for (double i = D1; i <= D2; i += 1.0f / h) {
			int x = (WIDTH / 2) + (i * h);
			y = HEIGHT / 2 - f(ch, i, a, b, c, d) * hy;
			if (chert > 0)chert--;
			else if ((y1>HEIGHT/2 && y <HEIGHT/2)||(y1 <HEIGHT/2&&y>HEIGHT/2)) {
				SDL_RenderDrawLine(renderer, x, y + HEIGHT / 100, x, y - HEIGHT / 100);
				if(y > HEIGHT /2)
					DrawBigNum(renderer, i, x - WIDTH / 30, y - HEIGHT / 30, HEIGHT / 50);
				else
					DrawBigNum(renderer, i, x + WIDTH / 100, y - HEIGHT / 30, HEIGHT / 50);
				chert = WIDTH / 100;
			}
			if (y <= 0) y = 0;
			else if (y > HEIGHT)y = HEIGHT;
			if (y == 0 && y1 == HEIGHT) y1 = 0;
			if (y == HEIGHT && y1 == 0)y1 = HEIGHT;
			SDL_RenderDrawLine(renderer, x1, y1, x, y);
			x1 = x, y1 = y;
			SDL_RenderPresent(renderer);
		}
	}
	else {
		for (double i = D1; i <= D2; i += 1.0f / h) {
			int x = (WIDTH / 2) + (i * h);
			y = HEIGHT / 2 - f(ch, i, a, b, c, d) * hy;
			if (chert > 0)chert--;
			else if ((y1 >= HEIGHT / 2 && y <= HEIGHT / 2) || (y1 <= HEIGHT / 2 && y >= HEIGHT / 2)) {
				SDL_RenderDrawLine(renderer, x, y + HEIGHT / 100, x, y - HEIGHT / 100);
				if (y > HEIGHT / 2)
					DrawBigNum(renderer, i, x - WIDTH / 30, y - HEIGHT / 30, HEIGHT / 50);
				else
					DrawBigNum(renderer, i, x + WIDTH / 100, y - HEIGHT / 30, HEIGHT / 50);
				chert = WIDTH / 100;
			}
			if (y <= 0) y = 0;
			else if (y > HEIGHT)y = HEIGHT;
			if (y == 0 && y1 == HEIGHT) y1 = 0;
			if (y == HEIGHT && y1 == 0)y1 = HEIGHT;
			SDL_RenderDrawLine(renderer, x1, y1, x, y);
			x1 = x, y1 = y;

			SDL_RenderPresent(renderer);
		}
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
void root_f(char ch, double a, double b, double c, double d) {

}
void extremum(char ch, double a, double b, double c, double d) {
	
}
