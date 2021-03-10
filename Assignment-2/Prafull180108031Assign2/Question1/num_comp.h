#ifndef NUM_COMP
#define NUM_COMP

#include<iostream>
#include<math.h>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;


template <class T>
class Complex;

template<class T>
ostream& operator<< ( ostream& os, const Complex<T>& obj );


template<typename T>
class Complex {
    private:
        T real;
        T img;
        friend ostream& operator<< <>(ostream&, const Complex&);
    public:
        Complex();
        //constructor
        Complex(T real_part, T img_part);
        //conjugate
        Complex<T> conjugate();
        //multiplicative inverse
        Complex<T> inverse();
        // addition
        Complex<T> operator + (Complex<T> const &obj);
        //substraction
        Complex<T> operator - (Complex<T> const &obj);
        //multiplication
        Complex<T> operator * (Complex<T> const &obj);
        //division
        Complex<T> operator / (Complex<T> const &obj);
        //absolute value
        T absolute();
        T get_real();
        T get_imaginary();
        
};


template<typename T>
Complex<T> :: Complex() {
    real = 0;
    img = 0;
}


template<typename T>
Complex<T> :: Complex(T real_part, T img_part) {
    real = real_part;
    img = img_part;
}


template<typename T>
Complex<T> Complex<T> :: conjugate() {
    Complex<T> result;
    result.real = real;
    result.img = 0 - img;
    return result;
}


template<typename T>
Complex<T> Complex<T> :: inverse() {
    Complex<T> result;
    T abs_sqr = real*real + img*img;
    result = conjugate();
    result.real = result.real/abs_sqr;
    result.img = result.img/abs_sqr;
    return result;
}


template<typename T>
Complex<T> Complex<T> :: operator + (Complex<T> const &obj) {
    Complex<T> result;
    result.real = real + obj.real;
    result.img = img + obj.img;
    return result;
}


template<typename T>
Complex<T> Complex<T> :: operator - (Complex<T> const &obj) {
    Complex<T> result;
    result.real = real - obj.real;
    result.img = img - obj.img;
    return result;
}


template<typename T>
Complex<T> Complex<T> :: operator * (Complex<T> const &obj) {
    Complex<T> result;
    result.real = (real * obj.real) - (img * obj.img);
    result.img = (img * obj.real) + (real * obj.img);
    return result;
}


template<typename T>
Complex<T> Complex<T> :: operator / (Complex<T> const &obj) {
    Complex<T> temp, result;
    T abs_sqr = obj.real*obj.real + obj.img*obj.img;
    result.real = ((real * obj.real) + (img * obj.img)) / abs_sqr;
    result.img = ((img * obj.real) - (real * obj.img)) / abs_sqr;
    return result;
}



template<typename T>
T Complex<T> :: absolute() {
    T result;
    result = sqrt(real*real + img*img);
    return result;
}


template<typename T>
T Complex<T> :: get_real() {
    return real;
}


template<typename T>
T Complex<T> :: get_imaginary() {
    return img;
}


template<typename T>
ostream& operator<< (ostream& os, const Complex<T> &obj) {
    if (obj.img == 0)
    {
        return os << obj.real << " ";
    }
    if (obj.img < 0)
    {
        if (obj.real == 0)
        {
            return os << "-i" << abs(obj.img);
        }
        return os << obj.real << "-i" << abs(obj.img);
    }
    if (obj.real == 0)
    {
        return os << "i" << abs(obj.img);
    }
    
    return os << obj.real << "+i" << abs(obj.img);
}


template<typename T>
class Matrix {
    private:
        int row;
        int column;
        vector<vector<T > > matrix;
    public:
        Matrix();
        Matrix(int Row, int Column);
        Matrix(const vector<vector<T > > &mat);
        Matrix(int Row, int Column, const vector<vector<T > > &mat);
        void print_matrix();
        void set_row(int Row);
        void set_column(int Col);
        void set_matrix(const vector<vector<T > > &Matrix);
        int get_row();        
        int get_column();        
        vector<vector<T > > get_matrix();
        Matrix<T> operator + (const Matrix<T> &obj);
        Matrix<T> operator - (const Matrix<T> &obj);
        Matrix<T> operator * (const Matrix<T> &obj);
};


template<typename T>
Matrix<T> :: Matrix() {
    row = 0;
    column = 0;
}


template<typename T>
Matrix<T> :: Matrix(int Row, int Column) {
    row = Row;
    column = Column;
    vector<vector<T>> a(Row, vector<T> (Column, 0));
    matrix = a;
}


template<typename T>
Matrix<T> ::Matrix(const vector<vector<T > > &mat) {
    row = mat.size();
    column = mat[0].size();
    matrix = mat;
}

template<typename T>
Matrix<T> :: Matrix(int Row, int Column, const vector<vector<T > > &mat) {
    row = Row;
    column = Column;
    matrix = mat;
}


template<typename T>
void Matrix<T> :: print_matrix() {
    for (int i = 0; i < row; i++)
    {
        cout<<"\n";
        for (int j = 0; j < column; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
    
}


template<typename T>
int Matrix<T> :: get_row() {
    return row;
}


template<typename T>
int Matrix<T> :: get_column() {
    return column;
}


template<typename T>
vector<vector<T > > Matrix<T> :: get_matrix() {
    return matrix;
}


template<typename T>
Matrix<T> Matrix<T> :: operator + (const Matrix<T> &obj) {
    Matrix<T> a;
    if (!(obj.row==row && obj.column==column))
    {
        cout<<"\nCannot Add these matrices!!  Try with matrices having same dimentions..........";
        return a;
    }
    vector<vector<T>> b(row, vector<T>(column));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            b[i][j] = matrix[i][j] + obj.matrix[i][j];
        }
    }
    a.row = obj.row;
    a.column = obj.column;
    a.matrix = b;
    return a;
}


template<typename T>
Matrix<T> Matrix<T> :: operator - (const Matrix<T> &obj) {
    Matrix<T> a;
    if (!(obj.row==row && obj.column==column))
    {
        cout<<"\nCannot subract this matrix from given matrix!!  Try with matrices having same dimentions..........";
        return a;
    }
    vector<vector<T>> b(row, vector<T>(column));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            b[i][j] = matrix[i][j] - obj.matrix[i][j];
        }
    }
    a.row = obj.row;
    a.column = obj.column;
    a.matrix = b;
    return a;
}

template<typename T>
Matrix<T> Matrix<T> :: operator * (const Matrix<T> &obj) {
    Matrix<T> a;
    if (column != obj.row)
    {
        cout<<"\nCannot multiply these matrices!!  Try with valid matrix multiplication..........";
        return a;
    }
    vector<vector<T>> b(row, vector<T>(obj.column));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < obj.column; j++)
        {
            T sum = matrix[i][0];
            for (int k = 0; k < column; k++)
            {
                sum = sum + (matrix[i][k] * obj.matrix[k][j]);
            }
            sum = sum - matrix[i][0];
            b[i][j] = sum;
        }
    }    
    a.row = row;
    a.column = obj.column;
    a.matrix = b;
    return a;
}


#endif