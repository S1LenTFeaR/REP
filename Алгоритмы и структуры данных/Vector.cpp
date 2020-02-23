#include "Vector.h"
#include <random>
#include <ctime>

using namespace std;

template <class T, int n>
void vect<T, n>::read()
{
    default_random_engine gen(time(NULL));
    uniform_int_distribution<T> dis(1, 50);
    a = dis(gen);
    b = dis(gen);
}

template <class T, int n>
vect<T, n>::vect(T aa, T bb)
{
    a = aa;
    b = bb;
}

template <class T, int n>
vect<T, n>::~vect(){}


