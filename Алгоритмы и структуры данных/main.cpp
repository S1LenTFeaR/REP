#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста
#include <exception>
#include <cmath>
#define N 3

using namespace std;

template <class T, int n>
class vector
{
private:
	T *vectors;
public:
	vector();
	~vector();
	T scalar_product();
	T scalar_product_sum();
};

template <class T, int n>
vector<T,n>::vector()
{
	vectors = new T[n];
}

template <class T, int n>
vector<T,n>::~vector()
{
	delete[]vectors;
}

template <class T, int n>
T vector<T, n>::scalar_product_sum()
{
	T a, b, c, mult = 0.0;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите a" << i + 1 << endl;
		cin >> a;
		cout << "Введите b" << i + 1 << endl;
		cin >> b;
		c = a * b;
		cout << "Result" << " = " << a << "*" << b << " = " << c << endl;
		mult += c;
	}
	cout << "mult = " << mult << endl;
	return mult;
}



int main()
{
	setlocale(LC_ALL, "RUS");
	vector<float, N> *x = 0;
	float y = 0;
	int i = 0;

	x[i].scalar_product_sum();

	return 0;
}