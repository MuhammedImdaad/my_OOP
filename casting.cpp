#include <iostream>
using namespace std;

int main()
{
    // double a = 5.432;
    // int b1 = a;
    // int b2 = (int)a;
    // int b3 = static_cast<int>(a);
    // cout << b1 << b2 << b3 << endl;

    int a = 65;
    char b1 = (char)a;
    char b2 = static_cast<char>(a);
    char b3 = a;
    cout << b1 << b2<< b3<<endl;
}