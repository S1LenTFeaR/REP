#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <chrono>
#include <random> 
#include <ctime>  
#include <iomanip>
#define N 50000

using namespace std;

template <class T, int n>
class svector
{
private:
	T *vectors;
public:
	svector();
	~svector();
	T scalar_product();
	T multiply(T a[], T b[]);
};

template <class T, int n>
svector<T,n>::svector()
{
	vectors = new T[n];
}

template <class T, int n>
svector<T,n>::~svector()
{
	delete[]vectors;
}

template <class T, int n>
T svector<T, n>::multiply(T a[], T b[])
{
	T c, mult = 0.0;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		c = a[i] * b[i];
		//cout << "Result" << " = " << a[i] << "*" << b[i] << " = " << std::setprecision(4) << std::fixed << c << endl;
		//cout << mult << " + " << c << " = " << std::setprecision(4) << std::fixed <<  mult + c << endl;
		mult += c;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration = " << std::setprecision(8) << std::fixed << duration.count() << endl;
	return mult;
}

template <class T, int n>
T svector<T, n>::scalar_product()
{
	T a[n], b[n], mult = 0.0;
	default_random_engine gen(time(NULL));
	//uniform_int_distribution<T> uid(0, 1000);
	uniform_int_distribution<T> dis(1, 50);
	for (int i = 0; i < n; i++)
	{
		a[i] = dis(gen);
		//cout << "a" << i + 1 << " b" << i + 1 << ": " << a[i] << " ";
		b[i] = dis(gen);
		//cout << b[i] << endl;
	}
	mult = multiply(a, b);
	cout << "mult = " << std::setprecision(8) << std::fixed << mult << endl;
	return mult;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	svector<int, N> *x = nullptr;
	float y = 0;
	int i = 0;
	
	x[i].scalar_product();
	
	return 0;
}