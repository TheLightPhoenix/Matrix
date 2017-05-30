#ifndef MAT_H
#define MAT_H

#include "wektor.h"
#include <iostream>

class Mat
{
    private:
		Wektor* tab;
		//wektor jest rzedem
		int rows, cols;

	public:
		Mat(int rows1 = 2, int cols1 = 2);
		Mat(const Mat& m);
		~Mat();

		int getRows() const {return rows;};
		int getCols() const {return cols;};

		Wektor& operator[](int index) {return tab[index];};
		const Wektor& operator[](int index) const {return tab[index];};
		Mat& operator=(const Mat& m);
		Mat operator+(const Mat& m) const;
		Mat operator-(const Mat& m) const;
		Mat operator*(double sk) const;
		friend Mat operator*(double sk, const Mat& m);
		Mat operator*(const Mat& m) const;
		Mat& operator+=(const Mat& m);
		Mat& operator-=(const Mat& m);
		Mat& operator*=(double sk);
		bool operator==(const Mat& m) const;
		bool operator!=(const Mat& m) const;

		friend std::ostream & operator<< (std::ostream &wyjscie, const Mat &m);
		friend std::istream & operator>> (std::istream &wejscie, Mat &m);
};

#endif // MAT_H
