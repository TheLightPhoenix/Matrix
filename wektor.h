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
		~Wektor();
		int getElement(int index) const;
		void setElement(int index, int value);
		int getSize(){return rozmiar;};
		
		friend std::ostream & operator<< (std::ostream &wyjscie, const Wektor &w);
};

#endif