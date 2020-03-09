#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>
#include <fstream>
#include <random> 
#include <ctime>  

using namespace std;

int SelectAction()
{
	int action;
	cout << "Меню:" << endl;
	cout << "1 / пузырик" << endl;
	cout << "2 / быстрая" << endl;
	cout << "3 / турнирная" << endl;
	cout << "4 / завершить" << endl;
	cin >> action;
	return action;
}

template<class T>
T Puzyrik(T* arr, int size)
{
	double temp;

	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return *arr;
}

template<class T>
T quickSort(T* arr, int left, int right)
{
	T pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = arr[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((arr[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((arr[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	arr[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(arr, left, pivot - 1);
	if (right > pivot)
		quickSort(arr, pivot + 1, right);
	return *arr;
}

template<class T>
void heapify(T* arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
template<class T>
void heapSort(T* arr, int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

template <class T>
void realgen(int n)
{
	T* arr;
	T* arr1;
	arr = new T[n];
	arr1 = new T[n];
	default_random_engine gen(time(NULL));
	uniform_real_distribution<T> dis(1, 50);
	for (int i = 0; i < n; i++)
	{
		arr1[i] = dis(gen);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	int key;
	do
	{
		key = SelectAction();
		switch (key)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			Puzyrik(arr, n); //Сортировка пузырьком
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " "; 
			}
			cout << endl;
			break;
		case 2:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			quickSort(arr, 0, n - 1); //Быстрая сортировка
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		case 3:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			heapSort(arr, n);
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		default:
			key = -1;
			break;
		}
	} while (key != -1);
	delete[] arr;
	delete[] arr1;
}

template <class T>
void intgen(int n)
{
	T* arr;
	T* arr1;
	arr = new T[n];
	arr1 = new T[n];
	default_random_engine gen(time(NULL));
	uniform_int_distribution<T> dis(1, 50);
	for (int i = 0; i < n; i++)
	{
		arr1[i] = dis(gen);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	int key;
	do
	{
		key = SelectAction();
		switch (key)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			Puzyrik(arr, n); //Сортировка пузырьком
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		case 2:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			quickSort(arr, 0, n - 1); //Быстрая сортировка
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		case 3:
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr1[i];
			}
			cout << "Сортировка началась" << endl;
			heapSort(arr, n);
			cout << "Сортировка закончилась" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		default:
			key = -1;
			break;
		}
	} while (key != -1);
	delete[] arr;
	delete[] arr1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	realgen<double>(10);
	intgen<int>(10);


	return 0;
}