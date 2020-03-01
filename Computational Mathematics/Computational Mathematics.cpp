#include <iostream>
#include <cmath>
#include <clocale>
#include <fstream>
using namespace std;

double f1(double x)
{
	return sqrt(x + 1) - 1 / x;
}

double proizvod(double x, double h, double f(double x))
{
	return (f(x + h) - f(x)) / h;
}

double f2(double x)
{
	double pi = 3.1415926536;
	double alpha = x / 180 * pi;
	return pow(x, 3) - 7 * pow(sin(alpha), 3) + x - 4;
}

double Nuton(double eps, double Xn, double h, double f(double Xn))
{
	cout << "f(" << Xn << ") = " << f(Xn) << endl;
	for (int i = 0; eps <= abs(f(Xn)); i++)
	{
		Xn = Xn - f(Xn) / proizvod(Xn, h, f);
		cout << "f(" << Xn << ") = " << f(Xn) << endl;
	}
	cout << endl;
	return Xn;
}

double diht(double eps, double x0, double x1, double f(double x))
{

	double x2;
	while (x1 - x0 > eps) 
	{
		x2 = (x0 + x1) / 2;
		if (f(x2) * f(x1) > 0)
		{
			x1 = x2;
			cout << "f(" << x2 << ") = " << f(x2) << endl;
		}
		else
		{
			x0 = x2;
			cout << "f(" << x2 << ") = " << f(x2) << endl;
		}
	}
	return 0.5 * (x0 + x1);
}

double func(double x)
{
	return (pow(x, 6) + pow(x, 3) - 2) / sqrt(1 - pow(x, 3));
}

double proizvodX2(double x, double h, double f(double x))
{
	return (f(x + h) - f(x - h)) / (2 * h);
}

