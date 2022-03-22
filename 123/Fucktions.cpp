#include "Functions.h"

void menu_Func() {
	char s, ch;
	
	while (true) {
		while (true) {
			system("cls");
			cout << "�������� ��������" << endl << "1 - ���������� ������������� ���������" << endl << "2 - ���������� ������� �������"
				<< endl << "3 - ����� ����� ��� Y = 0 �� �������" << endl << "4 - ����� ����������� �� �������" 
				<< endl << "0 - ����� � ������� ����" << endl << '>';
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
				input_d(a, "������� a"); input_d(b, "������� b"); input_d(c, "������� c");
			}
			if (ch == '3' || ch == '5' || ch == '6') {
				input_d(d, "������� d");
			}
			if (ch == '4' && b <= 0)cout << "���������� ����� �������� �� ����� �������� ��� ������� ����"<<endl;
			else break;
		}	
		switch (s) {
		case '1': integral(ch,a,b,c,d); break;
		case '2': graph(ch, a, b, c, d); break;
		case '3': root_f(ch, a, b, c, d); break;
		case '4': extremum(ch, a, b, c, d); break;
		default: break;
		}
		cout << endl << "����������?";
		s = tolower(_getche());
		if (s == 'n' || s == '�') break;
		system("cls");
	}
}

void integral(char ch, double a, double b, double c, double d) {
	double D1, D2;
	while (true) {
		input_d(D1, "������� ������ ������ ��������������");
		input_d(D2, "������� ������� ������ ��������������");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if(ch == '3'&& b==0 && c == 0) cout << "������ ����� ��������, �.�. 0^0 ����������\n��� ������ ������� 0 0\n";
		else if(ch == '4' && (D1 < 0 || D2 <0)) cout << "������ ����� ��������, �.�. ������� ���������� �� (0;+oo)\n��� ������ ������� 0 0\n";
		else break;
	}
	if (ch != '1') {
		if(ch=='2') cout << "�����: " << f1(ch, (D2 < 0 ? -D2 : D2), (D2 < 0 ? -a : a),b,c,d) - f1(ch,(D1 <0? -D1:D1),(D1 < 0 ? -a : a),b,c,d);
		else if(ch=='3') cout << "�����: " << f1(ch, D2, b<0?-a:a, b<0?-b:b, c, d) - f1(ch, D1, b<0?-a:a, b<0?-b:b, c, d);
		else cout << "�����: " << f1(ch, D2, a, b, c, d) - f1(ch, D1, a, b, c, d);
		
	}
	else {
		int N;
		double x = D1, x1 = D2;
		while (true) {
			input(N, "������� ������� N");
			if (N < 0) cout << "N >=0" << endl;
			else break;
		}
		N += 1;
		double sum = 0,sum1 = 0, a0;
		for (int i = 0; i < N; i++, x *= D1, x1 *= D2) {
			string str = "������� �������� a";
			str += to_string(i);
			input_d(a0, str);
			sum += ((a0 / (i + 1)) * x);
			sum1 += ((a0 / (i + 1)) * x1);
		}
		cout << "�����: " << sum1 - sum;
	}
}
void graph(char ch, double a, double b, double c, double d) {
	const int WIDTH = 1500, HEIGHT = 1200;
	const int width = 49 * WIDTH / 50, height = 49 * HEIGHT / 50;
	int i1, i2, i3, i4;
	SDL_Event e;
	bool quit = 0;
	int D1, D2;
	double h = 0, hy;
	while (true) {
		input(D1, "������� ����� �������");
		input(D2, "������� ������ �������");
		if (D1 == 0.0f && D2 == 0.0f) return;
		else if (D2 < D1) cout << "����� ������� �� ����� ���� ������ ������" << endl;
		else if (D2 > 1000 || D1 > 1000) cout << "������� ������� �������" << endl;
		else if (ch == '4' && D1 < 0) cout << "������ ������� ���������� �� (0;+��)" << endl;
		else break;
	}
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
	hy = double((int)(height / hy));
	if (hy == 0)hy++;
	
	cout << 'h' << h<<" hy: " << hy << endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"��������",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	for (i1 = WIDTH / 2 + h; i1 <= 99 * WIDTH / 100; i1 += h) {
		SDL_RenderDrawLine(renderer, i1, HEIGHT / 2 - HEIGHT / 100, i1, HEIGHT / 2 + HEIGHT / 100);
	}
	for (i2 = WIDTH / 2 - h; i2 >= WIDTH / 100; i2 -= h) {

		SDL_RenderDrawLine(renderer, i2, HEIGHT / 2 - HEIGHT / 100, i2, HEIGHT / 2 + HEIGHT / 100);
	}
	if (hy <= 4) {
		for (i3 = HEIGHT / 2 + hy; i3 <= 99 * HEIGHT / 100; i3 += height/20) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i3, WIDTH / 2 + WIDTH / 400, i3);
		}
		for (i4 = HEIGHT / 2 - hy; i4 >= HEIGHT / 100; i4 -= height / 20) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i4, WIDTH / 2 + WIDTH / 400, i4);
		}
		i3 -= height / 20, i4 += height / 20;
	}
	else {
		for (i3 = HEIGHT / 2 + hy; i3 <= 99 * HEIGHT / 100; i3 += hy) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i3, WIDTH / 2 + WIDTH / 400, i3);
		}
		for (i4 = HEIGHT / 2 - hy; i4 >= HEIGHT / 100; i4 -= hy) {
			SDL_RenderDrawLine(renderer, WIDTH / 2 - WIDTH / 400, i4, WIDTH / 2 + WIDTH / 400, i4);
		}
		i3 -= hy, i4 += hy;
	}
	

	i2 += h, i1 -= h;
	SDL_RenderDrawLine(renderer, i2, HEIGHT / 2, i1, HEIGHT / 2);
	SDL_RenderDrawLine(renderer, WIDTH/2, i3, WIDTH/2, i4);
	double y,y1 = HEIGHT / 2 - f(ch, D1, a, b, c, d) * hy,x1 = (WIDTH / 2) + (D1 * h);
	SDL_SetRenderDrawColor(renderer, 192, 0, 64, 0);
	if (y1 < 0) y1 = 0;
	else if(y1 > HEIGHT)y1 = HEIGHT;
	for (double i = D1; i <=0 ; i+= 1.0f/h) {
		int x = (WIDTH / 2) + (i * h);
		y = HEIGHT / 2 - f(ch, i, a, b, c, d) * hy;
		if (y <= 0) y = 0;
		else if (y > HEIGHT)y = HEIGHT;
		SDL_RenderDrawLine(renderer, x1, y1, x, y);
		x1 = x, y1 = y;
		SDL_RenderPresent(renderer);
	}
	for (double i = 0; i <= D2; i += 1.0f / h) {
		int x = (WIDTH / 2) + (i * h);
		y = HEIGHT / 2 - f(ch, i, a, b, c, d) * hy;
		
		if (y <= 0) y = 0;
		else if(y>HEIGHT)y = HEIGHT;
		SDL_RenderDrawLine(renderer, x1, y1, x, y);
		cout << y << endl;
		x1 = x, y1 = y;
		SDL_RenderPresent(renderer);
	}
	SDL_RenderPresent(renderer);
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
