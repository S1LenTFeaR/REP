#include "Vectors.h"



template <class T, int n>
vectors<T, n>::vectors()
{
	vectors = new T[n];
}

template <class T, int n>
vectors<T, n>::~vectors()
{
	delete[]vectors;
}

template <class T, int n>
void vectors<T, n>::read_vectors()
{
	for (int i = 0; i < n; i++)
	{
			vects[i] = new vector();
			vects[i]->read();
	}
}

template <class T, int n>
T vectors<T, n>::multiply()
{
	T c, mult;
	for (int i = 0; i < n; i++)
	{
		c = vects[i].a * vects[i].b;
		mult += c;
	}
	return mult;
}

template <class T, int n>
T vectors<T, n>::scalar_product()
{
	T mult;
	read_vectors();
	mult = multiply();
	cout << "multiply = " << mult << endl;
}