double proizvod2(double x, double h, double f(double x))
{
	return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double proizvod3(double x, double h, double f(double x))
{
	return (f(x + 2 * h) - 2 * f(x + h) + 2 * f(x - h) - f(x - 2 * h)) / (2 * pow(h, 3));
}

void func(double a, double h, double b, double N, ofstream& file, double f(double x))
{
	double c = b - a;
	cout << N << "N" << endl;
	file << N << "N" << endl;
	c /= N;
	if(c == 0)
	{ 
		cout << "f(" << a << ") =" << f(a) << endl;
		file << a << ";" << f(a) << endl;
	}
	else
	{ 
		for (a; a <= b; a += c)
		{
			cout << "f(" << a << ") =" << f(a) << endl;
			file << a << ";" << f(a) << endl;
		}
	}
	cout << endl;
}

void func(double a, double h, double b, double N, ofstream& file, double f(double x, double h, double f(double x)))
{
	double c = b - a;
	cout << N << "N" << endl;
	file << N << "N" << endl;
	c /= N;
	if (c == 0)
	{
		cout << "f(" << a << ") =" << f(a, h, func) << endl;
		file << a << ";" << f(a, h, func) << endl;
	}
	else
	{ 
		for (a; a <= b; a += c)
		{
			cout << "f(" << a << ") =" << f(a, h, func) << endl;
			file << a << ";" << f(a, h, func) << endl;
		}
	}
	cout << endl;
}

int SelectAction()
{
	int action;
	cout << "Меню:" << endl;
	cout << "1 / найти x, где f(x) = 0 в sqrt(x+1)-1/x методом Ньютона" << endl;
	cout << "2 / найти x, где f(x) = 0 в x^3-7*sin^3(x)+x-4/x методом Ньютона" << endl;
	cout << "3 / найти x, где f(x) = 0 в x^3-7*sin^3(x)+x-4/x методом дихтонии" << endl;
	cout << "4 / вычислить функцию (x^6+x^3-2)/sqrt(1-x^3)" << endl;
	cout << "5 / вычислить первую производную функции (x^6+x^3-2)/sqrt(1-x^3)" << endl;
	cout << "6 / вычислить первую производную функции с x2 точностью (x^6+x^3-2)/sqrt(1-x^3)" << endl;
	cout << "7 / вычислить вторую производную функции (x^6+x^3-2)/sqrt(1-x^3)" << endl;
	cout << "8 / вычислить третью производную функции (x^6+x^3-2)/sqrt(1-x^3)" << endl;
	cout << "9 / вычислить первую производную функции (x^6+x^3-2)/sqrt(1-x^3) аналит" << endl;
	cout << "10 / вычислить вторую производную функции (x^6+x^3-2)/sqrt(1-x^3) аналит" << endl;
	cout << "11 / вычислить третью производную функции (x^6+x^3-2)/sqrt(1-x^3) аналит" << endl;
	cout << "12 / завершить" << endl;
	cin >> action;
	return action;
}

double proizvoda1(double x)
{
	return (3 * pow(x, 2) + 6 * pow(x, 5)) / sqrt(1 - pow(x, 3)) + 3 * pow(x, 2) * (pow(x, 6) + pow(x, 3) - 2) / (2 * pow((1 - pow(x, 3)), 1.5));
}

double proizvoda2(double x)
{
	return 3 * x * (2 + 10 * pow(x, 3) + 3 * pow(x, 3) * (1 + 2 * pow(x, 3)) / (1 - pow(x, 3)) - (-4 + 9 * pow(x, 3) / (-1 + pow(x, 3))) * (-2 + pow(x, 3) + pow(x, 6)) / (4 * (1 - pow(x, 3)))) / sqrt(1 - pow(x, 3));
}

double proizvoda3(double x)
{
	return 3 * (2 + 40 * pow(x, 3) + 9 * pow(x, 3) * (1 + 5 * pow(x, 3)) / (1 - pow(x, 3)) + (-2 + pow(x, 3) + pow(x, 6)) * (8 - 108 * pow(x, 3) / (-1 + pow(x, 3)) + 135 * pow(x, 6) / pow((-1 + pow(x, 3)), 2)) / (8 * (1 - pow(x, 3))) - 9 * pow(x, 3) * (1 + 2 * pow(x, 3)) * (-4 + 9 * pow(x, 3) / (-1 + pow(x, 3))) / (4 * (1 - pow(x, 3)))) / sqrt(1 - pow(x, 3));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream file("f(x).txt");
	double h = 0.01, eps = 0.5 * pow(10, -3);
	double a, b, N;
	cout << "Введите начало отрезка a" << endl;
	cin >> a;
	cout << "Введите конец отрезка b" << endl;
	cin >> b;
	int key;
	do 
	{	
		key = SelectAction();
		switch (key)
		{
		case 1:
			cout << "x = " << Nuton(eps, a, h, f1) << endl;
			break;
		case 2:
			cout << "x = " << Nuton(eps, a, h, f2) << endl;
			break;
		case 3:
			cout << "x = " << diht(eps, a, b, f2) << endl;
			break;
		case 4:
			N = 1;
			func(a, h, b, N, file, func);
			N = 2;
			func(a, h, b, N, file, func);
			N = 4;
			func(a, h, b, N, file, func);
			break;
		case 5:
			N = 1;
			func(a, h, b, N, file, proizvod);
			N = 2;
			func(a, h, b, N, file, proizvod);
			N = 4;
			func(a, h, b, N, file, proizvod);
			break;
		case 6:
			N = 1;
			func(a, h, b, N, file, proizvodX2);
			N = 2;
			func(a, h, b, N, file, proizvodX2);
			N = 4;
			func(a, h, b, N, file, proizvodX2);
			break;
		case 7:
			N = 1;
			func(a, h, b, N, file, proizvod2);
			N = 2;
			func(a, h, b, N, file, proizvod2);
			N = 4;
			func(a, h, b, N, file, proizvod2);
			break;
		case 8:
			N = 1;
			func(a, h, b, N, file, proizvod3);
			N = 2;
			func(a, h, b, N, file, proizvod3);
			N = 4;
			func(a, h, b, N, file, proizvod3);
			break;
		case 9:
			N = 1;
			func(a, h, b, N, file, proizvoda1);
			N = 2;
			func(a, h, b, N, file, proizvoda1);
			N = 4;
			func(a, h, b, N, file, proizvoda1);
			break;
		case 10:
			N = 1;
			func(a, h, b, N, file, proizvoda2);
			N = 2;
			func(a, h, b, N, file, proizvoda2);
			N = 4;
			func(a, h, b, N, file, proizvoda2);
			break;
		case 11:
			N = 1;
			func(a, h, b, N, file, proizvoda3);
			N = 2;
			func(a, h, b, N, file, proizvoda3);
			N = 4;
			func(a, h, b, N, file, proizvoda3);
			break;
		default:
			key = -1;
			break;
		}
	} while (key != -1);
	file.close();
	return 0;
}

