#ifndef NUM_COMP
#define NUM_COMP

#include<iostream>
#include<math.h>
#include<string.h>
#include<cstdlib>
#include<vector>

using namespace std;



template<typename T>
class Complex {
    private:
        T real;
        T img;
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
        string as_string();
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
string Complex<T> :: as_string() {
    if (img == 0)
    {
        return to_string(real);
    }
    if (img < 0)
    {
        if (real == 0)
        {
            return "-i"+to_string(abs(img));
        }
        return to_string(real)+"-i"+to_string(abs(img));
    }
    if (real == 0)
    {
        return "i"+to_string(abs(img));
    }
    
    return to_string(real)+"+i"+to_string(abs(img));
}


template<typename T>
class Matrix {
    private:
        int row;
        int colomn;
        vector<vector<T > > matrix;
    public:
        Matrix();
        Matrix(int Row, int Colomn);
        Matrix(int Row, int Colomn, const vector<vector<T > > &mat);
        void print_matrix();
        Matrix<T> operator + (const Matrix<T> &obj);
};


template<typename T>
Matrix<T> :: Matrix() {
    row = 0;
    colomn = 0;
    matrix = {{0}};
}


template<typename T>
Matrix<T> :: Matrix(int Row, int Colomn) {
    row = Row;
    colomn = Colomn;
    vector<vector<T>> a(Row, vector<T> (Colomn, 0));
    matrix = a;
}


template<typename T>
Matrix<T> :: Matrix(int Row, int Colomn, const vector<vector<T > > &mat) {
    row = Row;
    colomn = Colomn;
    matrix = mat;
}


template<typename T>
void Matrix<T> :: print_matrix() {
    for (int i = 0; i < row; i++)
    {
        cout<<"\n";
        for (int j = 0; j < colomn; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
    
}


template<typename T>
Matrix<T> Matrix<T> :: operator + (const Matrix<T> &obj) {
    Matrix<T> a;
    if (!(obj.row==row && obj.colomn==colomn))
    {
        cout<<"\nCannot Add these matrices!!  Try with matrices having same dimentions..........";
        return a;
    }
    vector<vector<T>> b(row, vector<T>(colomn));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colomn; j++)
        {
            b = 
        }
        
    }
    
}


#endif