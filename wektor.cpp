#include "wektor.h"
#include <iostream>

using namespace std;

Wektor::Wektor(int rozmiar1)
{
	rozmiar = rozmiar1;
	if(rozmiar < 1)
		cout << "Rozmiar musi byc dodatni" << endl;
	tab = new int[rozmiar];
	for(int i = 0; i < rozmiar; ++i)
		tab[i] = 0;
}

Wektor::~Wektor()
{
	delete[] tab;
}

int Wektor::getElement(int index) const
{
	if(index < 0 || index >= rozmiar)
	{
		cout << "Przekroczono zakres" << endl;
		return -1;	
	}
	return tab[index];
}

void Wektor::setElement(int index, int value)
{
	if(index < 0 || index >= rozmiar)
	{
		cout << "Przekroczono zakres" << endl;
		return;	
	}
	tab[index] = value;
}

ostream & operator<< (ostream &wyjscie, const Wektor &w)
{
	for(int i = 0; i < w.rozmiar; ++i)
		wyjscie << w.getElement(i) << ' ';
	wyjscie << endl;
	return wyjscie;
}