#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>
#include <fstream>
using namespace std;

double f(double x)
{
    return x * sin(x);
}

double fu(double x)
{
    return x * sqrt(x);
}

double Rectangle(double x, double xn, double h) //По методу прямоугольника
{
    double S = 0;
    for (x; x < xn; x += h)
    {
        S += f(x);
    }
    return S *= h;
}

double Trapeze(double x, double xn, double h) //По методу трапеции
{
    double S = 0.5 * (f(x) + f(xn));
    for (x += h; x < xn; x += h)
    {
        S += f(x);
    }
    return S *= h;
}

double Simpson(double x, double xn, double h, int N) //По методу Симпсона
{
    double I, I2 = 0, I4 = 0;
    I4 = f(x + h);
    for (int i = 2; i < N; i += 2)
    {
        if (N > 3)
            I4 += f(x + (i + 1) * h);
        I2 += f(x + i * h);
    }
    I = f(x) + f(xn) + 4 * I4 + 2 * I2;
    I *= h / 3;
    return I;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    double pi = 3.14159265;
    double a = 0, b = 2 * pi;
    int N = 4;
    double h = (b - a) / N;
    cout << "N по методу прямоугольника: " << Rectangle(a, b, h) << endl;
    cout << "N по методу трапеции: " << Trapeze(a, b, h) << endl;
    cout << "N по методу симпсона: "  << Simpson(a, b, h, N) << endl;
    N *= 2;
    h = (b - a) / N;
    cout << "2N по методу прямоугольника: " << Rectangle(a, b, h) << endl;
    cout << "2N по методу трапеции: " << Trapeze(a, b, h) << endl;
    cout << "2N по методу симпсона: " << Simpson(a, b, h, N) << endl;
}