#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста

using namespace std;

#define Z 79

using namespace std;

double xmax = 1;
double ymax = 5;
double dt = 0.01;
double tk = 5;

void polet(double y, double F, ofstream& file)
{
	double Vx = 3;
	double Vy = 0;
	double x = -3;
	double t = 0;
	while ((t <= tk) && (x <= xmax) && (y <= ymax))
	{
		Vx = Vx + F * abs(x) * pow(x * x + y * y, -1.5) * dt;
		Vy = Vy + F * abs(y) * pow(x * x + y * y, -1.5) * dt;
		x += Vx * dt;
		y += Vy * dt;
		t += dt;
		if ((x <= xmax) && (y <= ymax))
			file << x << "," << y << endl;
	}
}

int main()
{
	ofstream file("Polet.txt");
	double e = 1.602189246 * pow(10, -19);
	double k = 8.987551777 * pow(10, 9);
	double Ma = 6.638 * pow(10, -27);
	double kof = (2 * k * Z * e * e) / Ma;
	file << "x,y" << endl;
	polet(0.1, kof, file);
	polet(0.3, kof, file);
	polet(0.5, kof, file);
	return 0;
}