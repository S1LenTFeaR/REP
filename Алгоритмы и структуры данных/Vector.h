#pragma once
template <class T, int n>
class vect
{
private:
	T a;
	T b;
public:
	vect() : a(0), b(0) {};
	vect(T, T);
	~vect();
	void read();
};

