#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>

class Wektor
{
	private:
		int* tab;
		int rozmiar;

	public:
		Wektor(int rozmiar1 = 2);
		Wektor(const Wektor& v);
		~Wektor();

		int getSize() const {return rozmiar;};

		int& operator[](int index) {return tab[index];};
		const int& operator[](int index) const {return tab[index];};
		Wektor& operator=(const Wektor& v);
		Wektor operator+(const Wektor& v) const;
		Wektor operator-(const Wektor& v) const;
		Wektor operator*(double sk) const;
		friend Wektor operator*(double sk, const Wektor& v);
		Wektor& operator+=(const Wektor& v);
		Wektor& operator-=(const Wektor& v);
		Wektor& operator*=(double sk);
		bool operator==(const Wektor& v) const;
		bool operator!=(const Wektor& v) const;

		friend std::ostream & operator<< (std::ostream &wyjscie, const Wektor &w);
		friend std::istream & operator>> (std::istream &wejscie, Wektor &w);
};

#endif
