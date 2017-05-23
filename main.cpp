#include <iostream>
#include "wektor.h"

using namespace std;

int main()
{
	Wektor a(10);
	cout << a;
	Wektor b(10);
	cout << b;
	Wektor c = a+b;
	cout << c;
	Wektor d = a - b;
	cout << d;
	Wektor e = a*5;
	cout << e;
	cout << a[0] << endl;
	return 0;
}