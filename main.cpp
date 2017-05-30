#include <iostream>
#include "wektor.h"
#include "mat.h"

using namespace std;

int main()
{
	///testowanie wektorow
	/*Wektor a;
	Wektor b(4);
	for(int i = 0; i < 4; ++i)
        b[i] = i;
	Wektor c(4);
	cout << "Podaj 4 wartosci: ";
	cin >> c;
	cout << "a: " << a << "b: " << b << "c: " << c << endl;
	cout << endl << c << "+ \n" << b << "= \n" << c+b;
	cout << endl << c << "- \n" << b << "= \n" << c-b;
	cout << endl << c << "* \n" << 2 << "\n= \n" << c*2;
	cout << endl << 2 << "\n* \n" << c << "= \n" << 2*c;

	cout << endl << c << "*= \n" << 2 << "\nc:";
	c*=2;
	cout << c;

	cout << endl << c << "+= \n" << b << "\nc:";
	c+=b;
	cout << c;

	cout << endl << c << "-=\n" << b << "\nc:";
	c-=b;
	cout << c;

	cout << endl << c << "== \n" << b << "= \n" << (c==b);
	cout << endl << endl << c << "!= \n" << b << "= \n" << (c!=b);

	Wektor d(5);
	d = c;

    cout << endl << endl << c << "== \n" << d << "= \n" << (c==d);
    cout << endl << endl << d[1] << endl;*/

    ///testowanie macierzy
    Mat z;
	Mat x(3,3);
	for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            x[i][j] = i*j;
	Mat y(3,3);
	cout << "Podaj 9 wartosci: ";
	cin >> y;

	cout << "z: " << endl << z << endl << "x: " << endl << x << endl << "y: " << endl << y << endl;
	cout << endl << y << "+ \n" << x << "= \n" << y+x;
	cout << endl << y << "- \n" << x << "= \n" << y-x;
	cout << endl << y << "* \n" << 2 << "\n= \n" << y*2;
	cout << endl << 2 << "\n* \n" << y << "= \n" << 2*y;
	cout << endl << y << "* \n" << x << "= \n" << y*x;

	cout << endl << y << "*= \n" << 2 << "\ny:\n";
	y*=2;
	cout << y;

	cout << endl << y << "+= \n" << x << "\ny:\n";
	y+=x;
	cout << y;

	cout << endl << y << "-=\n" << x << "\ny:\n";
	y-=x;
	cout << y;

	cout << endl << y << "== \n" << x << "= \n" << (y==x);
	cout << endl << endl << y << "!= \n" << x << "= \n" << (y!=x);

	Mat v(4,4);
	v = y;

    cout << endl << endl << y << "== \n" << v << "= \n" << (y==v);
    cout << endl << endl << v[1][1] << endl;

	return 0;
}
