#pragma once
#include "Vector.h" 

using namespace std;

template <class T, int n>
class vectors
{
private:
	vect * * vects;
public:
	vectors();
	~vectors();
	void read_vectors();
	T multiply();
	T scalar_product();
};




