#include<iostream>
#include"num_comp.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1,2},{2,1},{1,2}};
    Matrix<int> m(mat);
    vector<vector<int>> mat2 = {{1,0,5},{0,1,2}};
    Matrix<int> m2(mat2);
    Matrix<int> m3 = m * m2;
    m3.print_matrix();
    // Complex<double> a(5,5);
    // Complex<double>b(4,4);
    // Complex<double>c = b.inverse();
    // cout<<c.as_string();
    return 0;
}
