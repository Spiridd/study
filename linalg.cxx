// add some valarray functions
// add numeric
#include <iostream>
#include <iomanip>
#include <valarray>
#include <numeric>
#include <cmath>

using namespace std;

// first index - coloumn
// second index - row
template <class T>
class Matrix
{
protected:
    int rows, cols;
    valarray<valarray<T>> matr;
public:
    // constructors
    Matrix ()
    {}
    Matrix (int rows_, int cols_)
        : rows (rows_)
        , cols (cols_)
    {
        matr.resize(cols);
        for (int i=0; i<cols; i++)
            matr[i].resize(rows);
    }
    Matrix (const Matrix &W)
    {
        rows = W.rows;
        cols = W.cols;
        matr = W.matr;
    }
    Matrix (T **p, int rows_, int cols_)
        : rows (rows_)
        , cols (cols_)
    {
        matr.resize(cols);
        for (int i=0; i<cols; i++)
            matr[i].resize(rows);
        for (int i=0; i<cols; i++)
            for (int j=0; j<rows;j++)
                matr[i][j] = p[i][j];
    }
    ~Matrix ()
    {}
    void display() const
    {
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
                cout << setw(10) << matr[j][i];
            cout << endl;
        }
    }
    const T SumCol (int k) const
    {
		T x = 0;
		x = accumulate (begin(matr[k]), end(matr[k]), x);
		return x;
	}
	T GetMax()
	{
		T x = 0;
		for (int i=0; i<cols; i++)
			if (matr[i].max() > x)
				x = matr[i].max();
		return x;
	}
    void Swap (Matrix &M)
    {
		try
		{
			if (rows != M.rows || cols != M.cols)
				throw (0);
			else
			{
				for (int i=0; i<cols; i++)
					swap (matr[i], M.matr[i]);
			}
		}
		catch (...)
		{
			cout << "Can't swap Matrixes" << endl;
		}
	}
    Matrix& operator = (const Matrix &W)
    {
        rows = W.rows;
        cols = W.cols;
        matr = W.matr;
        return *this;
    }
    Matrix operator + (const Matrix &W)
    {
        Matrix ret (rows, cols);
        try
        {
            if (rows != W.rows || cols != W.cols)
                throw (0);
            else
            {
                ret.matr = matr + W.matr;
            }
        }
        catch(...)
        {
            cout << "Matrix addition is impossible" << endl;
            //return *this;
        }
        return ret;
    }
    Matrix& operator += (const Matrix &W)
    {
        try
        {
            if (rows != W.rows || cols != W.cols)
                throw (0);
            else
            {
                matr = matr + W.matr;
            }
        }
        catch (...)
        {
            cout << "Can't plus matrix" << endl;
        }
        return *this;
    }
    Matrix& operator *= (int k)
    {
        for (int i=0; i<cols; i++)
            matr[i] = k * (matr[i]);
        return *this;
    }
    Matrix operator * (int k)
    {
        for (int i=0; i<cols; i++)
            matr[i] = k * matr[i];
        return *this;
    }
    Matrix operator * (const Matrix &W)
    {
        Matrix ret (rows, W.cols);
        try
        {
            if (cols != W.rows)
                throw (0);
            else
                for (int i=0; i<ret.cols; i++)
                for (int j=0; j<ret.rows; j++)
                {
                    int x = 0;
                    for (int k=0; k<rows; k++)
                        x += matr[k][j] * W.matr[i][k];
                    ret.matr[i][j] = x;
                }
        }
        catch (...)
        {
            cout << "Can't multiply matrixes" << endl;
        }
        return ret;
    }
    T& operator () (int c, int r)
    {
        return matr[c][r];
    }
    Matrix operator ~ () // transpose
    {
		Matrix ret (cols, rows);
		for (int i=0; i<rows; i++)
			for (int j=0; j<cols; j++)
				ret.matr[i][j] = matr[j][i];
		return ret;
	}
    const int GetRows () const
    {
        return rows;
    }
    const int GetCols () const
    {
        return cols;
    }
};

template <class T>
class Vector : public Matrix<T>
{
	using Matrix<T>::cols;
	using Matrix<T>::rows;
	using Matrix<T>::matr;
public:
    Vector ()
    {
        cols = 1;
    }
    Vector (int rows_)
    {
        rows = rows_;
        cols = 1;
        matr.resize(1);
        matr[0].resize(rows);
    }
    Vector (T *p, int rows_)
    {
        rows = rows_;
        cols = 1;
        matr.resize(1);
        matr[0].resize(rows);
        for (int i=0; i<rows; i++)
            matr[0][i] = p[i];
    }
    Vector (const Vector &V)
    {
        rows = V.rows;
        cols = 1;
        matr = V.matr;
    }
    T& operator () (T k)
    {
        return matr[0][k];
    }
    const double GetNorm () const
    {
		double norm = 0;
		norm = inner_product (begin(matr[0]), end(matr[0]), begin(matr[0]), norm);
		norm = sqrt (norm);
		return norm;
	}
	void display() const
	{
		for (int i=0; i<rows; i++)
			cout << setw(10) << matr[0][i] << endl;
	}
	Vector<T>& operator = (Matrix<T> M)
	{
		try
		{
			if (rows != M.GetRows() || M.GetCols() != 1)
				throw (0);
			else
			{
				for (int i=0; i<rows; i++)
					matr[0][i] = M(0,i);
			}
		}
		catch (...)
		{
			cout << "Can't assign Matrix to Vector" << endl;
		}
		return *this;
	}
	Vector& operator ~ ()
	{
		cout << "Can't transpose Vector" << endl;
		return *this;
	}
};

template <class T>
Vector<T> operator * (Matrix<T> &M, Vector<T> &V)
{
    int rows = V.GetRows();
    int cols = M.GetCols();
    Vector<T> ret (rows);
    try
        {
            if (cols != rows)
                throw (0);
            else
                for (int i=0; i<cols; i++)
                {
                    T x = 0;
                    for (int k=0; k<cols; k++)
                    {
                        x += M(k,i) * V(k);
                    }
                    ret(i) = x;
                }
        }
        catch (...)
        {
            cout << "Can't multiply matrix and vector" << endl;
        }
        return ret;
}

int main()
{
	int v[] = {8, 4, -3, 9, 6};
	cout << "V" << endl;
	Vector<int> V(v,5);
	V.display();
	cout << endl << "V norm = " << V.GetNorm() << endl << endl;
	V = V + V;
	cout << "V+V" << endl;
	V.display();
    Matrix<int> M(5,5);
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            M(i,j) = (i+2)*j;
    cout << "M" << endl;
    M.display();
    cout << "Max element is " << M.GetMax() << endl;
    cout << "Sum of 1 coloumn = " << M.SumCol(0) << endl;
    V = M*V;
    cout << "V = M*V" << endl;
    V.display();
    V = ~V;
    Matrix<int> R = M;
    M = M*R;
    cout << "M = M*M" << endl;
    M.display();
    cout << "R" << endl;
    R.display();
    R.Swap (M);
    cout << "R.Swap (M)" << endl;
    cout << "R" << endl;
    R.display();
    cout << "M" << endl;
    M.display();
    R *= 2;
    cout << "R = R * 2" << endl;
    R.display();
    R = R+M;
    cout << "R = R+M" << endl;
    R.display();
    M += R;
    cout << "M += R" << endl;
    M.display();
    M = M*2;
    cout << "M = M*2" << endl;
    M.display();
    M = ~M;
    cout << "M transposed" << endl;
    M.display();
    return 0;
}
