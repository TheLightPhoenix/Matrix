#include "mat.h"

using namespace std;

Mat::Mat(int rows1, int cols1)
{
	rows = rows1;
	cols = cols1;
	if(rows < 1)
	{
	    cout << "Rozmiar musi byc dodatni" << endl;
	    rows = 2;
	}
	if(cols < 1)
	{
	    cout << "Rozmiar musi byc dodatni" << endl;
	    cols = 2;
	}

	tab = new Wektor[rows];
	for(int i = 0; i < rows; ++i)
		tab[i] = Wektor(cols);
}

Mat::Mat(const Mat& m)
{
	rows = m.getRows();
	tab = new Wektor[rows];
	for(int i = 0; i < rows; ++i)
		tab[i] = m[i];
}

Mat::~Mat()
{
	delete[] tab;
}

Mat& Mat::operator=(const Mat& m)
{
    if(&m == this)
        return *this;

    delete[] tab;
    rows = m.getRows();
    cols = m.getCols();
    tab = new Wektor[rows];
	for(int i = 0; i < rows; ++i)
		tab[i] = m[i];
    return *this;
}

Mat Mat::operator+(const Mat& m) const
{
	if(m.getRows() != rows || m.getCols() != cols)
    {
        cout << "Niezgodne wielkosci macierzy" << endl;
        return *this;
    }
	else
	{
		Mat w(rows, cols);
		for(int i = 0; i < rows; ++i)
			w[i] = m[i] + tab[i];
		return w;
	}
}

Mat Mat::operator-(const Mat& m) const
{
	if(m.getRows() != rows || m.getCols() != cols)
    {
        cout << "Niezgodne wielkosci macierzy" << endl;
        return *this;
    }
	else
	{
		Mat w(rows, cols);
		for(int i = 0; i < rows; ++i)
			w[i] = tab[i] - m[i];
		return w;
	}
}

Mat Mat::operator*(double sk) const
{
	Mat w(rows, cols);
    for(int i = 0; i < rows; ++i)
        w[i] = tab[i] *sk;
    return w;
}

Mat operator*(double sk, const Mat& m)
{
    return m*sk;
}

Mat Mat::operator*(const Mat& m) const
{
    if(cols != m.getRows())
    {
        cout << "Niezgodne rozmiary, nie mo¿na wykonaæ mno¿enia macierzy" << endl;
        return *this;
    }

    Mat w(rows, m.getCols());
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < m.getCols(); ++j)
        {
            for(int x = 0; x < cols; ++x)
            {
                w[i][j] += tab[i][x]*m[x][j];
            }
        }
    }
    return w;
}

Mat& Mat::operator+=(const Mat& m)
{
	if(m.getRows() != rows || m.getCols() != cols)
    {
        cout << "Niezgodne wielkosci macierzy" << endl;
        return *this;
    }
	else
	{
		for(int i = 0; i < rows; ++i)
			tab[i] += m[i];
		return *this;
	}
}

Mat& Mat::operator-=(const Mat& m)
{
	if(m.getRows() != rows || m.getCols() != cols)
    {
        cout << "Niezgodne wielkosci macierzy" << endl;
        return *this;
    }
	else
	{
		for(int i = 0; i < rows; ++i)
			tab[i] -= m[i];
		return *this;
	}
}

Mat& Mat::operator*=(double sk)
{
    for(int i = 0; i < rows; ++i)
        tab[i] *= sk;
    return *this;
}

bool Mat::operator==(const Mat& m) const
{
    if(m.getRows() != rows || m.getCols() != cols)
        return false;
    for(int i = 0; i < rows; ++i)
    {
        if(m[i] != tab[i])
            return false;
    }
    return true;
}

bool Mat::operator!=(const Mat& m) const
{
    return !(*this == m);
}

ostream & operator<< (ostream &wyjscie, const Mat &m)
{
	for(int i = 0; i < m.rows; ++i)
		wyjscie << m[i];
	return wyjscie;
}

istream & operator>> (istream &wejscie, Mat &m)
{
    for(int i = 0; i < m.rows; ++i)
        wejscie >> m[i];
    return wejscie;
}

