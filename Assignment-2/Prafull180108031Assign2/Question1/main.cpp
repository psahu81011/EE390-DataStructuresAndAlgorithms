#include<iostream>
#include"num_comp.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<Complex<int>>> mat;
    Complex<int> c(1,-1), d(1),e(1),f(1);
    vector<Complex<int>> m1,m2;
    m1.push_back(c);
    m1.push_back(d);
    m2.push_back(e);
    m2.push_back(f);
    mat.push_back(m1);
    mat.push_back(m2);
    Matrix<Complex<int>> m(mat);
    Matrix<Complex<int>> m4 = m.inverse();
    Matrix<Complex<int>> m3 = m4 * m;
    m3.print_matrix();
    // cout<<m.get_row();
    // int m3 = m.determinant();
    // m.print_matrix();
    // m3.print_matrix();
    // Complex<double> a(5.10);
    // Complex<double>b(4,4);
    // Complex<double>c = b.inverse();
    // cout<<a;
    return 0;
}
