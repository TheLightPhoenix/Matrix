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
		tab[i] = 1;
}

Wektor::Wektor(const Wektor& v)
{
	rozmiar = v.getSize();
	tab = new int[rozmiar];
	for(int i = 0; i < rozmiar; ++i)
		tab[i] = v.getElement(i);
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

Wektor Wektor::operator+(Wektor& v)
{
	if(v.getSize() != this->getSize())
		return Wektor();
	else
	{
		Wektor w(v.getSize());		
		for(int i = 0; i < v.getSize(); ++i)
			w.setElement(i, this->getElement(i)+v.getElement(i));
		return w;
	}
}		

Wektor Wektor::operator-(Wektor& v)
{
	if(v.getSize() != this->getSize())
		return Wektor();
	else
	{
		Wektor w(v.getSize());		
		for(int i = 0; i < v.getSize(); ++i)
			w.setElement(i, this->getElement(i)-v.getElement(i));
		return w;
	}
}

Wektor Wektor::operator*(int sk)
{
	Wektor w(getSize());		
	for(int i = 0; i < getSize(); ++i)
		w.setElement(i, this->getElement(i)*sk);
	return w;
}

int& Wektor::operator[](int index)
{
	return tab[index];
}

ostream & operator<< (ostream &wyjscie, const Wektor &w)
{
	for(int i = 0; i < w.rozmiar; ++i)
		wyjscie << w.getElement(i) << ' ';
	wyjscie << endl;
	return wyjscie;
}