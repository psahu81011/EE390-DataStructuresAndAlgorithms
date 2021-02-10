#ifndef NUM_COMP
#define NUM_COMP

#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
class Complex {
    private:
        T real;
        T img;
    public:
        //constructor
        Complex(T real_part, T img_part);
        //conjugate
        Complex conjugate();
        //multiplicative inverse
        Complex inverse();
        // addition
        Complex operator + (Complex const &obj);
        //substraction
        Complex operator - (Complex const &obj);
        //multiplication
        Complex operator * (Complex const &obj);
        //division
        Complex operator / (Complex const &obj);
        //absolute value
        T absolute();
        T get_real();
        T get_imaginary();
        string polar_form();
        string as_string();
};

#endif