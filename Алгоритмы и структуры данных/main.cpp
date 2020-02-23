#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <chrono>
#include <random> 
#include <ctime>  
#include <iomanip>
#include "Vectors.h"
#define N 50000

using namespace std;



int main()
{
	setlocale(LC_ALL, "RUS");
	vectors<int, N> vector1;

	vector1.scalar_product();
	
	return 0;
}