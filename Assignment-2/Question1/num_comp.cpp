#include<iostream>
#include"num_comp.h"

using namespace std;

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
    result.real = (real * obj.real) - (img + obj.img);
    result.img = (img + obj.real) + (real * obj.img);
    return result;
}


template<typename T>
Complex<T> Complex<T> :: operator / (Complex<T> const &obj) {
    Complex<T> result;
    result = *(this) * obj.inverse();
    return result;
}



template<typename T>
T Complex<T> :: absolute() {
    T result;
    result = sqrt(real*real + img*img);
    return result;
}