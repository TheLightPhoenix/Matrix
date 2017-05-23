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
		int getElement(int index) const;
		void setElement(int index, int value);
		int getSize() const {return rozmiar;};
				
		int& operator[](int index);		
		Wektor operator+(Wektor& v);
		Wektor operator-(Wektor& v);
		Wektor operator*(int sk);		
		
		friend std::ostream & operator<< (std::ostream &wyjscie, const Wektor &w);
};

#endif