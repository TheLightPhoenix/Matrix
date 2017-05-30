#include "wektor.h"

using namespace std;

Wektor::Wektor(int rozmiar1)
{
	rozmiar = rozmiar1;
	if(rozmiar < 1)
	{
	    cout << "Rozmiar musi byc dodatni" << endl;
	    rozmiar = 2;
	}
	tab = new int[rozmiar];
	for(int i = 0; i < rozmiar; ++i)
		tab[i] = 0;
}

Wektor::Wektor(const Wektor& v)
{
	rozmiar = v.getSize();
	tab = new int[rozmiar];
	for(int i = 0; i < rozmiar; ++i)
		tab[i] = v[i];
}

Wektor::~Wektor()
{
	delete[] tab;
}

Wektor& Wektor::operator=(const Wektor& v)
{
    if(&v == this)
        return *this;

    delete[] tab;
    rozmiar = v.getSize();
    tab = new int[rozmiar];
    for(int i = 0; i < rozmiar; ++i)
    {
        tab[i] = v[i];
    }
    return *this;
}

Wektor Wektor::operator+(const Wektor& v) const
{
	if(v.getSize() != rozmiar)
    {
        cout << "Niezgodne wielkosci wektorow" << endl;
        return *this;
    }
	else
	{
		Wektor w(rozmiar);
		for(int i = 0; i < rozmiar; ++i)
			w[i] = v[i] + tab[i];
		return w;
	}
}

Wektor Wektor::operator-(const Wektor& v) const
{
	if(v.getSize() != rozmiar)
    {
        cout << "Niezgodne wielkosci wektorow" << endl;
        return *this;
    }
	else
	{
		Wektor w(rozmiar);
		for(int i = 0; i < rozmiar; ++i)
			w[i] = tab[i] - v[i];
		return w;
	}
}

Wektor Wektor::operator*(double sk) const
{
	Wektor w(rozmiar);
	for(int i = 0; i < rozmiar; ++i)
		w[i] = sk*tab[i];
	return w;
}

Wektor operator*(double sk, const Wektor& v)
{
    return v*sk;
}

Wektor& Wektor::operator+=(const Wektor& v)
{
	if(v.getSize() != rozmiar)
    {
        cout << "Niezgodne wielkosci wektorow" << endl;
        return *this;
    }
	else
	{
		for(int i = 0; i < rozmiar; ++i)
			tab[i] += v[i];
		return *this;
	}
}

Wektor& Wektor::operator-=(const Wektor& v)
{
	if(v.getSize() != rozmiar)
    {
        cout << "Niezgodne wielkosci wektorow" << endl;
        return *this;
    }
	else
	{
		for(int i = 0; i < rozmiar; ++i)
			tab[i] -= v[i];
		return *this;
	}
}

Wektor& Wektor::operator*=(double sk)
{
	for(int i = 0; i < rozmiar; ++i)
		tab[i] *= sk;
	return *this;
}

bool Wektor::operator==(const Wektor& v) const
{
    if(rozmiar != v.getSize())
        return false;
    for(int i = 0; i < rozmiar; ++i)
    {
        if(v[i] != tab[i])
            return false;
    }
    return true;
}

bool Wektor::operator!=(const Wektor& v) const
{
    return !(*this == v);
}

ostream & operator<< (ostream &wyjscie, const Wektor &w)
{
	for(int i = 0; i < w.rozmiar; ++i)
		wyjscie << w[i] << ' ';
	wyjscie << endl;
	return wyjscie;
}

istream & operator>> (istream &wejscie, Wektor &w)
{
    for(int i = 0; i < w.rozmiar; ++i)
        wejscie >> w[i];
    return wejscie;
}
