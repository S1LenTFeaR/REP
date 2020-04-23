#include <iostream>
#include <cmath>
#include <clocale>
#include <fstream>
#include <iomanip>
#define n 6
using namespace std;

void glavelem(int k, double matrix[n][n + 1], int otv[n]);

template<typename T>
void vivod(T a[n][n + 1])
{
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << "|\t" << a[i][n] << endl;
	}
	cout << endl;
}

template<typename T>
T Gauss(T a[n][n], T b[n], T x[n])
{
	int i, j, k;
	double matrix[n][n + 1]; //Общая матрица
	int otv[n]; //Отвечает за порядок корней
	//Совмещаем матрицы в одну
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			matrix[i][j] = a[i][j];
		matrix[i][n] = b[i];
	}
	//Выводим матрицы на экран
	cout << "Матрица СЛАУ для решения методом Гаусса: " << endl;
	vivod(matrix);
	//Сначала все корни по порядку
	for (i = 0; i < n; i++)
		otv[i] = i;
	//Прямой ход метода Гаусса
	for (k = 0; k < n; k++)
	{ 
		//На какой позиции должен стоять главный элемент
		glavelem(k, matrix, otv); //Установка главного элемента
		if (fabs(matrix[k][k]) < 0.0001)
		{
			printf("Система не имеет единственного решения");
			return (0);
		}
		for (j = n; j >= k; j--)
			matrix[k][j] /= matrix[k][k];
		for (i = k + 1; i < n; i++)
			for (j = n; j >= k; j--)
				matrix[i][j] -= matrix[k][j] * matrix[i][k];
	}
	//Обратный ход
	for (i = 0; i < n; i++)
		x[i] = matrix[i][n];
	for (i = n - 2; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			x[i] -= x[j] * matrix[i][j];
	//Выводим корни на экран
	cout << "Корни:" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == otv[j])
			{ //Расставляем корни по порядку
				cout << x[j] << "\t";
				break;
			}
	cout << "\n" << endl;
	return 0;
}

template<typename T>
void progonka(T a[n][n], T b[n], T x[n])
{
	int i, N, j, k;
	double z; //Промежуточная переменная
	double A[n]; //Прогоночный коэффициент A
	double B[n]; //Прогоночный коэффициент B
	double matrix[n][n + 1];
	//Собираем все в 1 матрицу для вывода на экран
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			matrix[i][j] = a[i][j];
		matrix[i][n] = b[i];
	}
	//Выводим матрицу на экран
	cout << "Матрица СЛАУ для решения прогонкой: " << endl;
	vivod(matrix);
	N = n - 1;
	//Вычисляем начальные A и B
	A[0] = -a[0][1] / a[0][0];
	B[0] = b[0] / a[0][0];
	//Прямой ход
	for (i = 1; i < N; i++)
	{
		z = a[i][i] + a[i][i - 1] * A[i - 1];
		A[i] = -a[i][i + 1] / z;
		B[i] = (b[i] - a[i][i - 1] * B[i - 1]) / z;
	}
	//Обратный ход
	x[N] = (b[N] - a[N][N - 1] * B[N - 1]) / (a[N][N] + a[N][N - 1] * A[N - 1]);
	for (i = N - 1; i >= 0; i--)
		x[i] = A[i] * x[i + 1] + B[i];
	//Выводим A и B на экран
	cout << "A и B:" << endl;
	for (i = 0; i < n-1; i++)
	{
		cout << setprecision(4) << A[i] << "\t\t" << B[i] << endl;
	}
	cout << endl;
	//Выводим корни на экран
	cout << "Корни:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << x[i] << "\t";
	}
	cout << "\n" << "\n" << endl;
}

void glavelem(int k, double matrix[n][n + 1], int otv[n])
{
	int i, j, i_max = k, j_max = k;
	double temp;
	//Ищем максимальный по модулю элемент
	for (i = k; i < n; i++)
		for (j = k; j < n; j++)
			if (fabs(matrix[i_max][j_max]) < fabs(matrix[i][j]))
			{
				i_max = i;
				j_max = j;
			}
	//Переставляем строки
	for (j = k; j < n + 1; j++)
	{
		temp = matrix[k][j];
		matrix[k][j] = matrix[i_max][j];
		matrix[i_max][j] = temp;
	}
	//Переставляем столбцы
	for (i = 0; i < n; i++)
	{
		temp = matrix[i][k];
		matrix[i][k] = matrix[i][j_max];
		matrix[i][j_max] = temp;
	}
	//Учитываем изменение порядка корней
	i = otv[k];
	otv[k] = otv[j_max];
	otv[j_max] = i;
}

int main()
{
	setlocale(LC_ALL, "Russian");
    double x[n] = { 0 }; //Корни системы
	double a1[n][n] = {{-9, 0, 1,-9, 1, 7},
				    {1 ,-5, 9,-2,-6, 8},
				    {1 ,-8, 9,-3, 5,-7},
					{2 ,-3, 1,-4, 4,-9},
					{4 ,-7,-6, 2, 4, 1},
					{-2,-0,-4, 1,-7, 7}};
	double a2[n][n] = {{7 , 2, 0, 0, 0, 0},
					{9 ,-3, 5, 5, 0, 0},
					{0 ,-5, 5, 5, 0, 0},
					{0 , 0, 5, 4, 6, 0},
					{0 , 0, 0,-6,-7,-5},
					{0 , 0, 0, 0,-1, 3}};
	double b1[n] = { -38, -14, 196, 128, 62, -117 };
	double b2[n] = { 23, 78, 65, 31, 11, -21 };
	
	Gauss(a1, b1, x); //Считаем 1 СЛАУ методом Гаусса
	
	progonka(a2, b2, x); //Считаем 2 СЛАУ методом прогонки

	system("pause"); //Чтобы сразу не пропадало окно
	return 0;
}
