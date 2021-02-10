#include<iostream>
#include<vector>
#include"num_comp.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Complex<double> a(5,5);
    Complex<double>b(4,4);
    Complex<double>c = b.inverse();
    cout<<c.as_string();
    return 0;
}
